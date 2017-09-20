#include <iostream>
#include <cmath>

template<typename F>
double doSin(double x, F f)
{
	double y = 	f(x);
	double g = x-y/100;
	return g;
}

template<typename F>
double doE(double x, F f)
{
	double y = f(x);
	double g = x-y;
	return g;
}

template<typename F>
double fixedPoint(double x_0, F f, double tol, int maxIter, bool isSin)
{
	int counter=1;
	double g = 0.0;

	if (isSin == true)
	{
		g = doSin(x_0, f);
	}
	else
	{
		g = doE(x_0, f);
	}

	while(counter < maxIter && std::abs(x_0-g)> tol)
	{
		x_0 = g;
		
		if (isSin == true)
		{
			g = doSin(x_0, f);
		}
		else
		{
			g = doE(x_0,f);
		}
		counter++;
	}

	if (counter >= maxIter)
	{
		std::cout << "Error, no solution to be found." << std::endl;
		return 0;
	}
	return g;
}

int main()
{
	std::cout << "The approximation of the function: 3xsin(10x) is: " << fixedPoint(1, [](double x){return(((3*x)*(std::sin(10*x))));}, .000001, 10000, true) << std::endl;
	std::cout << "The approximation of the function: xe^-x is: " << fixedPoint(1, [](double x){return((x*std::exp(-x)));}, .000001, 10000, false) << std::endl;
}
