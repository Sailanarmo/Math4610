#include <iostream>
#include <vector>
#include <fstream>

#include "matrixGen.hpp"


std::vector<double> conjGrad(std::vector<std::vector<double> > &A, std::vector<double> &b)
{
	double tol = 1.0e-10;

	int n = A.size();
	std::vector<double> x(n,0.0);

	std::vector<double> r = b;
	std::vector<double> p = r;
	int k = 0;

	while (k < n)
	{
		std::vector<double> rOld = r;
		std::vector<double> ap = matrixVectProd(A,p);

		double alpha = inverse(r,r)/std::max(inverse(p,ap), tol);
		x = vecComb(1.0,x,alpha,p);
		r = vecComb(1.0,r,-alpha,ap);

		if (vecNorm(r) < tol)
		{
			break;
		}
		double beta = inverse(r,r)/std::max(inverse(rOld,rOld), tol);
		p = vecComb(1.0,r,beta,p);
		k++;
	}

	return x;
}


int main()
{
	std::ofstream myFile;
	std::vector<std::vector<double> > A = makeMatrix();
	std::vector<double> b = makeVectorB();
	
	A = makeSymmetric(A);
	
	for(auto &&f: A)
	{
		for(auto &&e : f)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
				
	std::vector<double> x = conjGrad(A,b);	
	
	myFile.open("conjGrad-sol.txt");
	for(auto &&e:x)
	{
		myFile << e << std::endl;
	}
	myFile.close();

	return 0;
}
