# Math 4610 Exam2 Take Home

## Raul Ramirez

## Problem 3

Using the routines from Polynomial Interpolation I was able to approximate sin at the given values. I had to represent pi/6, pi/4, pi/3, and pi/2 in decimal form as best I could. But this was quite the accurate computation:

```C++
int main()
{
	std::vector<double> x1 = { 0, .5235988, .7853982, 1.0471976, 1.5707963 };
	std::vector<double> x2 = { 0, .5, .7071068, .8660254, 1 };

	double result = PolyInterp(x1,x2, 1.2);

	std::cout << "Result of Polynomial Interpolation of sin(1.2): " << result << std::endl;
	std::cout << "Error: " << std::abs(result - std::sin(1.2)  << std::endl;
}
```

**Results**
```
Results of Polynomial Interpolation of sin(1.2): 0.932141
Error: 0.000102389
```


