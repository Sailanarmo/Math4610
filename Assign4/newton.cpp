#include <iostream>
#include <cmath>

template <typename F, typename U>
double newton(double x_0, F f, U df, double tol, int maxIter)
{
	double error = 10*tol;
	int count = 0;
	double f_0 = f(x_0);
	double fp_0 = df(x_0);

	while (error > tol && count < maxIter)
	{
		if (std::abs(fp_0) < 1.11022e-16)
		{
			std::cout << "The derivative is zero. Input another guess." << std::endl;
			return 0;
		}
		double x = x_0 - f_0/fp_0;
		double e_0 = std::abs(x-x_0);

		if (count > 2 && error < e_0)
		{
			std::cout << "Please choose a point with a smaller interval for convergence." << std::endl;
		}

		error = e_0;
		x_0 = x;

		f_0 = f(x_0);
		fp_0 = df(x_0);
		count++;
	}
	return x_0;
}

int main()
{
	std::cout << "Newtons approx: " << newton(1.0, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);},.0001,10) << std::endl;	
	std::cout << "Newtons approx: " << newton(0.5, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);},.0001,10) << std::endl;	
	std::cout << "Newtons approx: " << newton(3.0, [](double x){return 3*x*std::sin(10*x);}, [](double x){return 3*std::sin(10*x)+30*x*std::cos(10*x);},.0001,10) << std::endl;	
}





