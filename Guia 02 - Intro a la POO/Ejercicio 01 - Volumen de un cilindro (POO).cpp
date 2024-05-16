#include <iostream>
#include <cmath>
using namespace std;
typedef struct cilindro{
private:
	float r, h; 
public:
	cilindro(float rr=0, float hh=0){  //constructor
		r = rr; h = hh;
	}
//	cilindro(){} // otra opción
	void AsignarDatos(float radio, float altura);
	float ObtenerVolumen();
	float ver_radio();
	float ver_altura();
};
void cilindro::AsignarDatos(float radio, float altura){
	r= radio; h = altura;
}
float cilindro::ObtenerVolumen(){
	return 3.1415*r*r*h;
}
float cilindro::ver_altura(){
	return h;
}

float cilindro::ver_radio(){
	return r;
}
int main(int argc, char *argv[]) {
	cilindro c1, c2;
	float altura, radio;
	cout << "Radio del cilindro 1: " << endl;
	cin >> radio;
	cout << "\nAltura del cilindro 1: " << endl;
	cin >> altura;
	c1.AsignarDatos(radio, altura);
	c2.AsignarDatos(5.3,10.2);
	cout << "\n----------Datos Cilindro1----------"<< endl;
	cout << "Radio = " << c1.ver_radio()<< "cm  Altura = "  << c1.ver_altura()<< "cm." <<endl;
	cout << "Volumen: "<< c1.ObtenerVolumen()<< endl;
	cout << "-----------------------------------"<< endl << endl;
	cout << "----------Datos Cilindro2----------"<< endl;
	cout << "Radio = " << c2.ver_radio()<< "cm  Altura = " << c2.ver_altura()<< "cm."<< endl;
	cout << "Volumen: "<< c2.ObtenerVolumen()<< endl;
	cout << "-----------------------------------";
								
	return 0;
}

