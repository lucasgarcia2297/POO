//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Adicional Nº 4

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
class AnalizaTexto {
	string frase;
	string::size_type largo;
public:
	AnalizaTexto(string archivo);
	void contar(int &vocales, int &consonantes, int &espacios, int &parrafos);
	string::size_type ver_largo();
	string ver_frase(){return frase;}
};
AnalizaTexto::AnalizaTexto(string narchivo){
	frase.clear();
	ifstream archivo(narchivo.c_str());//Lo abro para lectura
	if(!archivo.is_open()){cout<<"Error en apertura de archivo.";
	getchar();exit(0);}
	string  a;
	while(getline(archivo,a)){//Mientras hay datos leo el archivo
		frase+=a;//Concateno
		frase+="\n";//Enter
	}
	largo = frase.length();
}
void AnalizaTexto::contar(int &vocales, int &consonantes, int &espacios, int &parrafos){
	int i;
	vocales=0; consonantes=0; espacios= 0; parrafos=1;
	int p= frase.find_first_of("aeiou");//Busca vocales
	while (p !=string::npos){//Si encontro alguna cuenta
		vocales++;
		p= frase.find_first_of("aeiou",p+1);//Vuelve a buscar
	}
	for (char k='a'; k < 'z'; k++){//Busca letras
		int p= frase.find(k);
		while (p !=string::npos){//Si encontro alguna, cuenta
			consonantes++;
			p= frase.find(k,p+1);//Vuelve a buscar
		}	
	}
	consonantes -= vocales;//Calcula las consonantes (letras - vocales)
	p= frase.find_first_of(" ");//Busca espacios
	while (p !=string::npos){//Si encontro alguna, cuenta
		espacios++;
		p= frase.find_first_of(" ",p+1);//Vuelve a buscar
	}
	p= frase.find(".\n");//Busca espacios punto y aparte
	while (p !=string::npos){//Si encontro alguna, cuenta
		parrafos++;
		p= frase.find(".\n",p+1);//Vuelve a buscar
	}
}
string::size_type AnalizaTexto::ver_largo(){
	return largo;
}
//************************************************************************
int main(){
	AnalizaTexto T("Adicionales\\agenda.txt");
	int voc, cons, esp, par;
	cout<<" FICH - P.O.O."<<endl;
	cout<<"frase: "<<endl;
	cout<<T.ver_frase();
	T.contar(voc,cons,esp,par);
	cout<<"\n";
	cout<<"\nTotal de letras: "<<cons+voc<<endl;
	cout<<"\nTotal de Vocales: "<<voc<<endl;
	cout<<"\nTotal de Consonantes: "<<cons<<endl;
	cout<<"\nTotal de Espacios: "<<esp<<endl;
	cout<<"\nTotal de Parrafos: "<<par<<endl;
}
//(c)Prof. Gerardo Sas.
