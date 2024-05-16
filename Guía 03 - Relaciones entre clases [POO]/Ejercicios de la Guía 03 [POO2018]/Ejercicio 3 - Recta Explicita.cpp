#include <iostream>
#include <sstream>
using namespace std;
/**Ejercicio 3: Recta explicita**/
class TPunto{
private:
	float x,y;
public:
	void AsignarValor(float xx, float yy){
		x= xx; y = yy;
	};
	float ver_x(){ return x;}
	float ver_y(){ return y;}
};
class TExplicita{
private: 
	TPunto p1, p2;
	float a, b;
public:
	TExplicita(TPunto &p_1, TPunto &p_2):p1(p_1),p2(p_2){};
	string ObtenerEcuacion();
	float ver_a() {return a;};
	float ver_b() {return b;};
};
string TExplicita::ObtenerEcuacion(){
	/*stringstream:  Los objetos de esta clase usan un buffer de cadena que  
	contiene una secuencia de caracteres. Se puede acceder a esta secuencia  
	de caracteres directamente como un objeto de cadena, utilizando miembro 
	str. */ 
	
	float A,B,C;
/*	A= -(y2-y1) 
	B=  (x2-x1) 
	C= -((y1*(x2-x1)–x1*(y2-y1)))  */
	A = -(p2.ver_y() - p1.ver_y());
	B = p2.ver_x() - p1.ver_x();
	C = -((p1.ver_y()*(p2.ver_x() - p1.ver_x())-p1.ver_x()*(p2.ver_y() - p1.ver_y())));
	float a = -(A/B), b=-(C/B);
	stringstream aux;
	aux.str("");
	aux << " Y = "<<a<<"x + ("<<b<<")"<<endl;
	return aux.str();
}
int main(int argc, char *argv[]) {
	TPunto punto1, punto2;
	punto1.AsignarValor(2,1);
	punto2.AsignarValor(1,2);
	cout << "P1.x = "<< punto1.ver_x()<< ", P1.y = "<< punto1.ver_y()<< endl;
	cout << "P2.x = "<< punto2.ver_x()<< ", P2.y = "<< punto2.ver_y()<< endl;
	TExplicita R(punto1,punto2);
	string ecuacion="";
	ecuacion = R.ObtenerEcuacion();
	cout << ecuacion << endl;
		
	return 0;
}

