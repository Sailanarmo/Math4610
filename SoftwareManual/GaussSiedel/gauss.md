# Computational Mathematics Software Manual

## **Routine Name:** Gauss Seidel

**Author:** Raul Ramirez

**Language:** C++

**Description:** Gauss-Siedel iteration is an iteration matrix meant to attempt to solve Ax = b, it is far more efficient than the Jacobi iteration.. 
    
**Input:**  There are no user inputs for this program, as the program will handle the various arguments passed in the function parameters.

**Output:** The solution to Ax = b is printed out to a text file. 

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

**Last Modification Date:** November 2017
