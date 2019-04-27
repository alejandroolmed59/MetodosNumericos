#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// Función para IPF


/*
Iteración de punto fijo
p0: aproximación inicial
Nmax: número máximo de iteraciones
T: tolerancia
-rapidez: O((k)^n)
k= abs(g'(p)) ; p es el valor de la ultima iteracion del metodo ("la solucion")
Condiciones:
Existencia: g(x) toma numeros del interavlo y los vuelve a poner en el intervalo
Unicidad: fmax(abs(g'(x), x ,a,b) y evaluando eso en abs(g'(x))<1
Tabla: n, p

Si k en ipf 0<k<0.5 es mas rapida que bisecc
Si k en ipf 0.5<k<1 es mas lenta que bisecc
Si k en ipf k=0 es son iguales
*/

 double g(double x){  
     return (1.50*x)-(0.16666)*(pow(x,3)+1);
     
 }

void fixedPoint(double p0, int Nmax, double T){
	
	double p;	

	for(int i=0; i< Nmax; i++){
		p = g(p0);		
		cout << setprecision(10) <<  i << "\t" << "\t" << p << "\t" <<abs(p-p0) <<endl;
		
		if(abs(p-p0) < T) {
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}
		
		p0 = p;
	}
	
}



int main(){

	fixedPoint(-2, 30, pow(10, -3));	
}