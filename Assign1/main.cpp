#include <iostream>
#include <cmath>
#include <cfenv>

#include "macEpsFloat.hpp"
#include "macEpsDouble.hpp"
#include "e.hpp"

int main()
{
	
	MacEpsFloat a;
	MacEpsDouble b;
	E c;
	std::cout << std::endl;
	std::cout << "=================================================" << std::endl;
	std::cout << "Precision Float: " << a.precision(1) << std::endl;
	std::cout << "Float Error: " << a.errorFloat() << std::endl;
	std::cout << std::endl;
	std::cout << "Precision Double: " << b.precision(1.0) << std::endl;
	std::cout << "Double Error: " << b.errorDouble() << std::endl;
	std::cout << "=================================================" << std::endl;
		
	std::cout << "E calculated with std::exp: " << std::exp(1) << std::endl;
	std::fesetround(FE_DOWNWARD);
	std::cout << "E calculated at x_0 = 1: " << c.computeE() << std::endl;
	std::cout << "=================================================" << std::endl;
	std::cout << std::endl;
}
