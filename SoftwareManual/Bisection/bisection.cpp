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
	std::cout << "The approximation for the function sin(x) is: " << bisect(-10.0,10.0, [](double x){return std::sin(x);}, .000000001, 1000000) << std::endl;
	std::fesetround(FE_DOWNWARD);
	std::cout << "The approximation for the function -sinx/x is: " << bisect(-10.0, 10.0, [](double x){return (-(std::sin(x)/(x)));}, .000000001, 1000000) << std::endl;
}
