//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Adicional Nº 3

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
//*******************************************************
void creaLista(){
	ofstream lista("Adicionales//agenda.txt");
	if (!lista.is_open()){cout<<"ERROR ";getchar();exit(0);}
	lista<<"Lopez Javier"<<endl;
	lista<<"0342-15619022"<<endl;
	lista<<"Garcia Ana"<<endl;
	lista<<"0342-15677381"<<endl;
	lista<<"Farias Daniel"<<endl;
	lista<<"0342-15604602"<<endl;
	lista.close();//cerramos el archivo
}
//-------------------------------------------------------------
struct ficha{
	string nombre, telefono;
};
//Clase Agenda, Interface--------------------------------------
class Agenda{
private:
	vector<ficha> V;
	string nombreArchivo;
public:
	bool cargar(string nombArch);
	ficha buscar(string dato);
	void ver_agenda();
	void agregar_contacto(ficha f);
};
//Clase Agenda, Implementacion ---------------------------------
bool Agenda::cargar(string nombArch){
	nombreArchivo= nombArch;
	ifstream archivo(nombArch.c_str());//Lo abro para lectura
	if(!archivo.is_open()){//Verifica la apertura del archivo
		cout<<"Error en apertura de archivo.";
		getchar();return false;}
	char a[50];
	ficha aux;
	while(archivo.getline(a,50)){//Mientras hay datos leo el archivo
		aux.nombre= a;
		archivo.getline(a,50);//Leo Telefono
		aux.telefono= a;
		V.push_back(aux);//Agrego al vector
	}
	archivo.close();
	return true;
}
ficha Agenda::buscar(string dato){
	int p;
	ficha aux; aux.nombre="E R R O R";
	string may;
	for(int n=0; n<(int)V.size(); n++){
		may=V[n].nombre;//Utilizo este recurso para pasar las cadenas a mayusculas
		std::transform(may.begin(), may.end(), may.begin(), ::toupper);
		std::transform(dato.begin(), dato.end(), dato.begin(), ::toupper);
		p= may.find(dato);;//Busco la cadena en la linea con la funcion miembro find()
		if (p !=string::npos){//Si la encontro (npos es el final del string)
			aux= V[n];//Copio el struct
			return aux;}//Devuelvo el struct y salgo del metodo
	}
}
void Agenda::ver_agenda(){
	cout<<"Cantidad de Fichas: "<<V.size()<<endl;
	for(int n=0; n<(int)V.size(); n++){
		cout<<n<<" - "<<V[n].nombre<<" - "<<V[n].telefono<<endl;
	}
}
void Agenda::agregar_contacto(ficha f){
	V.push_back(f);
	ofstream salida(nombreArchivo.c_str());
	//Verifica la apertura del archivo
	if(!salida.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	for(int x=0;x<(int)V.size();x++){
		salida<<V[x].nombre.c_str()<<endl;//Guardo en el archivo
		salida<<V[x].telefono.c_str()<<endl;//Guardo en el archivo
	}
	salida.close();
}

//*****************************************************************************
int main(int argc, char *argv[]) {
	creaLista();//Creo el archivo
	Agenda A;//Declaro el objeto tipo Agenda
	A.cargar("Adicionales//agenda.txt");//Cargo las fichas desde el archivo
	A.ver_agenda();//Muestro el vector de fichas en pantalla
	char dato[50];
	cout<<"Ingrese Apellido y/o nombre a buscar: ";
	cin.getline(dato,50);//Ingreso el dato a buscar
	ficha f1= A.buscar(dato);//Busco el Apellido y/o nombre en el arreglo dinamico
	cout<<f1.nombre<<" - "<<f1.telefono<<endl;//Muestro resultado
	cout<<"Ingrese Nuevo Apellido y nombre para agregar: ";
	cin.getline(dato,50);//Ingreso el dato a buscar
	f1.nombre= dato;//Apellido y nombre 
	cout<<"Ingrese Telefono para agregar: ";
	cin.getline(dato,50);//Ingreso el dato a buscar
	f1.telefono= dato;//Apellido y nombre 
	A.agregar_contacto(f1);
	A.cargar("Adicionales//agenda.txt");//Cargo las fichas desde el archivo
	A.ver_agenda();//Muestro el vector de fichas en pantalla
	return 0;
}

