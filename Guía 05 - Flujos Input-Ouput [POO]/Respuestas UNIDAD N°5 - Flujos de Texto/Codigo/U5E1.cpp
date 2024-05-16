//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio 1
/*Escriba un programa que cargue en un vector de strings una lista de palabras
desde un archivo de texto (que contendrá una palabra por línea), muestre en
pantalla la cantidad de palabras leídas, las ordene en el vector alfabéticamente, y
reescriba el archivo original con la lista ordenada.
Ayuda: para ordenar un vector ?v de principio a fin puede utilizar la sentencia
“sort(v.begin(),v.end());”.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	vector<string> texto;
	string palabra;
	ifstream archiLect("palabras.txt");
	if(!archiLect.is_open()){cout<<"Error";return 1;}
	while(getline(archiLect, palabra)){
		texto.push_back(palabra);
		cout<<palabra<<endl;
	}
	archiLect.close();
	ofstream archiEsc("palabras2.txt");
	if(!archiEsc.is_open()){cout<<"Error";return 1;}
	sort(texto.begin(),texto.end());
	cout<<"***********************************"<<endl;
	for(string T:texto){
		cout<<T<<endl;
		archiEsc<< T << endl;
	}
	archiEsc.close();
	return 0;
}

