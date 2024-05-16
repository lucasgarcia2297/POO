#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream ArchiSalida("Datos.binario",ios::binary);
		int n = 10;
		int *x = new int[n];
		x[0] = 0;
		ArchiSalida.write(reinterpret_cast<char*> (&x[0]),sizeof(int));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
//		float *f = new float[n];
	if(!ArchiSalida.is_open()){
		cout << "No se pudo abrir.";
		return 1;
	}else{
		int cant_bytes = ArchiSalida.tellp();
		int tamanio = cant_bytes/sizeof(char);
		ArchiSalida.seekp(1*sizeof(int));
		cout << "Tamaño del arhivo: " << tamanio<< endl;
		for(int i=1;i<n;i++) { 
			x[i] = x[0]+i;
////			f[i] = x[i]/1000.f;
			//		cout << x << endl; //el << convierte el valor de la variable en el codigo ascii correspondiente;
			//en binario la x valor 4 bytes como cualquier entero;
			ArchiSalida.write(reinterpret_cast<char*> (&x[i]),sizeof(int));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
//			ArchiSalida.write(reinterpret_cast<char*> (&f),sizeof(float));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
		}
		ArchiSalida.close();
	}
	
	ifstream ArchiEntrada("Datos.binario", ios::binary|ios::ate); //arranca desde el final
	if(!ArchiEntrada.is_open()){
		cout << "No se pudo abrir.";
		return 1;
	}else{
		int cant_bytes = ArchiEntrada.tellg();
		int tamanio = cant_bytes/sizeof(char);
		ArchiEntrada.seekg(0);
		cout << "Tamaño del archivo: " << tamanio<< endl;
//		cout << ArchiEntrada.tellg()<<endl;	// para saber en qué posicion esta
//		int tamanio = ArchiEntrada.tellg();
//		int n = tamanio/sizeof(int);
//		cout<< n << endl;   
//		ArchiEntrada.seekg(0); // seekg sirve para 
//		cout << ArchiEntrada.tellg()<<endl;	// 
//		
		//	ifstream ArchiEntrada("Datos.binario",ios::binary);
		//	ArchiEntrada.seekg(200*sizeof(int));    //saltea los 100 primeros enteros (posicion 400)
		cout << ArchiEntrada.tellg()<<endl;	// para saber en qué posicion esta
		for(int i=0;i<n;i++) { 
			int x; 
//			float f;
			//		cout << x <<endl; //el << convierte el valor de la variable en el codigo ascii correspondiente;
			//en binario la x valor 4 bytes como cualquier entero;
			ArchiEntrada.read(reinterpret_cast<char*> (&x),sizeof(int));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
//			ArchiEntrada.read(reinterpret_cast<char*> (&f),sizeof(float));  //el sizeof(int) es la cantidad de bytes que va a tomar luego de la primera posicion definida por el puntero &x
			cout << "V["<< i<<"]=" <<x << "   " /*<< f*/ << endl;
			
		}
		ArchiEntrada.close();
	}
	return 0;
}

