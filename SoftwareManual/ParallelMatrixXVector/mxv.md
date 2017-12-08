# Computational Mathematics Software Manual

## **Routine Name:** Parallel Matrix x Vector

**Author:** Raul Ramirez

**Language:** C++

**Description:** The matrix vector function multiplies a matrix by a vector by running through a nested for loop and in simple terms calculates the dot product for each row in the matrix. This routine is coded to run in Open MP on multiple processors in order to speed up the computing time. 

**Input:**  The user will be prompted to ente the size of a vector and a matrix. 

**Output:** The routine provides a vector of type double with the dimensions: rows of matrix x 1, and prints out the time it takes to compute the vector.

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
	printTime();		
	//printResults();		

}

void MatrixVector::printTime()
{
	std::cout << "Matrix took: " << time.count() << " Seconds." << std::endl;
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
	
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<double> temp(rowA);
	#pragma omp parallel for
	for(int i = 0; i < rowA; ++i)
	{
		for(int j = 0; j < rowA; ++j)
		{
			temp[i] += (A[i][j] * x[j]);
		}
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	b = temp;	
	temp.clear();
	return b;
}
```

**Example:**
```C++
Please enter rows of Matrix A: 1000
Please enter columns of Matrix A: 1000
Matrix took: 0.000459182 Seconds.  
```

**Last Modification Date:** Oct. 18, 2017
