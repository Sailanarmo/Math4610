#include "mxv.hpp"
#include "matrixProduct.hpp"

#include <iostream>

void printMenu()
{	
	std::cout << std::endl;
	std::cout << "Please enter a program to init: " << std::endl;
	std::cout << std::endl;
	std::cout << "  1 ------ Matrix-Vector Product" << std::endl;
	std::cout << "  2 ------ Matrix-Matrix Product" << std::endl;
	std::cout << "  3 ------ Print this Menu Again" << std::endl;
	std::cout << "  4 ------ Kill the program" << std::endl;
	std::cout << std::endl;
}

int main()
{
	//============ Class Initialization =================
	MatrixVector a;	
	MatrixProduct b;	
	//============ User Input ===========================	

	int input = 0;	
	printMenu();
	std::cin >> input;

	while(input != 4)
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
