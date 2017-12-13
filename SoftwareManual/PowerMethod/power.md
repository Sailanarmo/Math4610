# Computational Mathematics Software Manual

## **Routine Name:** Power Method

**Author:** Raul Ramirez

**Language:** C++

**Description:** This code attempts to create large eigenvalues in a matrix. 

**Input:**  This code takes no user inputs, but the powerMethod function accepts a Matrix A, a vector b, the tolerace, and a maxIteration.

**Output:** This will print the time and the largest eigenvalue found. 

**Code:**
```C++
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
```

**Example:**
```C++
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
```

**Results:**  
```
0.022358
597.867
```

**Last Modification Date:** November 2017
