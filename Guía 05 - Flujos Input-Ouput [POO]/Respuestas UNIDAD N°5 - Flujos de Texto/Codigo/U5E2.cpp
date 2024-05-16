//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - 
/*Ejercicio 2
En un archivo de texto llamado lista.txt
Se encuentran los nombres y notas de los alumnos de una comisión de Programación
Orientada a Objetos.
a) Escriba una función modificar que reciba el nombre 
de un alumno y dos notas, y modifique el archivo
reemplazando las dos notas de ese alumno.
b) Escriba una función que lea la lista del archivo y genere otro archivo de texto
promedios.txt ?con una tabla donde cada línea posea el nombre, el promedio,
y la condición final de cada uno de los alumnos.
Ayuda: utilice manipuladores de flujo (?setw?, ?right?, ?left?, ?fixed?, ?setprecision?) para dar
formato a la tabla del archivo que se genera en b).
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
struct ficha{
	string nombre;
	int nota1,nota2;
};
//Item a) 
void modificar(ficha F, string nombArchi){
	vector<ficha> Fichero;
	ficha aux;
	ifstream archiLect(nombArchi.c_str());
	if(!archiLect.is_open()){cout<<"Error";exit;}
	while(getline(archiLect,aux.nombre)){
		archiLect >> aux.nota1;
		archiLect >> aux.nota2;
		archiLect.ignore();
		if(aux.nombre.compare(F.nombre) == 0){
			aux.nota1= F.nota1;
			aux.nota2= F.nota2;
		}
		Fichero.push_back(aux);
	}
	archiLect.close();
	ofstream archiEsc("lista2.txt");
	if(!archiEsc.is_open()){cout<<"Error";exit;}
	for(ficha FI:Fichero)
		archiEsc<< FI.nombre<<endl<<FI.nota1<<"  "<<FI.nota2<<endl;
	archiEsc.close();
}
//Item b)
void promedio(string nombArchi){
	ficha aux;
	float prom;
	ifstream archiLect(nombArchi.c_str());
	if(!archiLect.is_open()){cout<<"Error";exit;}
	ofstream archiEsc2("Promedio.txt");
	if(!archiEsc2.is_open()){cout<<"Error";exit;}
	while(getline(archiLect,aux.nombre)){
		archiLect >> aux.nota1;
		archiLect >> aux.nota2;
		archiLect.ignore();
		prom= ((aux.nota1+aux.nota2)/(2.0));
		archiEsc2<< aux.nombre<<endl<<prom<<endl;
	}
	archiLect.close();
	archiEsc2.close();
}
void mostrar(string arch){
	string cadena;
	stringstream texto;
	texto.clear();
	ifstream archivo(arch.c_str());
	if (archivo.is_open()){
		while (getline(archivo, cadena)){
			texto<< cadena<<endl;
		}
		cout<<setw(20)<<texto.str();
	}else cout<<"ERROR"<<endl;
}

int main() {
	ficha FF;
	FF.nombre= "Garcia Ana";
	FF.nota1= 10;
	FF.nota2= 10;
	cout<<"********Lista 1**************"<<endl;
	mostrar("lista1.txt");
	modificar(FF,"lista.txt");
	cout<<"********Lista 2**************"<<endl;
	mostrar("lista2.txt");
	promedio("lista1.txt");
	cout<<"********Promedio **************"<<endl;
	mostrar("Promedio.txt");
	return 0;
}
