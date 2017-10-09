#include "matrixNorm.hpp"

#include <iostream>
#include <random>
void MatrixNorm::initProgram()
{
	double ranNum = 0.0;
	int size = 0;	
	std::cout << "Please enter a size of an n by n Matrix: ";
	std::cin >> size;
	
	for(int i = 0; i < size; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < size; ++j)
		{
			ranNum = randNumber();
			k.emplace_back(ranNum);
		}
		M.emplace_back(k);
	}
	
	printResults();		

}


void MatrixNorm::printResults()
{
	for(auto &&e: M)
	{
		for(auto && f: e)
		{
			std::cout << f << " ";
		}
		std::cout << std::endl;
	}
}

double MatrixNorm::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-1000.0,1000.0);

	ranDouble = unif(generator);

	return ranDouble;
}

double MatrixNorm::matrixNorm1(std::vector<std::vector<double> > &A)
{

	return 0.0;
}

double MatrixNorm::matrixNormInf(std::vector<std::vector<double > > &B)
{

	return 0.0;
}
