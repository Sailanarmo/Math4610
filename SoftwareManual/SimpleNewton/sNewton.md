# Computational Mathematics Software Manual

## **Routine Name:** Simple Newton

**Author:** Raul Ramirez

**Language:** C++

**Description:** This is a newton method without any guards to safe guard the program, this is assuming the user will not
do anything dumb on their end. 

**Input:** There are no user inputs for the program.

**Output:** The output is an approximation of the root.

**Code:**
```C++
template <typename F, typename U>
double newton (double x_0, F f, U df, double tol, int maxIter)
{
	
	double error = 10.0*tol;
	int count = 0;
	double f_0 = f(x_0);
	double fp_0 = df(x_0);

	while (error > tol && count < maxIter)
	{
		double x = x_0 - f_0/fp_0;
		error = std::abs(x-x_0);
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
	std::cout << "Newton's Approx: " << newton(0.5, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);}, .0001, 10) << std::endl;
	return 0 ;
}
```

**Results:**  
```C++
Newton's approx: -9.38962e-14
```

**Last Modification Date:** September 2017
