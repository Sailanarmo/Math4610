# Math 4610 Fundamentals of Computational Mathematics Assignment 3

**Routine Name:**           Approximation and Error

**Author:** Raul Ramirez

**Language:** C++, this code can be compiled with g++ compiler or gcc.

For example,

    g++ -std=c++11 bisection.cpp
	g++ -std=c++11 fixedPointIteration.cpp

will produce an executable **./a.out**, however, a better way to compile is to use `Make`, for example:

    make bisect
	make fixed

These will give you executables named **./bisection** and **./fixed**

**Description/Purpose:** We were given the following functions to evaluate with both the Bisection Method and the Fixed Point Iteration Method: `3xsin(10x)` and `x*e^-x`. The Bisection method divides the problem in half every time and will return a root when one is found. 

The Fixed Point Iteration Method will use iteration to go through the functions and return a root when one is found. It is very unreliable as it will return a terrible root most of the time. 

**Input:** There are no user inputs that are needed from the user. All the inputs are handled within their own functions.

**Output:** The output will be a double, depending on the program you run as stated in the description.

**Implementation/Code:** The following is the code for bisection.cpp

```cpp

#include <iostream>
#include <cmath>
#include <cfenv>
#include <cstdlib>

//This is templatized, because we want the user to be able to pass in any arbitrary
//Function called f. F f will be captured in a lambda further down in the code.
template<typename F>
double bisect(double a, double b, F f, double tol, int maxIter)
{
	//Initializing Variables to 0	
	double f_a = 0.0;
	double f_b = 0.0;
	double f_center = 0.0;
	double center = 0.0;

	//This is where the lambda is the most powerful in the code. It will pass a
	//into the function f, and return a value as a double.
	f_a = f(a);
	f_b = f(b);

	//An error message
	if(f_a * f_b > 0.0)
	{
		std::cout << "Error computing! Exiting program!" << std::endl;
		return EXIT_FAILURE;
	}
	
	//The loop where the bisection will be handled
	for(int i = 1; i < maxIter; ++i)
	{
		//add a and b, and divide their result and set that equal to the center.
		center = (a+b) * 0.5;
		f_center = f(center);
		
		//if the center of the function is equal to zero, or b-a divided in half is less
		//than our tolerance. We have found the root and return it.
		if((f(center) == 0) || ((b-a) * 0.5 < tol))
		{
			return center;
		}
		//if the function evaluated at the center is greater than 0 and greater than 
		//the function evaluated at a. Or if the function evaluated at the center is 
		//less than 0 and less than the function evaluated at a. f_a is now the fun-
		//ction to evaluate at, and a is now the center. Else f_b is now the functi-
		//on to evaluate at, and b is now the center. 
		if((f(center)>0 && f(a)>0) || (f(center)<0 && f(a)<0))
		{
			f_a = f_center;
			a = center;
		}
		else
		{
			f_b = f_center;
			b = center;
		}
	
	}

	return center;
	
}

int main()
{
	//Floors the results
	std::fesetround(FE_DOWNWARD);
	//This is where the lambda is used. [] captures everthing, (double x) casts the variable
	//we are capturing into a double. And return, returns the resuls of the function we want
	//to evaluate.
	std::cout << "The approximation for the function 3xsin(10x) is: " << bisect(1.0,7.0, [](double x){return (((3*x)*(std::sin(10*x))));}, .00000001, 1000000) << std::endl;
	std::fesetround(FE_DOWNWARD);
	std::cout << "The approximation for the function xe^-x is: " << bisect(-100.0, 100.0, [](double x){return ((x*std::exp(-x)));}, .00000001, 1000000) << std::endl;
}

```
This program outputs 
```
The approximation for the function 3xsin(10x) is: 3.14159
The approximation for the function xe^-x is: 0
```

The Follow is code for fixedPointIteration.cpp

```cpp

#include <iostream>
#include <cmath>

//For the same reasons and bisection.cpp, we want any function f that we 
//can evaluate f at, however, x-y was too large of a result and would 
//break the code, so we divide the result in order to work with a better
//problem set
template<typename F>
double doSin(double x, F f)
{
	double y = 	f(x);
	double g = x-y/100;
	return g;
}

template<typename F>
double doE(double x, F f)
{
	double y = f(x);
	double g = x-y;
	return g;
}

//This function takes a double x_0, a function f, tolerace, maximum iterations
//and a boolean to determine which work we need to be doing.
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

int main()
{
	std::cout << "The approximation of the function: 3xsin(10x) is: " << fixedPoint(1, [](double x){return(((3*x)*(std::sin(10*x))));}, .000001, 10000, true) << std::endl;
	std::cout << "The approximation of the function: xe^-x is: " << fixedPoint(1, [](double x){return((x*std::exp(-x)));}, .000001, 10000, false) << std::endl;
}
```
This program outputs:
```
The approximation for the function 3xsin(10x) is: 1.25664
The approximation for the function xe^-x is: 8.90987e-19
```


**Last Modified:** September/2017
