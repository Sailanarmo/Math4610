# Computational Mathematics Software Manual

## **Routine Name:** matrixmatrix

**Author:** Nitasha Jeske

**Language:** C++

**Description:** The matrix matrix function takes the product of two matrices by applying the dot product for each of the rows in the first matrix paired with each column in the second matrix.

**Input:**  The user will be prompted to enter row and columns of two matrices, if the sizes do not apply to the
rules of matrix Multiplication, they will be prompted to enter new values. 

**Output:** The program will simply return the time of the matrix computations since the user can choose
any size matrix it would not make sense to print it out to the screen. 

**Code:**
```C++
void MatrixProduct::initProgram()
{
	double ranNum1 = 0.0;
	double ranNum2 = 0.0;

	std::cout << "Please enter rows of Matrix A: ";
	std::cin >> rowA;
	std::cout << "Please enter columns of Matrix A: ";
	std::cin >> colA;
	std::cout << "Please enter rows of Matrix B: ";
	std::cin >> rowB;
	std::cout << "Please enter columns of Matrix B: ";
	std::cin >> colB;

	if(colA != rowB)
	{
		std::cout << "Not a computable Matrix, please enter rows and columns again!" << std::endl;
		initProgram();
	}



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
	
	for(int i = 0; i < rowB; ++i)
	{
		std::vector<double> l;
		for(int j = 0; j < colB; ++j)
		{
			ranNum2 = randNumber();
			l.emplace_back(ranNum2);
		}
		B.emplace_back(l);
	}
	matrixProd(A,B);
			
	printResults();		

}

void MatrixProduct::printTime()
{
	std::cout << "Matrix took: " << time.count() << " Seconds." << std::endl;
}

void MatrixProduct::printResults()
{
	std::cout << std::endl;
	std::cout << "The Matrix: " << std::endl;
	std::cout << std::endl;
/*
	for(auto &&a: A)
	{
		for(auto && b: a)
		{
			std::cout << std::setw(10) << b << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "*" << std::endl;
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
*/
	std::cout << std::endl;
	
	printTime();

	A.clear();
	B.clear();
	C.clear();
}

double MatrixProduct::randNumber()
{
	double ranDouble = 0.0;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> unif(-10.0,10.0);

	ranDouble = unif(generator);

	return ranDouble;
}

std::vector<std::vector<double> > MatrixProduct::matrixProd(std::vector<std::vector<double> > &A,std::vector<std::vector<double> > &B)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<std::vector<double> > temp(rowA, std::vector<double>(colB));
	#pragma omp parallel for
	for(int i = 0; i < rowA; ++i)
	{
		for(int j = 0; j < colB; ++j)
		{
			for(int k = 0; k < rowB; ++k)
			{
				temp[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	C = temp;
	temp.clear();	
	return C;
}
```

**Example:**
```C++
Please enter rows of Matrix A: 2
Please enter columns of Matrix A: 2
Please enter rows of Matrix B: 2
Please enter columns of Matrix B: 2

Matrix took: 0.00500732 Seconds. 
```

**Last Modification Date:** Oct. 3, 2017
