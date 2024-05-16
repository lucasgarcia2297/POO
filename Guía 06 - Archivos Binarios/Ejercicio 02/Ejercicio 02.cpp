#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream Archi;
	Archi.open("Datos.binario", ios::binary	| ios::in | ios::out);
	if(Archi.is_open()){
		
	
		int pos, x;
	
		float f;
		Archi.white(reinterpret_cast<char*> (&x),sizeof(int));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
		Archi.white(reinterpret_cast<char*> (&f),sizeof(float));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
		cout << "v["<<i<<"]=" << x << " " << f << endl;
		
	Archi.close();
	}
	else{
		cout << "El archivo no se pudo abrir.";
	}
	return 0;
}

