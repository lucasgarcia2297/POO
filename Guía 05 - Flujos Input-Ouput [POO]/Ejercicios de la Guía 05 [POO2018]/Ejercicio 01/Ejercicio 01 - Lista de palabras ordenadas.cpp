#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/** Escriba un programa que cargue en un vector de strings una lista de palabras                            
desde un archivo de texto (que contendrá una palabra por línea), muestre en                          
pantalla la cantidad de palabras leídas, las ordene en el vector alfabéticamente, y                          
reescriba el archivo original con la lista ordenada. 
Ayuda: para ordenar un vector v de principio a fin puede utilizar la sentencia                            
“sort(v.begin(),v.end()).
**/
int main(int argc, char *argv[]) {
	fstream archi("Ejercicio 1.txt");
	vector<string> v;
	if(archi.is_open()){
		string palabra;
		while(archi >> palabra){
			v.push_back(palabra);
			cout << palabra<< endl;
		}
		archi << "\nCantidad de palabras leídas: " << v.size();
		archi.close();
	}
	else
		cout << "No se pudo abrir";
	
	archi.open("Ejercicio 1.txt",ios::trunc);
	cout << "\nOrdenado alfabeticamente: " << endl;
	archi << endl;
	sort(v.begin(),v.end());
	for(size_t i=0;i<v.size();i++) { 
		archi >> v[i];
		cout << v[i] << endl;
	}
	archi.close();
	return 0;
}

