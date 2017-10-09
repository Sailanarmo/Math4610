#include "vectorNorm.hpp"
#include "matrixNorm.hpp"

#include <iostream>

void printMenu()
{	
	std::cout << std::endl;
	std::cout << "Please enter a program to init: " << std::endl;
	std::cout << std::endl;
	std::cout << "1 ------ Vector Norms" << std::endl;
	std::cout << "2 ------ Matrix Norms" << std::endl;
	std::cout << "3 ------ Vector Error" << std::endl;
	std::cout << "4 ------ Matrix Addition" << std::endl;
	std::cout << "5 ------ Matrix Subtraction" << std::endl;
	std::cout << "6 ------ Dot Product" << std::endl;
	std::cout << "7 ------ Matrix-Vector Product" << std::endl;
	std::cout << "8 ------ Matrix-Matrix Product" << std::endl;
	std::cout << "9 ------ Print this Menu Again" << std::endl;
	std::cout << std::endl;
}

int main()
{
	//============ Class Initialization =================
	VectorNorm a;
	MatrixNorm b;	
	
	//============ User Input ===========================	

	int input = 0;	
	printMenu();
	std::cin >> input;

	if(input == 1)
	{
		a.initProgram();
	}
	else if(input == 2)
	{
		b.initProgram();
	}
	else if(input == 9)
	{
		printMenu();
	}
	else
	{
		printMenu();
	}


	return 0;
}
