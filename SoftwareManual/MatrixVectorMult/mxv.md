# Computational Mathematics Software Manual

## **Routine Name:** Matrix Vector Multiplication

**Author:** Raul Ramirez

**Language:** C++

**Description:** This program will multiple a vector by a matrix following the rules of vector and matrix multiplication. 

**Input:**  The user will be prompted to enter the size of a vector and the size of an n by n matrix.

**Output:** The output will be the results of the multiplication

**Code:**
```C++
void MatrixVector::initProgram()
{
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter rows of Matrix A: ";
	std::cin >> rowA;
	std::cout << "Please enter columns of Matrix A: ";
	std::cin >> colA;
	
	for(int i = 0; i < rowA; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < colA; ++j)
		{
			ranNum1 = randNumber();
			k.emplace_back(ranNum1);
		}
		A.emplace_back(k);
	}
	
	for(int i = 0; i < rowA; ++i)
	{
		ranNum2 = randNumber();
		x.emplace_back(ranNum2);
	}
	
	matrixVector(A,x);
			
	printResults();		

}


void MatrixVector::printResults()
{
	std::cout << std::endl;
	std::cout << "The Matrix: " << std::endl;
	std::cout << std::endl;

	for(auto &&a: A)
	{
		for(auto && b: a)
		{
			std::cout << std::setw(10) << b << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "*" << std::endl;
	for(auto &&c: x)
	{
		std::cout << std::setw(10) << c << " ";
	}
	std::cout << std::endl;
	std::cout << "=" << std::endl;
	for(auto &&e: b)
	{
		std::cout << std::setw(10) << e << " ";
	}
	std::cout << std::endl;

	A.clear();
	x.clear();
	b.clear();
}

double MatrixVector::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-10.0,10.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<double> MatrixVector::matrixVector(std::vector<std::vector<double> > &A, std::vector<double> &x)
{
	std::vector<double> temp(rowA);

	for(int i = 0; i < rowA; ++i)
	{
		for(int j = 0; j < rowA; ++j)
		{
			temp[i] += (A[i][j] * x[j]);
		}
	}
	
	b = temp;	
	temp.clear();
	return b;
}
```

**Example:**
```C++
Please enter columns of Matrix A: 3

The Matrix: 

   3.79113    5.71699   -9.07248 
  -9.64288    1.45042    6.38121 
   6.42371     9.3613   0.756915 
*
   3.07787    -6.9261   -3.65926 
=
   5.27071   -63.0757   -47.8357 
```

**Last Modification Date:** Oct. 3, 2017
