#Math 4610 Exam2 Take Home

## Raul Ramirez

## Problem 3

Using code from the Power Method and Inverse Power Method, I was able to replicate the results:

```C++
int main()
{
	std::vector<double> temp(32,0);
	std::vector<std::vector<double>> A(32,temp);
	std::vector<std::vector<double>> B(32,temp);
	std::vector<double> v(32,1);

	for (unsigned int i = 0; i < 32; ++i)
	{
		A[i][i] = i+1;
	}
	
	for (unsigned int i = 0; i < 32; ++i)
	{
		if (i == 30)
		{
			B[i][i] = 30;
		}
		B[i][i] = i+1;
	}

	std::cout << "Largest  Eigenvalue for A: " << powerMethod(A,v, .0001, 1000) << std::endl; 
	std::cout << "Largest  Eigenvalue for B: " << powerMethod(B,v, .0001, 1000) << std::endl; 
	std::cout << "Smallest Eigenvalue for A: " << invPowerM(A,v, .0001, 1000) << std::endl; 
	std::cout << "Smallest Eigenvalue for B: " << invPowerM(B,v, .0001, 1000) << std::endl; 
}
```

**Results**
```
Largest  EigenValue for A: 31.9986
Largest  EigenValue for B: 31.9986
Smallest EigenValue for A: 1.00003
Smallest EigenValue for B: 1.00003
```

These results confirm the calculations in the book.
