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
 */
#include <math.h>
#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

long double f(long double x){
    
    return 0.5 + 0.5*exp((-x)/(2.0*M_PI))*sin(x) -0.75  ; 
}
void secant(long double p0,long double p1,long double TOL,int Nmax){
	long double p;
	for(int i=0; i < Nmax; i++){
		p = p1 - f(p1)*(p1 - p0 )/( f(p1) - f(p0));		
		cout << i << setprecision(20) << "\t" << p0 << "\t" << p1 << "\t" << p << "\t"<< abs(p1 - p)<< endl;		
		if(abs(p - p1) < TOL)	break;

		p0 = p1;
		p1 = p;		
	}
} 

void biseccionAux(long double a,long double b, long double Tol){
    float n;
    int nEntero;
    long double p;
    n= (log10((b-a)/Tol))/log10(2.0);

    for(int i=0; i<n; i++){
        
        p=(a+b)/2.0;
        if((f(a)*f(p))>0){
            a=p;
        }else{
            b=p;
        }
    }
    secant(p, p+ 0.1, pow(10,-12),100);
}

/*
 * 
 */
int main(int argc, char** argv) {
    biseccionAux(0.0,2.1,0.2);
    return 0;
}

