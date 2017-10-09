#include "matrixProduct.hpp"

#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

void MatrixProduct::initProgram()
{
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter rows of Matrix A: ";
	std::cin >> rowA;
	std::cout << "Please enter columns of Matrix A: ";
	std::cin >> colA;
	std::cout << "Please enter rows of Matrix B: ";
	std::cin >> rowB;
	std::cout << "Please enter columns of Matrix B: ";
	std::cin >> colB;

	if(colA != rowB)
	{
		std::cout << "Not a computable Matrix, please enter rows and columns again!" << std::endl;
		initProgram();
	}



	for(int i = 0; i < rowA; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < colA; ++j)
		{
			ranNum1 = randNumber();
			k.emplace_back(ranNum1);
		}
		A.emplace_back(k);
	}
	
	for(int i = 0; i < rowB; ++i)
	{
		std::vector<double> l;
		for(int j = 0; j < colB; ++j)
		{
			ranNum2 = randNumber();
			l.emplace_back(ranNum2);
		}
		B.emplace_back(l);
	}
	matrixProd(A,B);
			
	printResults();		

}


void MatrixProduct::printResults()
{
	std::cout << std::endl;
	std::cout << "The Matrix: " << std::endl;
	std::cout << std::endl;

	for(auto &&a: A)
	{
		for(auto && b: a)
		{
			std::cout << std::setw(10) << b << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "*" << std::endl;
	for(auto &&c: B)
	{
		for(auto && d: c)
		{
			std::cout << std::setw(10) << d << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "=" << std::endl;
	for(auto &&e: C)
	{
		for(auto && f: e)
		{
			std::cout << std::setw(10) << f << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	A.clear();
	B.clear();
	C.clear();
}

double MatrixProduct::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-10.0,10.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<std::vector<double> > MatrixProduct::matrixProd(std::vector<std::vector<double> > &A,std::vector<std::vector<double> > &B)
{
	std::vector<std::vector<double> > temp(rowA, std::vector<double>(colB));
	for(int i = 0; i < rowA; ++i)
	{
		for(int j = 0; j < colB; ++j)
		{
			for(int k = 0; k < rowB; ++k)
			{
				temp[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	C = temp;
	temp.clear();	
	return C;
}
