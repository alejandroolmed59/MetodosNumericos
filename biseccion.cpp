/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alejandro Olmedo <00097017@uca.edu.sv>
 *
 * Created on 24 de abril de 2019, 23:05
-rapidez: O((1/2)^n)
-Condicion necesaria: Debe ser f(a)*f(b)<0
-Error>=(b-a/2^n)
Tabla: n, a, b, p=a+b/2, f(p)
 */

#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

long double f(long double x){ 
    return (1.74*(log10((pow(10.0,4.0)*pow(x,(0.5))))/log10(2.0)) - 0.4 - pow((1/x),(0.5))) ; 
}

void biseccion(long double a,long double b, long double Tol){
    int n;
    long double p;
    n= (log10((b-a)/Tol))/log10(2.0);
    cout<<n<<endl ;
    for(int i=0; i<n; i++){
        
        p=(a+b)/2.0;
        cout<<setprecision(10)<<i<<"\t"<<a<<"\t"<<b<<"\t"<<p<<"\t"<<f(p)<<endl ;
        if((f(a)*f(p))>0){
            a=p;
        }else{
            b=p;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    biseccion(0.005,0.01,pow(10,-6));
    return 0;
}

