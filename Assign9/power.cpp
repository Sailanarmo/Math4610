#include <iostream>
#include <chrono>

#include "power.hpp"
#include "matrixGen.hpp"

double powerMethod(std::vector<std::vector<double>> &A, std::vector<double> &b, double tol, int maxIter)
{
	
	std::chrono::duration<double> time;
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<double> y = matrixVec(A, b);

	int c = 0;

	double error = 10*tol;
	double lambdaOld = 0.0;

	int n = b.size();
	std::vector<double> x(n,0);

	double lambdaNew = 0.0;

	while(tol < error && c < maxIter)
	{
		double p = std::sqrt(dotProduct(y,y));
		for (int i = 0; i < n; ++i)
		{
			x[i] = y[i]/p;
		}

		y = matrixVec(A,x);
		lambdaNew = dotProduct(x,y);
		error = std::abs(lambdaNew-lambdaOld);
		lambdaOld = lambdaNew;
		c++;
	}
	std::vector<double> eigenValue = x;
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	std::cout << "Time: " << time.count() << std::endl;
	return lambdaNew;

}

int main()
{
	std::vector<std::vector<double>> A = makeMatrix();
	std::vector<double> v = makeVectorB();	

	A = makeSymmetric(A);

	std::cout << powerMethod(A, v, .0001, 100) << std::endl;
}


