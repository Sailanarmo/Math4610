#ifndef INVERSE_POWER
#define INVERSE_POWER

#include <vector>

std::vector<double> scalar(std::vector<double> &b, float a)
{
	for (unsigned int i = 0; i < b.size(); ++i)
	{
		b[i] = b[i]*a;
	}
	return b;
}

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

#endif
