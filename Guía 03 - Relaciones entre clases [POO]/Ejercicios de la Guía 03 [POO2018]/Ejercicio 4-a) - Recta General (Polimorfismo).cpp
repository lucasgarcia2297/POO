#include <iostream>
#include <sstream>
using namespace std;
class TPunto { 
private: 
	double x,y; 
public: 
	void asignar_valor(double xx, double yy); 
	double ver_x() {return x;}; 
	double ver_y() {return y;}; 
}; 
class RectaGeneral { 
private: 
	TPunto P1, P2; 
	double A,B,C; 
public: 
	RectaGeneral(TPunto &p1, TPunto &p2):P1(p1),P2(p2){}; 
	string obtenerEcuacion(); 
	double Ver_A(){return A;}; 
	double Ver_B(){return B;}; 
	double Ver_C(){return C;}; 
}; 
//*** Implementacion de los métodos de las clases *** 
void TPunto::asignar_valor(double xx, double yy){ 
	x= xx; y= yy; 
} 
string RectaGeneral::obtenerEcuacion() 
{/* A= -(y2-y1) 
	B=  (x2-x1) 
	C= -(y1*(x2-x1) - x1*(y2-y1))*/ 
	A = -(P2.ver_y()-P1.ver_y()); 
	B = (P2.ver_x()-P1.ver_x()); 
	C = -((P1.ver_y()* (P2.ver_x()-P1.ver_x())) - P1.ver_x()*(P2.ver_y()-
																	   P1.ver_y())); 
	stringstream aux; 
	aux.str(""); 
	aux << Ver_A()<<"  X + "<<Ver_B()<<" Y + "<<Ver_C()<<"  = 0"<<endl; 
	return aux.str(); 
} 
//******************************************************************************* 
int main(int argc, char *argv[]) { 
	TPunto punto1, punto2; 
	punto1.asignar_valor(1,1); 
	punto2.asignar_valor(4,4); 
	RectaGeneral R(punto1,punto2); 
	cout<<"P1.x= "<<punto1.ver_x()<<" , P1.y= "<<punto1.ver_y()<<endl; 
	cout<<"P2.x= "<<punto2.ver_x()<<" , P2.y= "<<punto2.ver_y()<<endl; 
	cout<<R.obtenerEcuacion(); 
	return 0; 
} 

	

