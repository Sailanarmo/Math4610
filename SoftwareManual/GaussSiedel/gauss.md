# Computational Mathematics Software Manual

## **Routine Name:** GaussSeidel

**Author:** Nitasha Jeske

**Language:** C++

**Description:** Gauss-Seidel is an iterative method to solve a linear system of equations, Ax=b. Using the properties of linear algebra, this algorithm calculates (D+U)^-1(b-Lx) and uses the 2 norm to calculate an error, then iterates until it reaches the desired tolerance or hits a maximum number of iterations. 

**Input:**  The input is a symmetric positive definite matrix of size n x n (A), a resulting vector of size n (b), an initial guess vector of size n (x0), a tolerance, and maximum number of iterations.

**Output:** The output is printed to a file with all the solutions. 

**Example:**

**Code:**
```C++
std::vector<double> sol(std::vector<std::vector<double> > &A, std::vector<double> &b, std::vector<double> &x, int maxIter)
{
	double sum;	
	while (maxIter != 0)
	{
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
		maxIter--;
	}
	return x;
}
```

```C++
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
```

**Last Modification Date:** Nov. 12, 2017
