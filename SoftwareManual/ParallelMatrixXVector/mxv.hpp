#ifndef MATRIX_VECTOR_HPP
#define MATRIX_VECTOR_HPP

#include <vector>
#include <chrono>

class MatrixVector
{
	
public:
	void initProgram();
	void printTime();
	void printResults();

	double randNumber();

	std::vector<double> matrixVector(std::vector<std::vector<double>> &A,std::vector<double> &x);

private:
	int rowA = 0;	
	int colA = 0;	
	
		
	std::chrono::duration<double> time;
			
	std::vector<std::vector<double>> A;
	std::vector<double> x;
	std::vector<double> b;
};

#endif
