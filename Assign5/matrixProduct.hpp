#ifndef MATRIX_PRODUCT_HPP
#define MATRIX_PRODUCT_HPP

#include <vector>

class MatrixProduct
{
	
public:
	void initProgram();
	void printResults();

	double randNumber();

	std::vector<std::vector<double> > matrixProd(std::vector<std::vector<double>> &A,std::vector<std::vector<double>> &B);

private:
	int rowA = 0;	
	int rowB = 0;	
	int colA = 0;
	int colB = 0;
		
	std::vector<std::vector<double>> A;
	std::vector<std::vector<double>> B;
	std::vector<std::vector<double>> C;
};

#endif
