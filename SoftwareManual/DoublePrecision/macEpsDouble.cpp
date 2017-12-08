#include "macEpsDouble.hpp"
#include <iostream>
#include <cmath>

int MacEpsDouble::precision(int n)
{
    y = 1.0 - (x/(std::pow(2,n)));
		
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

double MacEpsDouble::errorDouble()
{
	return error;
}
