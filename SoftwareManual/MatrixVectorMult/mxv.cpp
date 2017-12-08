#include "mxv.hpp"

#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

void MatrixVector::initProgram()
{
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter rows of Matrix A: ";
	std::cin >> rowA;
	std::cout << "Please enter columns of Matrix A: ";
	std::cin >> colA;
	
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
	
	for(int i = 0; i < rowA; ++i)
	{
		ranNum2 = randNumber();
		x.emplace_back(ranNum2);
	}
	
	matrixVector(A,x);
			
	printResults();		

}


void MatrixVector::printResults()
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
	for(auto &&c: x)
	{
		std::cout << std::setw(10) << c << " ";
	}
	std::cout << std::endl;
	std::cout << "=" << std::endl;
	for(auto &&e: b)
	{
		std::cout << std::setw(10) << e << " ";
	}
	std::cout << std::endl;

	A.clear();
	x.clear();
	b.clear();
}

double MatrixVector::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-10.0,10.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<double> MatrixVector::matrixVector(std::vector<std::vector<double> > &A, std::vector<double> &x)
{
	std::vector<double> temp(rowA);

	for(int i = 0; i < rowA; ++i)
	{
		for(int j = 0; j < rowA; ++j)
		{
			temp[i] += (A[i][j] * x[j]);
		}
	}
	
	b = temp;	
	temp.clear();
	return b;
}
