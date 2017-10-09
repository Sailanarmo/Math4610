#ifndef VECTOR_NORM_HPP
#define VECTOR_NORM_HPP

#include <vector>

class VectorNorm
{

public:
	void initProgram();
	void printResults();
	
	double randomDouble();
		
	double vectorNorm1(std::vector<double> &n);
	double vectorNorm2(std::vector<double> &n);
	double vectorNormInf(std::vector<double> &n);

private:
	std::vector<double> n;
	double vectNorm1 = 0.0;	
	double vectNorm2 = 0.0;	
	double vectNormInf = 0.0;	

};





#endif
