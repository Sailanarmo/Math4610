# Computational Mathematics Software Manual

## **Routine Name:** Double Precision

**Author:** Raul Ramirez

**Language:** C++

**Description:** This code will calculate the precision for a double. 

**Input:** No user input is needed.

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

**Last Modification Date:** September 2017

