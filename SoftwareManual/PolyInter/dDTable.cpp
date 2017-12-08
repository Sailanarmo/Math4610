#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector <vector <double>> Matrix;
typedef vector <double> Vec;



// Problem 1: Interpolating polynomial

/*Vec InterPoly (Vec x, Vec y){

} */

Vec DividedDiffTable (Vec x, Vec y){
    int n=(int)x.size();
    Matrix difftable(n, Vec(n+1,0));
    for (int i=0; i<n; i++){
        difftable[i][0]=x[i];
        difftable[i][1]=y[i];
    }
    for (int j=2; j<n+1; j++){
        for (int k=1; k<n; k++){
            for (int i=k; i<n; i++){
                // i=2, j=3, k=2
                difftable[i][j]=(difftable[i][j-1]-difftable[i-1][j-1])/(difftable[i][0]-difftable[i-k][0]);
            }
        }
    }
    Vec coeff(n);
    for (int i=0; i<n; i++){
        coeff[i]=difftable[i][i+1];
    }
    return coeff;
}


double PolyInterp (Vec x, Vec y, double t){
    Vec coeff=DividedDiffTable(x, y);
    double eval=0.0;
    int n=(int)x.size();

    for (int i=0; i<n; i++){
        double temp=coeff[i];
        for (int j=0; j<i; j++){
            temp=temp*(t-x[j]);
        }
        eval+=temp;
    }
    return eval;
}

void Print(Vec x){
    for (int i=0; i<x.size(); i++){
        cout << x[i] << "  " ;
    }
    cout << endl;
}

Vec func(Vec x){
    Vec y(x.size());
    for (int i=0; i<x.size(); i++){
        y[i]=1/(1+25*pow(x[i],2));
    }
    return y;
}

Vec x(int n){
    Vec x(n+1);
    for (int i=0; i<n+1; i++){
        x[i]=-1.0+2.0/n*i;
    }
    return x;
}

int main(){
    Print(DividedDiffTable({1,2,4},{1,3,3}));
    Print(DividedDiffTable(x(100),func(x(100))));
    cout<<PolyInterp({1,2,4},{1,3,3},1.5)<< endl;
    cout << PolyInterp(x(5), func(x(5)), .25) <<endl;
}
