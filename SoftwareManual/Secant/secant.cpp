#include <iostream>
#include <cmath>

template <typename F>
double secant(double x_0, double x_1, F f, double tol, int maxIter)
{
	double error = 10*tol;
	int count = 0;
	double f_0 = f(x_0);
	double f_1 = f(x_1);
	double fp_0 = (x_1-x_0)/(f_1-f_0);

	while (error > tol && count < maxIter)
	{
		if (std::abs(fp_0) < 1.11022e-16)
		{
			std::cout << "The derivative is zero. Input another guess." << std::endl;
			return 0;
		}
		double e_0 = std::abs(x_1-x_0);

		if (count > 4 && error < e_0)
		{
			std::cout << "Please choose a point with a smaller interval for convergence." << std::endl;
		}

		error = e_0;
		x_0 = x_1;
		f_0 = f_1;
		x_1 = x_0-f_0/fp_0;
		f_1 = f(x_1);
		fp_0 = (x_1-x_0)/(f_1-f_0);	
		count++;
	}
	return x_0;
}

int main()
{
	std::cout << "Secant approx: " << secant(0.5,.45, [](double x){return x*std::exp(-x);},.0001,10) << std::endl;	
}





