#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

//Definimos la funci�n
inline long double f(long double x) { return exp(x) - x - 2; }

/*
p0: aproximaci�n inicial
p1: aproximaci�n inicial
TOL: tolerancia
Nmax: n�mero m�ximo de iteraciones
*/
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
	
int main(){

	//Invocamos el m�todo con los par�metros dados en el problema	
	secant(0.8, 1.0, pow(10, -15), 40);

	return 0;
}