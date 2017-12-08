#include "vectorError.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cfenv>
#include <random>

void VectorError::initProgram()
{
	int size = 0;
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter a size of a vector of length n: ";
	std::cin >> size;

	for(int i = 0; i < size; ++i)
	{
		ranNum1 = randomDouble();
		ranNum2 = randomDouble();
		x.push_back(ranNum1);
		y.push_back(ranNum2);
	}

	printResults();
}

void VectorError::printResults()
{
	std::fesetround(FE_DOWNWARD);
	std::cout << "Vector Error 1: " << std::fixed << std::setprecision(5) << vectorError1(x,y) << std::endl;
	std::cout << "Vector Error 2: " << std::fixed << std::setprecision(5) << vectorError2(x,y) << std::endl;
	std::cout << "Vector Error Inf: " << std::fixed << std::setprecision(5) << vectorErrorInf(x,y) << std::endl;

	x.clear();
	y.clear();
	n.clear();
}

double VectorError::randomDouble()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-1000.0,1000.0);
	
	ranDouble = unif(generator);
	
	return ranDouble;	
}

double VectorError::vectorError1(std::vector<double>& x, std::vector<double> &y)
{
	VectorNorm a;
	std::set_difference(x.begin(),x.end(),y.begin(),y.end(),std::inserter(n,n.begin()));

	vectError1 = a.vectorNorm1(n);	
	return vectError1;
}


double VectorError::vectorError2(std::vector<double> &x, std::vector<double> &y)
{
	VectorNorm a;
	std::set_difference(x.begin(),x.end(),y.begin(),y.end(),std::inserter(n,n.begin()));

	vectError2 = a.vectorNorm2(n);	
	return vectError2;
}

double VectorError::vectorErrorInf(std::vector<double> &x, std::vector<double> &y)
{
	VectorNorm a;
	std::set_difference(x.begin(),x.end(),y.begin(),y.end(),std::inserter(n,n.begin()));
	
	vectErrorInf = a.vectorNormInf(n);
	
	return vectErrorInf;
}
