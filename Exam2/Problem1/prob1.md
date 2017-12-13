# Math 4610 Exam2 Take Home

## Raul Ramirez

## Problem 1

Using the Jacobi and Gauss iterations from previous homework assignments, the following were combined in order to compute the requested output. Vector Error was also taken from one of the previous assignments in order to compute the error:

```C++
int main()
{
	std::vector<std::vector<double> > A = { {10.0, 1.0, 1.0},
											{1.0, 10.0, 1.0},
											{1.0, 1.0, 10.0} };
	std::vector<double> x = {0.0,0.0,0.0};
	std::vector<double> b = {12.0,12.0,12.0};
	
	std::vector<double> jacobi1 = jacobi(x,A,b,1);	
	std::vector<double> jacobi2 = jacobi(x,A,b,2);
	std::vector<double> gauss   =  gauss(x,A,b,1);
	
	std::cout << "Jacobi1 Results: " << printVector(jacobi1) << std::endl;	
	std::cout << "Jacobi2 Results: " << printVector(jacobi2) << std::endl;	
	std::cout << "Gauss   Results: " << printVector(gauss) << std::endl;	

	std::cout << std::endl;

	std::cout << "Jacobi1 Error: " << vecError(jacobi1, {1,1,1}) << std::endl;	
	std::cout << "Jacobi2 Error: " << vecError(jacobi2, {1,1,1}) << std::endl;	
	std::cout << "Gauss   Error: " << vecError(gauss  , {1,1,1}) << std::endl;	
}
```

**Results**
```
Jacobi1 Results: 1.2 1.2 1.2
Jacobi2 Results: 0.96 0.96 0.96
Gauss   Results: 0.972 1.08 1.2

Jacobi1 Error: 0.6
Jacobi2 Error: 0.12
Gauss   Error: 0.308
```

Since gauss has the smallest error of all three of the computations, especially after one iteration, gauss-seidel converges the fastest.
