# Computational Mathematics Software Manual

## **Routine Name:** Dot Product

**Author:** Raul Ramirez

**Language:** C++

**Description:** The dot product function takes a two vectors and multiplies corresponding entries in the vectors and returns the sum of these products. 

**Input:**  When this program is run, the user will be asked to enter a size of a vector of length, n. The program
will then randomly generate the numbers and return the result of the dot product. 

**Output:** The routine provides a double value which is the dot product.


**Code:**
```C++
void DotProduct::initProgram()
{
	int size = 0;
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter a size of a vector of length n: ";
	std::cin >> size;

	for(int i = 0; i < size; ++i)
	{
		ranNum1 = randomDouble();
		ranNum2 = randomDouble();
		x.push_back(ranNum1);
		y.push_back(ranNum2);
	}
	
	dotProd(x,y);	
	printResults();
}

void DotProduct::printResults()
{
	std::cout << "[ ";
	for(auto &&a : x)
	{
		std::cout << std::fixed << std::setprecision(5) << a << " ";
	}
	std::cout << "] * [ ";
	for(auto &&b : y)
	{
		std::cout << std::fixed << std::setprecision(5) << b << " ";
	}
	std::cout << "] = "; 
	std::cout << result << std::endl;

	x.clear();
	y.clear();	
}

double DotProduct::dotProd(std::vector<double> &x, std::vector<double> &y)
{
	
	result = std::inner_product(x.begin(),x.end(),y.begin(),0.0);
	return result;
}

double DotProduct::randomDouble()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-10.0,10.0);
	
	ranDouble = unif(generator);
	
	return ranDouble;	
}
```

**Example:**
```C++
"Please enter a size of a vector of length n: 3
"[ 0.13688 -3.36491 4.65768 ] * [ -6.02876 7.54759 9.49463 ] = 18.00078"
```

**Last Modification Date:** October 2017
