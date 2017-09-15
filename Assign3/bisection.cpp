#include <iostream>
#include <cmath>
#include <cfenv>

template<typename F>
double bisect(double a, double b, F f, double tol, int maxIter)
{
	
	double error = 0.0;
	double f_a = 0.0;
	double f_b = 0.0;
	double f_center = 0.0;
	double center = 0.0;

	error = 10.0 * tol;

	f_a = f(a);
	f_b = f(b);

	std::cout << "f_a: " << f_a << std::endl;
	std::cout << "f_b: " << f_b << std::endl;

	if(f_a * f_b >= 0.0)
	{
		std::cout << "Error computing! Exiting program!" << std::endl;
		return 1;
	}

	int counter = 0;

	while(error > tol && counter < maxIter)
	{

		center = 0.5 * (a+b);
		f_center = f(center);

		if(f_a * f_center < 0.0)
		{
			b = center;
			f_b = f_center;
		}
		else
		{
			a = center;
			f_a = f_center;
		}
		error = b-a;
		counter++;
	}

	return center;
	
}

int main()
{
	std::fesetround(FE_DOWNWARD);
	std::cout << bisect(0.0,7.0, [](double x){return (((3*x)*(std::sin(10*x))));}, .0000001, 1000000) << std::endl;
	//bisect(-INFINITY, INFINITY, [](double x){return ((x*std::exp(-x)));}, .001, 1000);
	std::fesetround(FE_DOWNWARD);
	std::cout << bisect(-10.0, 11.0, [](double x){return ((x*std::exp(-x)));}, .00000001, 1000000) << std::endl;

    //double z = -100 * std::exp(100);

    //double s = 110 * std::exp(-110);

	//std::cout << "z: " << z << " s: " << s << std::endl;

}
