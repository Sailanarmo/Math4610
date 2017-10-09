#ifndef MATRIX_VECTOR_HPP
#define MATRIX_VECTOR_HPP

#include <vector>

class MatrixVector
{
	
public:
	void initProgram();
	void printResults();

	double randNumber();

	std::vector<double> matrixVector(std::vector<std::vector<double>> &A,std::vector<double> &x);

private:
	int rowA = 0;	
	int colA = 0;	
		
	std::vector<std::vector<double>> A;
	std::vector<double> x;
	std::vector<double> b;
};

#endif
