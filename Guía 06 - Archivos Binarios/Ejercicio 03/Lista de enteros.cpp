#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
struct Vector{
	int t;
	int *p; 
};
/**Ejercicio 3:
Escriba un programa que genere un archivo binario con una lista de 100 enteros                            
ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba                            
otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,                          
ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar                          
vectores auxiliares.**/
int main(int argc, char *argv[]) {
	Vector v;
	v.t = 100;
	v.p = new int [v.t];
	fstream archi("Lista de enteros - Original.binario", ios::binary | ios::out);
	if(archi.is_open()){
		v.p[0] = 0;
		archi.seekp(0);
		archi.write(reinterpret_cast<char*> (&v.p[0]),sizeof(int));
		cout << "v[0] = "<< v.p[0]<<endl;
		for(int i=1;i<v.t;i++) { 
			v.p[i] = v.p[i-1] + 5;
			cout << "v["<<i<<"] = "<<v.p[i] <<endl; 
			archi.seekp(i*sizeof(int));
			archi.write(reinterpret_cast<char*> (&v.p[i]),sizeof(int));
		}
	}
	else{
		cerr << "No se pudo abrir el archivo.";
	}
	archi.close();
	
	delete [] v.p; 
	return 0;
}
