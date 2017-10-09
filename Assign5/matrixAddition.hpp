#ifndef MATRIX_ADDITION_HPP
#define MATRIX_ADDITION_HPP

#include <vector>

class MatrixAdd
{
	
public:
	void initProgram();
	void printResults();

	double randNumber();

	std::vector<std::vector<double> > matrixAdd(std::vector<std::vector<double>> &A,std::vector<std::vector<double>> &B);

private:
	int size = 0;	
	std::vector<std::vector<double>> A;
	std::vector<std::vector<double>> B;
	std::vector<std::vector<double>> C;
};

#endif
