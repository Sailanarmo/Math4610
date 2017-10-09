#include "vectorNorm.hpp"
#include "matrixNorm.hpp"
#include "vectorError.hpp"
#include "matrixAddition.hpp"
#include "matrixSubtraction.hpp"
#include "dotProduct.hpp"
#include "mxv.hpp"
#include "matrixProduct.hpp"

#include <iostream>

void printMenu()
{	
	std::cout << std::endl;
	std::cout << "Please enter a program to init: " << std::endl;
	std::cout << std::endl;
	std::cout << "  1 ------ Vector Norms" << std::endl;
	std::cout << "  2 ------ Matrix Norms" << std::endl;
	std::cout << "  3 ------ Vector Error" << std::endl;
	std::cout << "  4 ------ Matrix Addition" << std::endl;
	std::cout << "  5 ------ Matrix Subtraction" << std::endl;
	std::cout << "  6 ------ Dot Product" << std::endl;
	std::cout << "  7 ------ Matrix-Vector Product" << std::endl;
	std::cout << "  8 ------ Matrix-Matrix Product" << std::endl;
	std::cout << "  9 ------ Print this Menu Again" << std::endl;
	std::cout << "  10------ Kill the program" << std::endl;
	std::cout << std::endl;
}

int main()
{
	//============ Class Initialization =================
	VectorNorm a;
	MatrixNorm b;
	VectorError c;	
	MatrixAdd d;
	MatrixSub e;
	DotProduct f;
	MatrixVector g;	
	MatrixProduct h;	
	//============ User Input ===========================	

	int input = 0;	
	printMenu();
	std::cin >> input;

	while(input != 10)
	{
		if(input == 1)
		{
			a.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 2)
		{
			b.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 3)
		{
			c.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 4)
		{
			d.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 5)
		{
			e.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 6)
		{
			f.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 7)
		{
			g.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 8)
		{
			h.initProgram();
			printMenu();
			std::cin >> input;
		}
		else if(input == 9)
		{
			printMenu();
			std::cin >> input;
		}
		else
		{
			std::cout << "Sorry, that wasn't an option, try again: ";
			printMenu();
			std::cin >> input;
		}
	}

	return 0;
}
