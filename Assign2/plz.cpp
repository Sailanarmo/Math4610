#include <iostream>
#include <cmath>
#include <cfenv>
#include <iomanip>



double integral(int n, double y_n)
{

	double a = 0.0;

	a = (((1.0/n) - y_n)/10.0); 

	return a;

}


int main()
{
	double y_30 = .002940928705;
	double y_n = y_30;
	for(int i = 30; i > 0; --i)
	{
		std::fesetround(FE_DOWNWARD);
		y_n = integral(i, y_n);

		std::cout << i-1 << " " << std::fixed << std::setprecision(20) << y_n << std::endl;
	}

}
