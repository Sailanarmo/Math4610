#include <iostream>
#include "macEpsFloat.hpp"
#include "macEpsDouble.hpp"

int main()
{

	MacEpsFloat a;
	MacEpsDouble b;

	std::cout << "Precision Float: " << a.precision(1) << std::endl;
	std::cout << "Float Error: " << a.errorFloat() << std::endl;
	std::cout << std::endl;
	std::cout << "Precision Double: " << b.precision(1.0) << std::endl;
	std::cout << "Double Error: " << b.errorDouble() << std::endl;

}
