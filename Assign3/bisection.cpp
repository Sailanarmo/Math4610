#include <iostream>
#include <cmath>
#include <cfenv>
#include <cstdlib>

template<typename F>
double bisect(double a, double b, F f, double tol, int maxIter)
{
	
	double f_a = 0.0;
	double f_b = 0.0;
	double f_center = 0.0;
	double center = 0.0;

	f_a = f(a);
	f_b = f(b);

	std::cout << "f_a: " << f_a << std::endl;
	std::cout << "f_b: " << f_b << std::endl;

	if(f_a * f_b > 0.0)
	{
		std::cout << "Error computing! Exiting program!" << std::endl;
		return EXIT_FAILURE;
	}

	for(int i = 1; i < maxIter; ++i)
	{
		center = (a+b) * 0.5;
		f_center = f(center);

		if((f(center) == 0) || ((b-a) * 0.5 < tol))
		{
			return center;
		}

		if((f(center)>0 && f(a)>0) || (f(center)<0 && f(a)<0))
		{
			f_a = f_center;
			a = center;
		}
		else
		{
			f_b = f_center;
			b = center;
		}
	
	}

	return center;
	
}

int main()
{
	std::fesetround(FE_DOWNWARD);
	std::cout << bisect(1.0,7.0, [](double x){return (((3*x)*(std::sin(10*x))));}, .00000001, 1000000) << std::endl;
	std::fesetround(FE_DOWNWARD);
	std::cout << bisect(-100.0, 100.0, [](double x){return ((x*std::exp(-x)));}, .00000001, 1000000) << std::endl;
}
