#ifndef MATRIX_NORM_HPP
#define MATRIX_NORM_HPP

#include <vector>

class MatrixNorm
{
	
public:
	void initProgram();
	void printResults();

	double randNumber();

	double matrixNorm1(std::vector<std::vector<double>> &A);
	double matrixNormInf(std::vector<std::vector<double>> &B);
private:
	int size = 0;	
	std::vector<std::vector<double>> M;
	double mNorm1 = 0.0;
	double mNormInf = 0.0;

};

#endif
