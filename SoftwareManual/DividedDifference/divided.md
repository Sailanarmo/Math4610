# Computational Mathematics Software Manual

## **Routine Name:** Divided Difference Table

**Author:** Raul Ramirez

**Language:** C++

**Description:** The Divided Difference Table attempts to calculate the coefficients of a polynomial of a matrix.

**Input:**  No user inputs are taken, but the function takes two vectors.

**Output:**  The output is a vector of the coefficients. 

**Code:**
```C++
std::vector<double> DividedDiffTable (std::vector<double> &x, std::vector<double> &y){
    std::vector<double> temp(n+1,0);
    std::vector<std::vector<double>> difftable(n, temp);
    
    for (int i=0; i< x.size(); i++){
        difftable[i][0]=x[i];
        difftable[i][1]=y[i];
    }
    int k=1;
    for (int j=2; j<n+1; j++){
            for (int i=k; i<n; i++){
                difftable[i][j]=(difftable[i][j-1]-difftable[i-1][j-1])/(difftable[i][0]-difftable[i-k][0]);
            }
            k++;
        }
    }
    std::vector<double> coeff(n);
    for (int i=0; i<n; i++){
        coeff[i]=difftable[i][i+1];
    }
    return coeff;
}
```
**Example:**

```C++
int main(){
    Print(DividedDiffTable({1,2,4},{1,3,3}));
    Print(DividedDiffTable(x(100),func(x(100))));
}
```

**Results:**  
```
1  2  -0.666667
0.0384615  0.153846  1.05769  -1.92308  1.20192  -3.66374e-15  
```

**Last Modification Date:** November 2017
