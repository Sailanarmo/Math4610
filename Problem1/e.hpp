#ifndef E_HPP
#define E_HPP
#include <cmath>

class E
{

	public:
		int factorial(int n);
		double computeE();

	private:
		double init = 1.0;
		//double e = 2.718;
		double e = std::exp(1);
		int x_0 = 0;
		//int x_0 = 1;
		double sum = 0.0;
		int x = 1;
	    int N = 10;	

};


#endif
