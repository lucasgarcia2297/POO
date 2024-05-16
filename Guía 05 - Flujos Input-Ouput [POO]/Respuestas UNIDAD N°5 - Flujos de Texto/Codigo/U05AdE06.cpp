//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Adicional Nº 6

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;
int reemplaza(string arch_origen, string arch_destino, string cad1, string cad2){
	int ocurrencias=0;//La utilizo para contar los reemplazos
	ifstream lectura(arch_origen.c_str());//Creo el objeto para leer asociado al archivo fisico
	if(!lectura.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	ofstream escritura(arch_destino.c_str());//Creo el objeto para escribir asociado al archivo fisico
	if(!escritura.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	//Declaro variables a utilizar
	string cadena2, aux;
	stringstream aux2;
	int p_ini,p_fin,longitud= cad2.length();
	while(getline(lectura,cadena2)){//Leo la linea del archivo
		aux= cadena2;//Asigno al string aux
		aux2.str("");//Linpio aux2
		//Utilizo este recurso para pasar la linea a minusculas
		std::transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		//cout<<aux<<endl;//Descomentar para ver lectura por pantalla
		p_ini= 0;
		p_fin= aux.find(cad1);//Busco la cadena en la linea con la funcion miembro find()
		while (p_fin !=string::npos){//Si la encontro cuenta (npos es el final del string)
			ocurrencias++;//cuento 1 mas
			aux2<<aux.substr(p_ini,p_fin)+cad2+aux.substr(p_fin+longitud);//Creo aux2 con el reemplazo
			aux= aux2.str();//Guardo la nueva cadena en aux
			p_ini=p_fin+1;//Actualizo p_ini
			p_fin= aux.find(cad1,p_ini);//Vuelvo a buscar en la linea
		}//Termino de buscar en la linea
		escritura<<aux<<endl;//Guardo la nueva linea en escritura
	}//Termino de leer el archivo */
	lectura.close();
	escritura.close();
	return ocurrencias;
}
//**************************************************************************
int main(int argc, char *argv[]) {
	int salida;
	string archivo_orig= "Adicionales//Quijote.txt";
	string archivo_dest= "Adicionales//Quijote_Trucho.txt";
	string busqueda= "molinos de viento";
	string cambia="turbina de agua";
	int r= reemplaza(archivo_orig, archivo_dest,busqueda,cambia);
	cout<<"Se ralizaron "<<r<<" reemplazos"<<endl;
	return 0;
}

