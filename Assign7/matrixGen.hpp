#ifndef MATRIX_GENERATOR_HPP
#define MATRIX_GENERATOR_HPP

#include <vector>
#include <random>
#include <algorithm>
#include <numeric>


#define SIZE 1000

double randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(0.0,1.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<std::vector<double> > makeMatrix()
{
	double random = 0.0;
	std::vector<std::vector<double> > A;
	
	for (int i = 0; i < SIZE; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < SIZE; ++j)
		{
			random = randNumber();
			k.emplace_back(random);
		}
		A.emplace_back(k);	
	}
	return A;
}

std::vector<double> makeVectorB()
{
	double random = 0.0;
	std::vector<double> b;
	for (int i = 0; i < SIZE; ++i)
	{
		random = randNumber();
		b.emplace_back(random);	
	}
	return b;
}

std::vector<double> makeGuessVector()
{
	std::vector<double> x;
	for(int i = 0; i < SIZE; ++i)
	{
		x.push_back(1);
	}
	return x;
}


std::vector<std::vector<double> > makeDiagonallyDominate(std::vector<std::vector<double> > &A)
{
	for (int i = 0, j = 0; i < SIZE && j < SIZE; ++i,++j)
	{
			A[i][j] += SIZE;
	}
	return A;
}


std::vector<std::vector<double> > makeSymmetric(std::vector<std::vector<double> > &A)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			A[j][i] = A[i][j];
		}
	}
	return A;
}

std::vector<double> vecComb(double a, std::vector<double> &u, double b, std::vector<double> &v)
{
	int n = u.size();
	std::vector<double> w(n);
	for (int i = 0; i < n; ++i)
	{
		w[i] = a * u[i] + b * v[i];
	}

	return w;
}

double inverse(std::vector<double> &u, std::vector<double> &v)
{
	return std::inner_product(u.begin(),u.end(),v.begin(), 0.0);
}

std::vector<double> matrixVectProd(std::vector<std::vector<double> > &A, std::vector<double> &v)
{
	int n = A.size();
	std::vector<double> c(n);
	for (int i = 0; i < n; ++i)
	{
		c[i] = inverse(A[i],v);
	}

	return c;
}
double vecNorm(std::vector<double> &v)
{
	return std::sqrt(inverse(v,v));	
}

#endif
