#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class EcuacionCuadratica{
private:
	float a, b, c, x1, x2, p_real,p_imag;
public:
	EcuacionCuadratica(float a,float b, float c);//item a.
	bool TieneRaicesReales();  	//item b.
	float VerRaiz1();			//item c.
	float VerRaiz2();
	void ObtenerRaices();
	float VerParteReal();
	float VerParteImag();
};
EcuacionCuadratica::EcuacionCuadratica(float a1,float b1, float c1){
	a = a1; b = b1; c = c1;
}//item a.
bool EcuacionCuadratica::TieneRaicesReales(){
	if((b*b-(4*a*c))>=0)
	   return true;
	else
		return false;
}
void EcuacionCuadratica::ObtenerRaices(){
	if(EcuacionCuadratica::TieneRaicesReales()){
		x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
	}
	else{
		p_real = (-b)/(2*a);
		p_imag = (sqrt(abs(b*b-4*a*c)))/(2*a);
	}
}
float EcuacionCuadratica::VerRaiz1(){
	return x1;
}

float EcuacionCuadratica::VerRaiz2(){
	return x2;
}
float EcuacionCuadratica::VerParteReal(){
	return p_real;
}
float EcuacionCuadratica::VerParteImag(){
	return p_imag;
}
	
int main(int argc, char *argv[]) {
	float a,b,c;
	cout << "Ingrese los valores de los coeficientes: "<<endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	EcuacionCuadratica N(a,b,c); //debo agregarle parametros porque cree el constructor
	N.ObtenerRaices();
	if(N.TieneRaicesReales()){
		cout << "---------Raices Reales--------"<<endl;
		cout << "X1 = " <<N.VerRaiz1() << endl;
		cout << "X2 = " <<N.VerRaiz2() << endl;
	}else{
		cout << "---------Raices Complejas----------"<< endl;
		if((-(N.VerParteImag()))<0){
			cout << "X1 = "<< N.VerParteReal() <<" +" <<N.VerParteImag()<<"i"<< endl;
			cout << "X2 = "<< N.VerParteReal() <<" "<< -(N.VerParteImag())<<"i"<<endl;
		}
		else{
			cout << "X1 = "<< N.VerParteReal() <<" "<< N.VerParteImag()<<"i"<<endl;
			cout << "X2 = "<< N.VerParteReal() <<" +" <<-(N.VerParteImag())<<"i"<< endl;
		}
	}
	return 0;
}

