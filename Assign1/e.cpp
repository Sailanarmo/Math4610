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

	double value = 1.0;
	double term = 1.0;
	for (int i = 1; i <= 50; ++i)
	{
		term *= 1.0/i;
		value += term;
	}

	return value;
} 
