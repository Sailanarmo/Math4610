# Computational Mathematics Software Manual

## **Routine Name:** SMacEps

**Author:** Nitasha Jeske

**Language:** C++

**Description:** This single machine epsilon routine will calculate the floating point precision of the computer being used. The program adds a value to one. This value is initially one, but is divided by two each iteration, until the sum is accepted as one. The value on the final iteration provides the machine epsilon of the computer. 

**Input:** Since this routine is specific in the values it uses to calculate the accuracy, there is no input.

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
"Precision Float: 5.96046e-08"
```

**Last Modification Date:** Sep. 1, 2017

