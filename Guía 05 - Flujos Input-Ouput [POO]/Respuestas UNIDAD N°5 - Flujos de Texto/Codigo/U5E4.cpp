//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Nº 4

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
struct registro {
	string campo, valor;
	} ;
//***************************************************
class ConfigFile{
private:
	vector<registro> V;
	string nombreArchivo;
public:
	ConfigFile(string);
	string ver_campo(string campo);
	void modificar_campo(string, string);
	void guardar(string);
	void ver_vector();
};
//Implementacion ************************
ConfigFile::ConfigFile(string nombArchi){
	nombreArchivo=nombArchi;
	ifstream leer(nombArchi.c_str());
	if(!leer.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	string aux,cadena;
	int pos;
	registro R;
	while(getline(leer,cadena)){
		aux= cadena;
		if(aux.substr(0,1)!="#"){//Si es distinto de #
			pos=aux.find("=");//Busco el =
			R.campo=aux.substr(0,pos);//Corto el campo
			R.valor=aux.substr(pos+1);//Corto el valor
			V.push_back(R);//Agrego R al vector
		}
	}
	leer.close();//Cierro el archivo
}
string ConfigFile::ver_campo(string campo){
if(V.empty()){return "Archivo vacio";}
int x=0;
while((x<V.size())&&(V[x].campo.compare(campo)!= 0)){
	x++;}
if(V[x].campo.compare(campo)== 0)
   return V[x].valor;
else
	return "ERROR";
}
void ConfigFile::modificar_campo(string campo, string valor2){
	if(V.empty()){return;}
	int x=0;
	while((x<V.size())&&(V[x].campo.compare(campo)!= 0)){
		x++;}
	if(V[x].campo.compare(campo)== 0)
	   V[x].valor= valor2;
}

void ConfigFile::guardar(string nombArchi){
	ofstream escribir(nombArchi.c_str());
	if(!escribir.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	for(int x=0; x<(int)V.size(); x++){
		escribir<<V[x].campo<<"="<<V[x].valor<<endl;
	}
	escribir.close();
}
void ConfigFile::ver_vector(){
	cout<<"Tamaño del Vector:  "<<V.size()<<endl;
	for(registro R:V)
		cout<<R.campo<<"="<<R.valor<<endl;
}
//****************************************************************************
int main(int argc, char *argv[]) {
ConfigFile F("archiE04.txt");	
F.ver_vector();
cout<<"\n\nVer campo Facultad: ";
cout<<F.ver_campo("facultad");
cout<<"\n\nModificar campo nro_unidad=6: "<<endl<<endl;
F.modificar_campo("nro_unidad", "6");
F.ver_vector();
F.guardar("archiE04bis.txt");
return 0;
}

