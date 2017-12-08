# Computational Mathematics Software Manual

## **Routine Name:** Bisection

**Author:** Raul Ramirez

**Language:** C++

**Description:** We were given the following functions to evaluate with both the Bisection Method and the Fixed Point Iteration Method: `3xsin(10x)` and `x*e^-x`. The Bisection method divides the problem in half every time and will return a root when one is found.  

**Input:** The inputs for this program are double a, double b, Function f, double tol and int maxIter. a and b are the left and right bounds for the interval, respectively. The Function f represents which function will be used to determine roots, as long as the function is declared and defined. Double tol is a measure of accuracy of the root, and int maxIter sets a maximum number of iterations for the interval to be divided if the tolerance is not met first. 

**Output:** The program will provide a double which is the first root it finds in the function on the interval, or print an error message telling the user to input a valid function or different interval. 

**Code:**
```C++
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
```

**Example:**
```C++
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

**Results:** 
``` C++
"The approximation for the cuntions sin(x) is: 0"
"Error computing! Exiting Program!"
"The approximation for the function -sinx/x is: 1"
```

**Last Modification Date:** Sep. 14, 2017
