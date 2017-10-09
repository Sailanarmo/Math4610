#ifndef VECTOR_ERROR_HPP
#define VECTOR_ERROR_HPP

#include "vectorNorm.hpp"

#include <vector>

class VectorError
{

public:
	void initProgram();
	void printResults();
	
	double randomDouble();
		
	double vectorError1(std::vector<double> &x, std::vector<double> &y);
	double vectorError2(std::vector<double> &x, std::vector<double> &y);
	double vectorErrorInf(std::vector<double> &x, std::vector<double> &y);

private:
	
	std::vector<double> x;
	std::vector<double> y;
	std::vector<double> n;

	double vectError1 = 0.0;	
	double vectError2 = 0.0;	
	double vectErrorInf = 0.0;	

};


#endif
