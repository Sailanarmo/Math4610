# Computational Mathematics Software Manual

## **Routine Name:** Hybrid Secant

**Author:** Raul Ramirez

**Language:** C++

**Description:** This routine is similar to Newton's Method, however, when the Secant Method discovers a 0, it will bisect the function
again to return a new root. 

**Input:** There are no user inputs.

**Output:** The output is an approximation of the root.

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

template <typename F>
double secant(double x_0, double x_1, double a, double b, F f, double tol, int maxIter)
{
	double error = 10*tol;
	int count = 0;
	double f_0 = f(x_0);
	double f_1 = f(x_1);
	double fp_0 = (x_1-x_0)/(f_1-f_0);
	
	std::vector<double> ans = bisect(a,b,f,tol);


	while (std::abs(fp_0) < 1.11022e-16 && count < maxIter)
	{
		ans = bisect(a,b,f,tol);
		a = ans[0];
		b = ans[1];
		x_0 = x_1;
		x_1 = ans[2];
		f_0 = f(x_0);
		f_1 = f(x_1);
		fp_0 = (x_1-x_0)/(f_1-f_0);
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
			fp_0 = (x_1-x_0)/(f_1-f_0);
			newCount++;
		}
		count++;
		int newCount2 = 0;
		double e_0 = std::abs(x_1-x_0);

		while(count > 2 && error < e_0 && newCount2 < maxIter)
		{
			ans = bisect(a,b,f,tol);
			a = ans[0];
			b = ans[1];
			x_0 = x_1;
			x_1 = ans[2];
			f_0 = f(x_0);
			f_1 = f(x_1);
			fp_0 = (x_1-x_0)/(f_1-f_0);
			error = e_0;
			e_0 = std::abs(x_1-x_0);
			newCount2++;
		}
		error = e_0;
		x_0 = x_1;
		f_0 = f_1;
		x_1 = x_0 - f_0/fp_0;
		f_1 = f(x_1);
		fp_0 = (x_1-x_0)/(f_1-f_0);
	}
	return x_0;
}
```

**Example:** 
```C++
int main()
{
	std::cout << "Bisect/Secant Hybrid approx: " << secant(1.0, 1.5,-10, 9, [](double x){return x*std::exp(-x);},.0001,10) << std::endl;	
}
```

**Results:**  
```C++
"Bisect/Secant Hybrid approx: -2.32698e-12"
```

**Last Modification Date:** September 2017
