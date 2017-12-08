# Computational Mathematics Software Manual

## **Routine Name:** Vector Norms

**Author:** Raul Ramirez

**Language:** C++

**Description:** The Vector Norm sums the absolute values of each entry in the vector.

**Input:**  The user will be prompted to enter the size of a vector n.

**Output:** The routine provides the Vector 1, 2, and inf Norm of type double.

**Code:**
```C++
void VectorNorm::initProgram()
{
	int size = 0;
	double ranNum = 0.0;

	std::cout << "Please enter a size of a vector of length n: ";
	std::cin >> size;

	for(int i = 0; i < size; ++i)
	{
		ranNum = randomDouble();
		n.push_back(ranNum);
	}


	printResults();
}

void VectorNorm::printResults()
{
	std::fesetround(FE_DOWNWARD);
	std::cout << "Vector Norm 1: " << std::fixed << std::setprecision(5) << vectorNorm1(n) << std::endl;
	std::cout << "Vector Norm 2: " << std::fixed << std::setprecision(5) << vectorNorm2(n) << std::endl;
	std::cout << "Vector Norm Inf: " << std::fixed << std::setprecision(5) << vectorNormInf(n) << std::endl;
	
	n.clear();
}

double VectorNorm::randomDouble()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-1000.0,1000.0);
	
	ranDouble = unif(generator);
	
	return ranDouble;	
}

double VectorNorm::vectorNorm1(std::vector<double>& n)
{
	for(auto &&e : n)
	{
		vectNorm1 += std::abs(e);	
	}

	return vectNorm1;
}


double VectorNorm::vectorNorm2(std::vector<double> &n)
{
	for(auto &&e : n)
	{
		vectNorm2 += std::pow(e,2);
	}
	
	vectNorm2 = std::abs(vectNorm2);
	
	return std::sqrt(vectNorm2);
}

double VectorNorm::vectorNormInf(std::vector<double> &n)
{
	std::vector<double> a;

	for(auto &&e : n)
	{
		a.push_back(std::abs(e));
	}

	vectNormInf = *std::max_element(a.begin(),a.end());

	return vectNormInf; 
}
```

**Example:**
```C++
Please enter a size of a vector of length n: 3
Vector Norm 1: 1617.67558
Vector Norm 2: 1052.04841
Vector Norm Inf: 890.37826
```

**Last Modification Date:** Oct. 3, 2017
