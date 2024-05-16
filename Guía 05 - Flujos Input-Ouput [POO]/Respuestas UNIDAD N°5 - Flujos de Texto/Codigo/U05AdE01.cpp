//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Adicional Nº 1

#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int cantidad(const string nombArchi, const string cadena){//Paso nombre de archivo y cadena a buscar
	int ocurrencias=0;//La utilizo para contar las coincidencias
	ifstream leer(nombArchi.c_str());//Creo el objeto leer asociado al archivo fisico
	if(!leer.is_open()){cout<<"Error";getchar();return(0);}//Valido
	//Declaro variables a utilizar
	string cadena2, aux;
	int p;
	while(getline(leer,cadena2)){//Leo la linea del archivo
		aux= cadena2;//Asigno al string aux
		//Utilizo este recurso para pasar la linea a minusculas
		std::transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		//cout<<aux<<endl;//Descomentar para ver lectura por pantalla
		p= aux.find(cadena);//Busco la cadena en la linea con la funcion miembro find()
		while (p !=string::npos){//Si la encontro cuenta (npos es el final del string)
			ocurrencias++;//cuento 1 mas
			p= aux.find(cadena,p+1);//Vuelvo a buscar en la linea
		}//Termino de buscar en la linea
	}//Termino de leer el archivo */
	return ocurrencias;//Devuelvo la cantidad de ocurrencias
}
//******************************************************
int main(int argc, char *argv[]) {
	int salida;
	string archivo= "Adicionales//Quijote.txt";
	string busqueda= "molinos de viento";
	salida= cantidad(archivo , busqueda);
	cout<<"La frase: "<<busqueda<<", se encontro "<<salida<<" veces en el archivo."<<endl;
	
	return 0;
}
