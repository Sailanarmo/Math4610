# Computational Mathematics Software Manual

## **Routine Name:** Polynomial Interpolation

**Author:** Raul Ramirez

**Language:** C++

**Description:** This is the polynomial interpolation routine.  

**Input:**  No user inputs, but this does take 2 vectors and a double t in the PolyInterp function. 

**Output:**  The output is a double which represents the solution of the polynomial interpolation routine. 

**Code:**
```C++
double PolyInterp (std::vector<double> x, std::vector<double> y, double t){
    std::vector<double> coeff = DividedDiffTable(x, y);
    double eval=0.0;
    
    for (int i=0; i< x.size(); i++){
        double temp=coeff[i];
        for (int j=0; j<i; j++){
            temp=temp*(t-x[j]);
        }
        eval+=temp;
    }
    return eval;
}
```

**Example:**
```C++
int main()
{
    std::cout << PolyInterp({1,2,4},{1,3,3},1.5) << std::endl;
    std::cout << PolyInterp(x(5), func(x(5)), .25) << std::endl;
    std::cout << PolyInterp(x(10), func(x(10)), .25) << std::endl;
}
```

**Results:**  
```
2.16667
0.367434
0.281977
```

**Last Modification Date:** Nov. 30, 2017
