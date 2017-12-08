#ifndef MATRIX_SUBTRACTION_HPP
#define MATRIX_SUBTRACTION_HPP

#include <vector>

class MatrixSub
{
	
public:
	void initProgram();
	void printResults();

	double randNumber();

	std::vector<std::vector<double> > matrixSub(std::vector<std::vector<double>> &A,std::vector<std::vector<double>> &B);

private:
	int size = 0;	
	std::vector<std::vector<double>> A;
	std::vector<std::vector<double>> B;
	std::vector<std::vector<double>> C;
};

#endif
