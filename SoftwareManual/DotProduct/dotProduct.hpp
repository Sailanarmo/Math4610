#ifndef DOT_PRODUCT_HPP
#define DOT_PRODUCT_HPP

#include <vector>

class DotProduct
{

public:

	void initProgram();
	void printResults();
	
	double dotProd(std::vector<double> &x, std::vector<double> &y);	
	double randomDouble(); 

private:
	
	std::vector<double> x;
	std::vector<double> y;

	double result = 0.0;

};

#endif
