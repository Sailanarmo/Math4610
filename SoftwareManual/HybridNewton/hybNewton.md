# Computational Mathematics Software Manual

## **Routine Name:** Hnewton

**Author:** Raul Ramirez

**Language:** C++

**Description:** This routine is a hybrid of Bisection and Newton's method. When Newton's encounters a zero derivative or a sequence that is not converging, instead of printing out an error, it calls a revised form of the bisection method to bisect the given interval 4 times and uses the last midpoint as the new guess. 

**Input:** x0 is the initial guess at the root, a and b are the endpoints of the interval, f and df indicate the desired fucntion and derivative, tol is the allowed tolerance and maxIter is the max number of iterations to be run.

**Output:** The output is an approximation to the root of type double.

**Code:**
```C++
template <typename F>
std::vector<double> bisect (double a, double b, F f,double tol)
{
	double f_a = f(a);
	double f_b = f(b);
	double c = 0.0;
	
	if (f_a*f_b >= 0.0)
	{
		std::cout << "By the intermediate value theorem, you may not receive a root in this interval." << std::endl;
		std::vector<double> error;
		error.push_back(0.0);
		return error;
	}
	
	for(int i = 0; i < (std::log((b-a)/tol)/std::log(2)+1) && i < 4; ++i)
	{
		c = .5 * (a+b);
		double f_c = f(c);

		if(f_c == 0)
		{
			continue;
		}
		else if(f_a*f_c < 0)
		{
			b = c;
			f_b = f_c;
		}
		else
		{
			a = c;
			f_a - f_c;
		}
	}
	std::vector<double> vec;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	return vec;
}

template <typename F, typename U>
double newton(double x_0, double a, double b, F f, U df, double tol, int maxIter)
{
	double error = 10*tol;
	int count = 0;
	double f_0 = f(x_0);
	double fp_0 = df(x_0);
	
	std::vector<double> ans = bisect(a,b,f,tol);


	while (std::abs(fp_0) < 1.11022e-16 && count < maxIter)
	{
		ans = bisect(a,b,f,tol);
		a = ans[0];
		b = ans[1];
		x_0 = ans[2];
		f_0 = f(x_0);
		fp_0 = df(x_0);
		count++;
	}
	count = 0;
	while (error > tol && count < maxIter)
	{
		int newCount = 0;
		while(std::abs(fp_0) < 1.11022e-16 && newCount < maxIter)
		{
			ans = bisect(a,b,f,tol);
			a = ans[0];
			b = ans[1];
			x_0 = ans[2];
			f_0 = f(x_0);
			fp_0 = df(x_0);
			newCount++;
		}
		count++;
		int newCount2 = 0;
		double x = x_0-f_0/fp_0;
		double e_0 = std::abs(x-x_0);

		while(count > 2 && error < e_0 && newCount2 < maxIter)
		{
			ans = bisect(a,b,f,tol);
			a = ans[0];
			b = ans[1];
			x_0 = ans[2];
			error = e_0;
			e_0 = std::abs(x-x_0);
			newCount2++;
		}
		error = e_0;
		x_0 = x;
		f_0 = f(x_0);
		fp_0 = df(x_0);
	}
	return x_0;
}
```
**Example:** 
```C++
int main()
{
	std::cout << "Bisect/Newton Hybrid approx: " << newton(1.0, -10, 9, [](double x){return x*std::exp(-x);}, [](double x){return std::exp(-x)-x*std::exp(-x);},.0001,10) << std::endl;	
}
```

**Results:**  
```C++
Bisect/Newton Hybrid approx: -2.74063e-15

```

**Last Modification Date:** Sep. 30, 2017