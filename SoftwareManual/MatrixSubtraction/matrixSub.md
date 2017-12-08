# Computational Mathematics Software Manual

## **Routine Name:** Matrix Subtraction

**Author:** Raul Ramirez

**Language:** C++

**Description:** The matrix difference function takes two matrices and subtracts the corresponding i,j entries to make a new matrice. 

**Input:**  The user will be prompted to enter the size of an n by n matrix to subtract. 

**Output:** The routine provides a vector of vector of doubles which has the subtracted values as the entries.

**Code:**
```C++
void MatrixSub::initProgram()
{
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter a size of an n by n Matrix: ";
	std::cin >> size;
	
	for(int i = 0; i < size; ++i)
	{
		std::vector<double> k;
		std::vector<double> l;
		for(int j = 0; j < size; ++j)
		{
			ranNum1 = randNumber();
			ranNum2 = randNumber();
			k.emplace_back(ranNum1);
			l.emplace_back(ranNum2);
		}
		A.emplace_back(k);
		B.emplace_back(l);
	}
	
	matrixSub(A,B);
			
	printResults();		

}


void MatrixSub::printResults()
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
	std::cout << "-" << std::endl;
	for(auto &&c: B)
	{
		for(auto && d: c)
		{
			std::cout << std::setw(10) << d << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "=" << std::endl;
	for(auto &&e: C)
	{
		for(auto && f: e)
		{
			std::cout << std::setw(10) << f << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	A.clear();
	B.clear();
	C.clear();
}

double MatrixSub::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-1000.0,1000.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<std::vector<double> > MatrixSub::matrixSub(std::vector<std::vector<double> > &A,std::vector<std::vector<double> > &B)
{
	std::vector<std::vector<double> > temp(size, std::vector<double>(size));
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			temp[i][j] = A[i][j] - B[i][j];
		}
	}
	C = temp;
	temp.clear();	
	return C;
}
```

**Example:**
```C++
Please enter a size of an n by n Matrix: 2

The Matrix: 

  -247.178   -910.672 
   794.187    327.847 
-
  -219.183    845.048 
   -69.671   -667.462 
=
  -27.9947   -1755.72 
   863.859    995.309 
```

**Last Modification Date:** Oct. 3, 2017
