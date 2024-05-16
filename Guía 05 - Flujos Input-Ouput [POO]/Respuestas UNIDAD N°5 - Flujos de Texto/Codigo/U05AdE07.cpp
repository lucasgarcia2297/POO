//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Adicional Nº 7

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
void corregir_formato(string arch_origen, string arch_destino){
	ifstream lectura(arch_origen.c_str());//Creo el objeto para leer asociado al archivo fisico
	if(!lectura.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	ofstream escritura(arch_destino.c_str());//Creo el objeto para escribir asociado al archivo fisico
	if(!escritura.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	//Declaro variables a utilizar
	string cadena2, aux, car1, aux2;
	int p_ini,p_fin;
	while(getline(lectura, cadena2)){//Leo la linea del archivo
		aux+= cadena2;//Concateno
		aux+= "\n";//Enter, salto de linea
	}
	lectura.close();//Termino la lectura del archivo
	//cout<<aux<<endl;//Descomentar para ver en pantalla
	//Tengo el archivo en aux
	//Utilizo este recurso para pasar la linea a minusculas
	std::transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
	//Paso primer letra a mayusculas.
	aux[0]= toupper(aux[0]);
	//Punto y aparte
	p_ini= 0;
	p_fin= aux.find("\n");//Busco la cadena en la linea con la funcion miembro find()
	while (p_fin != string::npos){//Si la encontro cuenta (npos es el final del string)
		car1 = aux[p_fin-1];
		if("." == car1){//Si el caracter anterior al <enter> es <punto>
			aux[p_fin+1]= toupper(aux[p_fin+1]);//Guardo la letra mayuscula
		}
		p_ini=p_fin+2;//Actualizo p_ini
		p_fin= aux.find("\n",p_ini);//Vuelvo a buscar en la linea
	}//Termino busqueda en aux
	//Punto y seguido
	p_ini= 0;
	p_fin= aux.find(". ");//Busco la cadena en la linea con la funcion miembro find()
	while (p_fin !=string::npos){//Si la encontro cuenta (npos es el final del string)
		if(p_fin+2<aux.length()){
			aux[p_fin+2]= toupper(aux[p_fin+2]);//Guardo la letra mayuscula
			p_ini=p_fin+3;//Actualizo p_ini
			p_fin= aux.find(". ",p_ini);//Vuelvo a buscar en la linea
			}
		}//Termino de buscar en aux
	escritura<<aux<<endl;//Guardo la nueva linea en escritura
	//Termino de utilizar el archivo */
	escritura.close();
	//cout<<endl<<aux<<endl;//Descomentar para ver en pantalla
}
//*****************************************************************************
int main(int argc, char *argv[]) {
	string archivo_orig= "Adicionales//Texto.txt";
	string archivo_dest= "Adicionales//Texto2.txt";
	corregir_formato(archivo_orig,archivo_dest);
	return 0;
}
