# Computational Mathematics Software Manual

## **Routine Name:** Conjugate Gradiant

**Author:** Raul Ramirez

**Language:** C++

**Description:** Conjugate Gradient is an iterative matrix to attempt to solve Ax=b. 

**Input:**  There are no user inputs, the various functions are handled inside with various parameters.

**Output:** The solution to Ax = b will print out to a file.

**Code:**
```C++
std::vector<double> conjGrad(std::vector<std::vector<double> > &A, std::vector<double> &b)
{
	double tol = 1.0e-10;

	int n = A.size();
	std::vector<double> x(n,0.0);

	std::vector<double> r = b;
	std::vector<double> p = r;
	int k = 0;

	while (k < n)
	{
		std::vector<double> rOld = r;
		std::vector<double> ap = matrixVectProd(A,p);

		double alpha = inverse(r,r)/std::max(inverse(p,ap), tol);
		x = vecComb(1.0,x,alpha,p);
		r = vecComb(1.0,r,-alpha,ap);

		if (vecNorm(r) < tol)
		{
			break;
		}
		double beta = inverse(r,r)/std::max(inverse(rOld,rOld), tol);
		p = vecComb(1.0,r,beta,p);
		k++;
	}

	return x;
}
```

**Example:**
```C++
int main()
{
	std::ofstream myFile;
	std::vector<std::vector<double> > A = makeMatrix();
	std::vector<double> b = makeVectorB();
	
	A = makeSymmetric(A);	
	std::vector<double> x = conjGrad(A,b);	
	
	myFile.open("conjGrad-sol.txt");
	for(auto &&e:x)
	{
		myFile << e << std::endl;
	}
	myFile.close();

	return 0;
}
```

**Last Modification Date:** Nov. 12, 2017
