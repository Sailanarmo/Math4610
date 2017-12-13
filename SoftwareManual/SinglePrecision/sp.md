# Computational Mathematics Software Manual

## **Routine Name:** Single Precision

**Author:** Raul Ramirez

**Language:** C++

**Description:** This code will return the precision of a floating point value. 

**Input:** There is no input for this program. 

**Output:** The program produces a float, which represents the machine epsilon for a floating point number system. 

**Code:**
``` C++
int MacEpsFloat::precision(int n)
{
    y = 1 - (x/(1 << n));
	
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

float MacEpsFloat::errorFloat()
{
	return error;
}
```

**Example:**
``` C++
int main(){
    MacEpsFloat a;
    
    std::cout << "Precision Float: " << a.precision(1) << std::endl;
}
```

**Results:** 
``` C++
"Precision Float: 24
"Float Error: 5.96046e-08"
```

**Last Modification Date:** September 2017

