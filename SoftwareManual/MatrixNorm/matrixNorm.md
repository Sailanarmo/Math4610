# Computational Mathematics Software Manual

## **Routine Name:** Matrix Norm

**Author:** Raul Ramirez

**Language:** C++

**Description:** This program will take the norm of a Matrix. 

**Input:**  The user will be prompted to enter the size of an n by n matrix.

**Output:** The output will be the Norm 1 of a matrix and Norm Inf of that same matrix.

**Code:**
```C++
void MatrixNorm::initProgram()
{
	double ranNum = 0.0;
	std::cout << "Please enter a size of an n by n Matrix: ";
	std::cin >> size;
	
	for(int i = 0; i < size; ++i)
	{
		std::vector<double> k;
		for(int j = 0; j < size; ++j)
		{
			ranNum = randNumber();
			k.emplace_back(ranNum);
		}
		M.emplace_back(k);
	}
	
	printResults();		

}


void MatrixNorm::printResults()
{
	std::cout << std::endl;
	std::cout << "The Matrix: " << std::endl;
	std::cout << std::endl;

	for(auto &&e: M)
	{
		for(auto && f: e)
		{
			std::cout << std::setw(10) << f << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Matrix Norm 1: " << matrixNorm1(M) << std::endl;
	std::cout << "Matrix Norm Inf: " << matrixNormInf(M) << std::endl;
	std::cout << std::endl;

	M.clear();
}

double MatrixNorm::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-1000.0,1000.0);

	ranDouble = unif(generator);

	return ranDouble;
}

double MatrixNorm::matrixNorm1(std::vector<std::vector<double> > &A)
{
	std::vector<double> max;
	for(int i = 0; i < size; ++i)
	{
		double blah =0;
		for(int j = 0; j < size; ++j)
		{
			blah += std::abs(A[i][j]);
		}
		max.emplace_back(blah);
	}
	mNorm1 = *std::max_element(max.begin(),max.end());
	max.clear();	
	return mNorm1;
}

double MatrixNorm::matrixNormInf(std::vector<std::vector<double > > &B)
{
	std::vector<double> max;
	for(int i = 0; i < size; ++i)
	{
		double blah =0;
		for(int j = 0; j < size; ++j)
		{
			blah += std::abs(B[j][i]);
		}
		max.emplace_back(blah);
	}
	mNormInf = *std::max_element(max.begin(),max.end());
	max.clear();	
	return mNormInf;
}
```

**Example:**
```C++
Please enter a size of an n by n Matrix: 2

The Matrix: 

  -619.537    84.8551 
   40.6964    546.736 

Matrix Norm 1: 704.392
Matrix Norm Inf: 660.233
```

**Last Modification Date:** Oct. 3, 2017
