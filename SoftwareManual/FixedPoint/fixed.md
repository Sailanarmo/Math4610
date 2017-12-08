# Computational Mathematics Software Manual

## **Routine Name:** Fixed Point

**Author:** Raul Ramirez

**Language:** C++

**Description:** The Fixed Point Iteration Method will use iteration to go through the functions and return a root when one is found. It is very unreliable as it will return a terrible root most of the time.  

**Input:** The inputs for this program are double a, double b, Function f, double tol and int maxIter. a and b are the left and right bounds for the interval, respectively. The Function f represents which function will be used to determine roots, as long as the function is declared and defined. Double tol is a measure of accuracy of the root, and int maxIter sets a maximum number of iterations for the interval to be divided if the tolerance is not met first. 

**Output:** The program will provide a double which is the first root it finds in the function on the interval, or print an error message telling the user to input a valid function or different interval. 

**Code:**
```C++
template<typename F>
double fixedPoint(double x_0, F f, double tol, int maxIter, bool isSin)
{
	//initializing variables
	int counter=1;
	double g = 0.0;
	
	//If the function is the sin function, do work here
	if (isSin == true)
	{
		g = doSin(x_0, f);
	}
	//else do work here
	else
	{
		g = doE(x_0, f);
	}
	
	//while the counter is less than the maximum iterations and the
	//absolute value of x_0 - g is greater than the tolerance, do
	//work until we find the solution.
	while(counter < maxIter && std::abs(x_0-g)> tol)
	{
		x_0 = g;
		
		if (isSin == true)
		{
			g = doSin(x_0, f);
		}
		else
		{
			g = doE(x_0,f);
		}
		counter++;
	}
	
	//an error message
	if (counter >= maxIter)
	{
		std::cout << "Error, no solution to be found." << std::endl;
		return 0;
	}
	return g;
}
```

**Example:**
```C++
int main()
{
	std::cout << "The approximation of the function: 3xsin(10x) is: " << fixedPoint(1, [](double x){return(((3*x)*(std::sin(10*x))));}, .000001, 10000, true) << std::endl;
	std::cout << "The approximation of the function: xe^-x is: " << fixedPoint(1, [](double x){return((x*std::exp(-x)));}, .000001, 10000, false) << std::endl;
}
```

**Results:** 
``` C++
"The approximation for the function 3xsin(10x) is: 1.25664"
"The approximation for the function xe^-x is: 8.90987e-19"
```

**Last Modification Date:** Sep. 14, 2017
