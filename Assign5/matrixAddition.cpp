#include "matrixAddition.hpp"

#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

void MatrixAdd::initProgram()
{
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter a size of an n by n Matrix: ";
	std::cin >> size;
	
	for(int i = 0; i < size; ++i)
	{
		std::vector<double> k;
		std::vector<double> l;
		for(int j = 0; j < size; ++j)
		{
			ranNum1 = randNumber();
			ranNum2 = randNumber();
			k.emplace_back(ranNum1);
			l.emplace_back(ranNum2);
		}
		A.emplace_back(k);
		B.emplace_back(l);
	}
	
	matrixAdd(A,B);
			
	printResults();		

}


void MatrixAdd::printResults()
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
	std::cout << "+" << std::endl;
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

double MatrixAdd::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-1000.0,1000.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<std::vector<double> > MatrixAdd::matrixAdd(std::vector<std::vector<double> > &A,std::vector<std::vector<double> > &B)
{
	std::vector<std::vector<double> > temp(size, std::vector<double>(size));
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			temp[i][j] = A[i][j] + B[i][j];
		}
	}
	C = temp;
	temp.clear();	
	return C;
}
