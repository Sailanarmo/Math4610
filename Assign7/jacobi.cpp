#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "matrixGen.hpp"

std::vector<double> sol(std::vector<double> &x,std::vector<std::vector<double> > &A, std::vector<double> &b, int n)
{
	
	double sum;	
	int k = 0;
	while(n != 0)
	{
		for (unsigned int i = 0; i < b.size(); ++i)
		{
			sum = 0.0;
			for (unsigned int j = 0; j < b.size(); ++j)
			{
				if(j != i)
				{
					sum += A[i][j]*std::pow(x[j],k);
				}
			}
			x[i] = std::pow(x[i],k+1); 
			x[i] = (1.0/A[i][i])*(b[i]-sum);
		}
		k++;
		n--;
	}

	return x;
}


int main()
{
	
	std::ofstream myFile;	
	std::vector<std::vector<double> > A = makeMatrix();
	std::vector<double> x = makeGuessVector();
	std::vector<double> b = makeVectorB();
	
	A = makeDiagonallyDominate(A);

	std::vector<double> xSol = sol(x,A,b,3000);
	
	myFile.open("jacobi-sol.txt");
	for(auto &&e:xSol)
	{
		myFile  << e << std::endl;
	}
	myFile.close();
		
	return 0;
}
