#include <iostream>
#include <cmath>
#include <cfenv>

namespace u
{
	double h = 0.0;
}

double absEr(double input)
{

	double result = 0.0;

	result = std::abs(((std::cos(input)) - u::h));

	return result;

}

double approx(double input, double h)
{
	
	std::cout << "Iterations: " << h << " ";

	u::h = (((std::sin(input + h)) - (std::sin(input - h)))/(2*h));

	return u::h;
}


int main()
{
	double n = 0.1;
	for(int i = 1; i < 18; ++i)
	{
		std::cout << "Approximation: " << approx(1.2,n) << " ";
		std::cout << "Absolute Error: " << absEr(1.2) << std::endl;
		n = n/10.0;
		std::cout << std::endl;

	}
	return 0;

}
