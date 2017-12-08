# Computational Mathematics Software Manual

## **Routine Name:** Newton

**Author:** Raul Ramirez

**Language:** C++

**Description:** This version of Newton's method contains checks to make sure the initial guess is valid with the given function. It will approximate the root by evaluating the function and derivative at the inital guess, and take that value to be the new guess. While doing that, the routine checks to make sure the derivative is non-zero and the sequence is converging within the interval. 

**Input:** x0 is the initial guess at the root, f and df indicate the desired fucntion and derivative, tol is the allowed tolerance and maxIter is the max number of iterations to be run. 

**Output:** The output is an approximation to the root of type double, or an error message telling you to pick a different initial guess. 

**Code:**
```C++
template <typename F, typename U>
double newton(double x_0, F f, U df, double tol, int maxIter)
{
	double error = 10*tol;
	int count = 0;
	double f_0 = f(x_0);
	double fp_0 = df(x_0);

	while (error > tol && count < maxIter)
	{
		if (std::abs(fp_0) < 1.11022e-16)
		{
			std::cout << "The derivative is zero. Input another guess." << std::endl;
			return 0;
		}
		double x = x_0 - f_0/fp_0;
		double e_0 = std::abs(x-x_0);

		if (count > 2 && error < e_0)
		{
			std::cout << "Please choose a point with a smaller interval for convergence." << std::endl;
		}

		error = e_0;
		x_0 = x;

		f_0 = f(x_0);
		fp_0 = df(x_0);
		count++;
	}
	return x_0;
}
```

**Example:**
```C++
int main()
{
	std::cout << "Newtons approx: " << newton(1.0, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);},.0001,10) << std::endl;	
	std::cout << "Newtons approx: " << newton(0.5, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);},.0001,10) << std::endl;	
	std::cout << "Newtons approx: " << newton(3.0, [](double x){return 3*x*std::sin(10*x);}, [](double x){return 3*std::sin(10*x)+30*x*std::cos(10*x);},.0001,10) << std::endl;	
}
```

**Results:**  
```C++
Newton's approx: Derivative is zero. Pleas input different guess.
0
Newton's approx: -9.38962e-14
Newton's approx: 3.76991

```

**Last Modification Date:** Sep. 30, 2017
