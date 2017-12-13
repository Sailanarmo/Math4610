# Computational Mathematics Software Manual

## **Routine Name:** Parallel Jacobi

**Author:** Raul Ramirez

**Language:** C++

**Description:** This is a parallelized version of the Jacobi iteration, since Jacobi is easily parallelizable,
this code runs really effeciently. 


**Input:**  Again, there are no user inputs, but the functions do take a Matrix, a vector b, a guess vector x, and how many iterations the user wants to have.

**Output:** This outputs the time and how many iterations it took.

**Code:**
```C++
std::vector<double> sol(std::vector<double> &x,std::vector<std::vector<double> > &A, std::vector<double> &b, int tol, int n)
{
	
	double sum;	
	double error = 10*tol;
	int k = 0;
	std::vector<double> x_1(A.size(),0);
	std::chrono::duration<double> time;
	auto start = std::chrono::high_resolution_clock::now();
	while(error > tol && k < n)
	{
		#pragma omp parallel for
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			sum = 0.0;
			for (unsigned int j = 0; j < i; ++j)
			{
					sum += A[i][j]*x[j];
			}
			x_1[i] = (b[i]-sum)/A[i][i];

			for (int j = i+1; j < n; j++)
			{
				sum+=A[i][j]*x[j];
			}
			x_1[i] = (b[i]-sum)/A[i][i];
		}
		sum = 0.0;

		#pragma omp parallel for
		for(unsigned int i = 0; i < A.size(); ++i)
		{
			double diff = std::abs(x_1[i]-x[i]);
			sum = sum+diff*diff;
		}
		error = std::sqrt(sum);
		x = x_1;
		k++;
	}
	auto start = std::chrono::high_resolution_clock::now();
	time = end - start;
	std::cout << "Time: " << time.count() << std::endl;
	std::cout << "k: " << k << std::endl;
	return x;
}
```

**Example:**

```C++
int main()
{
	
	std::ofstream myFile;	
	std::vector<std::vector<double> > A = makeMatrix();
	std::vector<double> x = makeGuessVector();
	std::vector<double> b = makeVectorB();
	
	A = makeDiagonallyDominate(A);

	std::vector<double> xSol = sol(x,A,b,.001,1000);
	
	myFile.open("jacobi-sol.txt");
	for(auto &&e:xSol)
	{
		myFile  << e;
	}
	myFile << std::endl;
	myFile.close();
		
	return 0;
}
```

**Results:**  
```
Time: 0.004531
k = 16
```

**Last Modification Date:**
November 2017
