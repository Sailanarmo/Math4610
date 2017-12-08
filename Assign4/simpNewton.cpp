#include <iostream>
#include <cmath>

template <typename F, typename U>
double newton (double x_0, F f, U df, double tol, int maxIter)
{
	
	double error = 10.0*tol;
	int count = 0;
	double f_0 = f(x_0);
	double fp_0 = df(x_0);

	while (error > tol && count < maxIter)
	{
		double x = x_0 - f_0/fp_0;
		error = std::abs(x-x_0);
		x_0 = x;
		f_0 = f(x_0);
		fp_0 = df(x_0);
		count++;
	}
	
	return x_0;
}

int main()
{
	std::cout << "Newton's Approx: " << newton(0.5, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);}, .0001, 10) << std::endl;
	return 0 ;
}
