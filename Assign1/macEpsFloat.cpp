#include "macEpsFloat.hpp"
#include <iostream>
#include <cmath>

int MacEpsFloat::precision(int n)
{
    y = 1 - (x/(1 << n));
	
	if (y == 1.0)
	{
	    prec = n-1;	
	}
	else
	{
		error = std::abs(e - y);
		++n;
		precision(n);
	}
	return prec;
}

float MacEpsFloat::errorFloat()
{
	return error;
}
