#include "e.hpp"
#include <iostream>

int E::factorial(int n)
{
	int fact = 1;
	if (n == 0) return 1;
	for (int i = 1; i <= n; ++i)
	{
		fact = fact * i;
	}

	return fact;	
}

double E::computeE()
{

	//sum = std::pow(e,x_0);	
	sum = 0;
	for (int i = 1; i < N; ++i)
	{
		sum += (((std::pow(x-x_0,i))/(factorial(i))));
	}

	return std::pow(std::exp(1),x_0) * sum;
	//return sum;
} 
