#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

//Definimos la funci�n
inline double f(double v) {
    return  (0.08205* 273.15)/v + (-1.16583607818894)/pow(v,2) + 
    (0.0542253936905836)/pow(v,3) + (-1.25100322759761*pow(10,-4))/pow(v,4) -200 ; }

//Derivada de la funci�n
inline double df(double v) { 
    return  (-0.08205* 273.15)/pow(v,2) - (2*-1.16583607818894)/pow(v,3) -(3*0.0542253936905836)/pow(v,4) - (4*(-1.25100322759761*pow(10,-4)))/pow(v,5) ;
    
}

/*
p0: Aproximaci�n inicial
TOL: tolerancia
Nmax: n�mero m�ximo de iteraciones
*/
void newton(double p0,double TOL,double Nmax){

	double p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(20) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el m�todo seg�n los datos del problema
	newton(0.1120597875, pow(10, -9), 40);
	return 0;
}