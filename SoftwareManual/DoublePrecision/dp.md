# Computational Mathematics Software Manual

## **Routine Name:** Double Precision

**Author:** Raul Ramirez

**Language:** C++

**Description:** This Double machine epsilon routine will calculate the floating point precision of the computer being used. The program adds a value to one. This value is initially one, but is divided by two each iteration, until the sum is accepted as one. The value on the final iteration provides the machine epsilon of the computer. 

**Input:** Since this routine is specific in the values it uses to calculate the accuracy, there is no input.

**Output:** The program produces a Double, which represents the machine epsilon for a floating point number system. 

**Code:**
``` C++
int MacEpsDouble::precision(int n)
{
    y = 1.0 - (x/(std::pow(2,n)));
		
	if (y == 1.0)
	{
	    prec = n-1;	
	}
	else
	{
		error = std::abs(e - y);
		++n;
		precision(n);
	}
	return prec;
}

double MacEpsDouble::errorDouble()
{
	return error;
}
```

**Example:**
``` C++
int main(){
    MacEpsDouble b;
    
    std::cout << "Precision Double: " << b.precision(1.0) << std::endl;
	  std::cout << "Double Error: " << b.errorDouble() << std::endl;
}
```

**Results:** 
``` C++
"Precision Double: 53"
"Double Error: 1.11022e-16"
```

**Last Modification Date:** Sep. 1, 2017

