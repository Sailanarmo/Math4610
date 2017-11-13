#include <iostream>
#include <vector>
#include <random>
#include <fstream>

double randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(0.0,1.0);
	
	ranDouble = unif(generator);
	
	return ranDouble;	
}

std::vector<double> sol(std::vector<double> &x,std::vector<std::vector<double> > &A, std::vector<double> &b, int n)
{
	
	double sum;	
	int counter = n;
	while(counter != 0)
	{
		for (unsigned int i = 0; i < b.size(); ++i)
		{
			sum = 0.0;
			for (unsigned int j = 0; j < b.size(); ++j)
			{
				if(j != i)
				{
					sum += A[i][j]*x[j];
				}
			}
			x[i] = (1.0/A[i][i])*(b[i]-sum);
		}
		counter--;
	}

	return x;
}


int main()
{
	
	const int SIZE = 1000;

	double ranNumber = 0.0;
	std::vector<std::vector<double> > A;
	std::vector<double> x;
	std::vector<double> b;
	std::ofstream myFile;	
				
	for (int i = 0; i < SIZE; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < SIZE; ++j)
		{
			ranNumber = randNumber();
			k.emplace_back(ranNumber);
		}
		A.emplace_back(k);
	}

	for (int i = 0; i < SIZE; ++i)
	{
		ranNumber = randNumber();
		b.emplace_back(ranNumber);
		x.push_back(1);
	}

	for (int i = 0, j = 0; i < SIZE,j < SIZE; ++i,++j)
	{
		A[i][j] += 1000;
	}

	std::vector<double> xSol = sol(x,A,b,3000);
	
	myFile.open("results.txt");
	for(auto &&e:xSol)
	{
		myFile  << e << std::endl;
	}
	myFile.close();
		
	return 0;
}
