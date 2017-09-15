# Math 4610 Fundamentals of Computational Mathematics Assignment 2

**Routine Name:**           Approximation and Error

**Author:** Raul Ramirez

**Language:** C++, this code can be compiled with g++ compiler or gcc.

For example,

    g++ -std=c++11 approx.cpp

will produce an executable **./a.out**, however, a better way to compile is to use `Make`, for example:

    make aprox
	make prob5

These will give you executables named **./approx** and **./prob5**

**Description/Purpose:** Aprox will compute the function `f'(x_0) = (f(x_0 + h) - f(x_0 - h))/2*h`. It will return a 
double of the iterations we are dividing by, the approximation of the function at the iteration, and the absolute
error of the iteration. Although, I am not sure if the absolute error is computed correctly for this problem.

Prob5 will return a double that evaluates the function `y_{n-1} = (((1\n) - y_n)/10)`. This took away the issue of 
having to multiply the entire function by 10 the entire time, making our computations incorrect and unreliable.

**Input:** There are no user inputs that are needed from the user. All the inputs are handled within their own functions.

**Output:** The output will be a double, depending on the program you run as stated in the description.

**Implementation/Code:** The following is the code for aprox.cpp

```cpp

    #include <iostream>
    #include <cmath>
	#include <cfenv>

	//this namespace was created in order to avoid use of a global variable.
	namespace u
	{
		double h = 0.0;
	}
	//This function would take in the input and return the absolute error of the funtion
	double absEr(double input)
	{

		double result = 0.0;

		result = std::abs(((std::cos(input)) - u::h));

		return result;

	}

	//This function takes in two arguments and returns the approximation of the function
	double approx(double input, double h)
	{
	
		std::cout << "Iterations: " << h << " ";

		u::h = (((std::sin(input + h)) - (std::sin(input - h)))/(2*h));

		return u::h;
	}


	int main()
	{
		//this variable is our starting iteration
		double n = 0.1;
		//I chose 18 to be an arbitrary number. It can be smaller or larger
		for(int i = 1; i < 18; ++i)
		{
			//This will print out the approximation
			std::cout << "Approximation: " << approx(1.2,n) << " ";
			//This will print out the absolute error
			std::cout << "Absolute Error: " << absEr(1.2) << std::endl;
			//Each time we go through the loop, divide the iteration by 10.
			n = n/10.0;
			std::cout << std::endl;

		}
		return 0;

	}

```

The Follow is code for prob5.cpp

```cpp
#include <iostream>
#include <cmath>
#include <cfenv>
#include <iomanip>


//Integral is probably a bad name for this function, but it takes
//an integer n, and a double y_n and returns the error.
double integral(int n, double y_n)
{

	double a = 0.0;

	a = (((1.0/n) - y_n)/10.0); 

	return a;

}


int main()
{
	//this double was computed using Maple to gives our y_30
	double y_30 = .002940928705;
	double y_n = y_30;
	for(int i = 30; i > 0; --i)
	{
		std::fesetround(FE_DOWNWARD);
		//this called the function integral, and set it equal to the double y_n
		y_n = integral(i, y_n);
		//this prints out the error of the function.
		std::cout << i-1 << " " << std::fixed << std::setprecision(9) << y_n << std::endl;
	}

}


```


**Last Modified:** September/2017
