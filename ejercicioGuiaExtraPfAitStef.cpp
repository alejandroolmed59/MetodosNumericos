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
*/

 double g(double x){  
     return 1+ pow(sin(x),2);
     
 }


// Inline para calcular cada término de la sucesión de Aitken
inline double p_hat(double p0, double p1, double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximación inicial
Nmax: número máximo de iteraciones
T: tolerancia
*/
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

void aitken(double p0, int Nmax, double T){	

	double p0_hat; //último valor en la sucesión de Aitken
	double p1_hat; //valor actual en la sucesión de Aitken
		
	double p1, p2; //valores en la iteración de punto fijo 

	for(int i = 0; i <= Nmax; i++){
		p1 = g(p0);	
		p2 = g(p1);
		
		p1_hat = p_hat(p0, p1, p2);		

		if(i == 0) cout << i <<setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << endl;
		else cout <<i << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << "\t" << abs(p1_hat - p0_hat) <<endl;

		
		if(abs(p0_hat - p1_hat) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;			
			break;						
		} 

		p0 = p1;
		p0_hat = p1_hat; 
	
	}		
}

void steffensen(long double p0, int Nmax, long double T){

	long double p, p1, p2;

	for(int i = 0; i <= Nmax; i++){
		
		p1 = g(p0);
		p2 = g(p1);
		p = p_hat(p0, p1, p2);

		if(i == 0) cout <<i << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << endl;
		else cout <<  i<<setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << "\t"  << abs(p0 - p) << endl;

		if(abs(p0-p) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}

		p0 = p;
	}
}

int main(){

	fixedPoint(1.5, 100, pow(10, -9));		
	
	return 0;
}













