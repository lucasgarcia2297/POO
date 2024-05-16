#include <iostream>
#include <sstream>
using namespace std;
/**Ejecicio 4_b)**/
//********************************************************************* 
class TPunto { 
private: 
	double x,y; 
public: 
	void asignar_valor(double xx, double yy); 
	double ver_x() {return x;}; 
	double ver_y() {return y;}; 
}; 
//********************************************************************* 
class TRecta{ //Clase BASE Abstracta porque tiene al menos 1 metodo virtual puro 
protected: 
	TPunto P1, P2;//Por agregacion o composición de clases 
public: 
	void asignar_coordenadas(double, double, double, double); 
	virtual void obtenerEcuacion()=0;//Metodo virtual puro 
	virtual string mostrar()=0;//Metodo virtual puro 
	virtual ~TRecta(){}; 
}; 
//*** TGeneral herencia simple de TRecta ******************************* 
class TGeneral: public TRecta{ 
private: 
	double A,B,C; 
public: 
	void obtenerEcuacion(); 
	string mostrar(); 
	double ver_A() {return A;}; 
	double ver_B() {return B;}; 
	double ver_C() {return C;}; 
}; 
//*** TExplicita herencia simple de TRecta ***************************** 
class TExplicita: public TRecta 
{private: 
	double m, b; 
public: 
	void obtenerEcuacion(); 
	string mostrar(); 
	double ver_m() {return m;}; 
	double ver_b() {return b;}; 
}; 
//*** Implementacion de los métodos de las clases *** 
void TPunto::asignar_valor(double xx, double yy){ 
	x= xx; y= yy; 
} 
void TRecta::asignar_coordenadas(double x1, double y1, double x2, double y2){ 
	P1.asignar_valor(x1,y1); 
	P2.asignar_valor(x2,y2); 
} 
void TExplicita::obtenerEcuacion() { 
	m = (P2.ver_y()-P1.ver_y())/(P2.ver_x()-P1.ver_x()); 
	b = P1.ver_y() - (m * P1.ver_x()); 
} 
void TGeneral::obtenerEcuacion() 
{/* A= -(y2-y1) 
	B= (x2-x1)16 
	C= -(y1*(x2-x1) - x1*(y2-y1))*/ 
	A = -(P2.ver_y()-P1.ver_y()); 
	B = (P2.ver_x()-P1.ver_x()); 
	C = -((P1.ver_y()* (P2.ver_x()-P1.ver_x())) - P1.ver_x()*(P2.ver_y()- P1.ver_y())); 
} 
string TExplicita::mostrar() { 
	stringstream aux; 
	aux.str(""); 
	aux << " Y = "<<ver_m()<<" . X + "<<ver_b()<<endl; 
	return aux.str(); 
} 
string TGeneral::mostrar(){ 
	stringstream aux; 
	aux.str(""); 
	aux <<endl<< ver_A()<<" X + "<<ver_B()<<" Y + "<<ver_C()<<" = 0"<<endl;
	return aux.str(); 
} 
//-------------Cuerpo principal del Programa -------------------------- 
int main(int argc, char *argv[]) { 
	double x1, x2, y1, y2; 
	TExplicita R1; 
	TGeneral R2; 
	TRecta *PR; 
	cout<<" FICH - P.O.O. "<<endl<<endl<<endl; 
	cout << "DATOS DE LOS PUNTOS P1 Y P2."<<endl<< endl; 
	cout << "Ingrese X1: "; cin>> x1; 
	cout << "Ingrese Y1: "; cin>> y1; 
	cout << endl; 
	cout << "Ingrese X2: "; cin>> x2; 
	cout << "Ingrese Y2: "; cin>> y2; 
	cout << endl; 
	PR= &R1; 
	PR->asignar_coordenadas(x1,y1,x2,y2); 
	PR->obtenerEcuacion(); 
	cout<<PR->mostrar(); 
	PR= &R2; 
	PR->asignar_coordenadas(x1,y1,x2,y2); 
	PR->obtenerEcuacion(); 
	cout<<PR->mostrar(); 
	return 0; 
}

