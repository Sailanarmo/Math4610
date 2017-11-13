# Math 4610 Fundamentals of Computational Mathematics Software Manual Entry

**Routine Name:**           Jacobi, Gauss-Seidel, Conjugate

**Author:** Raul Ramirez

**Language:** C++, can be compiled with any C++ interpreter, this was built with a make file.

For example,

    make jacobi

This will produce an executable called jacobi, you can then run this by typing `./jacobi` in the terminal.

**Description/Purpose:** This routine implemented 3 different methods to find a solution for the equation Ax=b. Jacobi being the slowest out of them all for 1000 random doubles between 0 and 1. Gauss-Seidel being the quickest of them, and Conjugate Gradient working on symmetric matrices. 

**Input:** There are no user inputs, the only inputs being the in code input, for example the Size of the matrix and the function inputs.

**Output:** These routines output a vector x to a text file. Since the solution is too big to print to a screen, a text file was used to represent the solutions of x.

**Implementation/Code:** 


**Last Modified:** November 2017
