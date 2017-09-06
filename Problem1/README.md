# Smaceps

## Description of Program:
This program will allow the user to calculate the Machine Epsilon for Floating point numbers and Doubles. To compile this program in a Linux enviornment, simply type `Make` into your terminal. Make will compile all of the code and give you the executable called **release**, simply type `./release` to run the program. 

The program has two classes named MacEpsFloat and MacEpsDouble. 

## Functions and their Descriptions:

```cpp
int precision(int n); //Takes an integer n, and returns the precision.
float errorX(); //Returns the error, X representing float or double;
```

## Variables and their Descriptions:

```cpp
float e = 1.0; //This is the error to subtract from y
float x = 1.0; //A constant to be divided by 2^n
float y = 0.0; //The Machine Epsilon
float error = 0.0; //The error to be returned
float prec = 0.0; //represents the Precision.
```

## The Output
The output of the program should look like this:
```
Precision Float: 24
Float Error: 5.96046e-08

Precision Double: 53
Double Error: 1.11022e-16
```

## The Code
```cpp
int MacEpsX::precision(int n)
{
	y = 1 - (x/(1<<n)); //(1<<n) is changed to std::pow(2,n) for doubles.

	if(y == 1.0)
	{
		prec = n-1;
	}
	else
	{
		error = std::abs(e-y);
		++n;
		precision(n);
	}
	return prec;
}
```
MacEpsX, X representing float or double. Takes `n` as our starting condition. It then takes it into the Machine Epsilon, represented as `y`. 

![equation](https://latex.codecogs.com/gif.latex?macEps&space;=&space;macEps&space;-&space;\frac{x}{2^n}) 

This is the formula given to compute the Machine Epsilon. If `y` does not equal to `1.0`, then it will calculate the `error` by taking the absolute value of `e - y`. It then will increment `n` by 1 and recursively return to the top of the program.

### Last Modified: 9-6-2017
### Author: Raul Ramirez
