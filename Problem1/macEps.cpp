#include "macEps.hpp"
#include <iostream>
#include <cmath>

int MacEps::precision(int n)
{
	std::cout << n << std::endl;

    y = 1 - (x/(1 << n));
	float error = std::abs(e - y);
	
	std::cout << "error: " << error << std::endl;		
	if (y == 1.0)
	{
	    return n;	
	}
	else
	{
		++n;
		precision(n);
	}
}

