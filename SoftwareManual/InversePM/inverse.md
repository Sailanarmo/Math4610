# Computational Mathematics Software Manual

## **Routine Name:** Inverse Power Method

**Author:** Raul Ramirez

**Language:** C++

**Description:** The inverse power method attemps to return the largest eigenvalue to the user of a SPD Matrix.

**Input:**  No user input is taken. 

**Output:** The largest value of the eigenvalues.

**Code:**
```C++
double invPowerM (std::vector<std::vector<double>> &A, std::vector<double> v_0, double tol, int maxIter)
{
	std::vector<double> y = conjGrad(A, v_0, v_0, tol, maxIter);

	int c = 0;
	double error = 10*tol;
	double lambdaOld = 0.0;

	int n = y.size();

	std::vector<double> x(n,0);

	double lambdaMax = 0.0;

	while (tol < error && c < maxIter)
	{
		double p = std::sqrt(dotProd(y,y));

		for (int i = 0; i < n; ++i)
		{
			x[i] = y[i]/p;
		}

		y = conjGrad(A,x,x,tol,maxIter);

		lambdaMax = dotProd(x,y);

		error = std::abs(lambdaMax-lambdaOld);
		lambdaOld = lambdaMax;
		c++;
	}
	
	std::vector<double> eigenVector = x;

	return 1.0/lambdaMax;
}
```

**Example:**

```C++
int main()
{
	std::srand(time(NULL));

	std::vector<std::vector<double>> A(1000,std::vector<double>(1000));

	for (int i = 0; i < 1000; ++i)
	{
		A[i][i] = rand()%100/100.0+500;
		for(int j = 0; j < i; ++j)
		{
			A[i][j] = rand()%100/100.0;
			A[j][i]= A[i][j];
		}
	}

	std::vector<double> v(1000);
	
	for (int i = 0; i < 1000; ++i)
	{
		v[i] = rand()%100/100.0;
	}
	
	std::cout << invPowerM(A, v, .0001,100) << std::endl;	
}
```


**Results:**  
```
601.743
```

**Last Modification Date:** Nov. 29, 2017
