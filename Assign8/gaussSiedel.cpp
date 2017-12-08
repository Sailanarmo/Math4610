#include <iostream>
#include <vector>
#include <fstream>
#include <omp.h>
#include <chrono>

#include "matrixGen.hpp"

std::vector<double> sol(std::vector<std::vector<double> > &A, std::vector<double> &b, std::vector<double> &x, int maxIter)
{
	std::chrono::duration<double> time;
	auto start = std::chrono::high_resolution_clock::now();
	double sum;
	int count = 0;
	while (maxIter != 0)
	{
		#pragma omp parallel for
		for(unsigned int i = 0; i < b.size(); ++i)
		{
			sum = 0.0;
			for (unsigned int j = 0; j < b.size(); ++j)
			{
				if (j != i)
				{
					sum += A[i][j]*x[j];
				}
			}
			x[i] = (1.0/A[i][i])*(b[i] - sum);
		}
		count++;
		maxIter--;
	}
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	std::cout << "Time: " << time.count() << std::endl;
	std::cout << "Count: " << count << std::endl;
	return x;
}

int main()
{

	std::vector<std::vector<double> > A = makeMatrix();
	std::vector<double> b = makeVectorB();
	std::vector<double> x = makeGuessVector();
	std::ofstream myFile;

	A = makeDiagonallyDominate(A);

	std::vector<double> xSol = sol(A,b,x,3000);

	myFile.open("gauss-siedel.txt");
	for(auto &&e:xSol)
	{
		myFile << e << std::endl;
	}
	myFile.close();
		
	return 0;

}
