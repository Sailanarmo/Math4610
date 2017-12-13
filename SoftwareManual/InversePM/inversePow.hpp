#ifndef INVERSE_POWER
#define INVERSE_POWER

#include <vector>
#include <iostream>
#include "matrixGen.hpp"

std::vector<double> add(std::vector<double> &a, std::vector<double> &b)
{
	for (unsigned int i = 0; i < a.size();++i)
	{
		a[i] = a[i] + b[i];
	}
	return a;
}

std::vector<double> sub(std::vector<double> &a, std::vector<double> &b)
{
	for (unsigned int i = 0; i < a.size();++i)
	{
		a[i] = a[i] - b[i];
	}
	return a;
}

std::vector<double> conjGrad(std::vector<std::vector<double>> &A, std::vector<double> &b, std::vector<double> &v, float tol, int maxIter)
{

	std::vector<double> temp = matrixVec(A,v);
	std::vector<double> r0 = sub(b, temp);
	
	double delta0 = dotProd(r0,r0);
	
	float b_delta = dotProd(b,b);
	
	int k = 0;
	
	std::vector<double> p0 = r0;
	
	double condition = tol*tol*b_delta;
	
	while (delta0 > condition && k < maxIter)
	{
		std::vector<double> s_k = matrixVec(A,p0);

		float alpha_k = delta0/dotProd(p0,s_k);
		std::vector<double> temp1 = scalarVec(p0,alpha_k);	
		std::vector<double> x1 = add(v, temp1);
		std::vector<double> temp2 = scalarVec(s_k,alpha_k);
		r0 = sub(r0,temp2);
		double delta1 = dotProd(r0,r0);
		float scalar = delta1/delta0;
		std::vector<double> temp3 = scalarVec(p0,scalar);
		p0 = add(r0,temp3);

		k++;

		v=x1;

		delta0 = delta1;
//		std::cout << "k: " << k << " maxIter: " << maxIter << std::endl;
//		std::cout << "delta0: " << delta0 << " condition: " << condition << std::endl;
	}

	return v;
}

#endif
