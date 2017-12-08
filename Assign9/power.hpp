#ifndef POWER_METHOD
#define POWER_METHOD

#include <vector>


std::vector<double> matrixVec(std::vector<std::vector<double>> &A, std::vector<double> &x)
{
	int rowA = A[0].size();
	std::vector<double> product(rowA);
	for (int i = 0; i < rowA; ++i)
	{
		for(int j = 0; j < rowA; ++j)
		{
			product[i] += (A[i][j] * x[j]);
		}
	}
	return product;
}

double dotProduct(std::vector<double> a, std::vector<double> b)
{
	double sum = 0.0;
	for(unsigned int i = 0; i < a.size(); ++i)
	{
		sum = sum + a[i]*b[i];
	}
	return sum;
}





#endif
