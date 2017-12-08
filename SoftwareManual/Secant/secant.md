# Computational Mathematics Software Manual

## **Routine Name:** Secant

**Author:** Raul Ramirez

**Language:** C++

**Description:** Secant's method approximates the root of the function by taking an initial guess and subtracting off the function value divided by an approximation to the derivative. This difference becomes the new value. While doing that, the routine checks to make sure the derivative is non-zero and the sequence is converging within the interval. 

**Input:** x0 and x1 are the initial guesses at the root, f indicates the desired fucntion, tol is the allowed tolerance and maxIter is the max number of iterations to be run. 

**Output:** The output is an approximation to the root of type double, or an error message telling you to pick a different initial guess. 

**Code:**
```C++
template <typename F>
double secant(double x_0, double x_1, F f, double tol, int maxIter)
{
	double error = 10*tol;
	int count = 0;
	double f_0 = f(x_0);
	double f_1 = f(x_1);
	double fp_0 = (x_1-x_0)/(f_1-f_0);

	while (error > tol && count < maxIter)
	{
		if (std::abs(fp_0) < 1.11022e-16)
		{
			std::cout << "The derivative is zero. Input another guess." << std::endl;
			return 0;
		}
		double e_0 = std::abs(x_1-x_0);

		if (count > 4 && error < e_0)
		{
			std::cout << "Please choose a point with a smaller interval for convergence." << std::endl;
		}

		error = e_0;
		x_0 = x_1;
		f_0 = f_1;
		x_1 = x_0-f_0/fp_0;
		f_1 = f(x_1);
		fp_0 = (x_1-x_0)/(f_1-f_0);	
		count++;
	}
	return x_0;
}
```

**Example:**
```C++
int main()
{
	std::cout << "Secant approx: " << secant(0.5,.45, [](double x){return x*std::exp(-x);},.0001,10) << std::endl;	
}
```

**Results:**  
```C++
Secant approx: 2.69781e-12
```

**Last Modification Date:** Sep. 30, 2017
