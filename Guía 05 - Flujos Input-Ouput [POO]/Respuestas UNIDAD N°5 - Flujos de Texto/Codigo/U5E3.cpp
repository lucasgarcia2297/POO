//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/
//Guia de estudios Nº 5 - Ejercicio Nº 3

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

void crear_lista(){//Creo el archivo de inscriptos
	ofstream inscriptos("inscriptos.txt");
	if(!inscriptos.is_open()){//Verifica la apertura del archivo
		cout<<"Error en apertura de archivo.";
		getchar();exit(0);}
	char letra;
	for(int x= 0; x< rand()%200+100;x++){//Crea entre 100 y 200 registros
		letra=(char)(65+rand()%24);//Genera una letra al azar
		for(int k=0; k<10; k++){//la escribe 10 veces, una al lado de la otra
			inscriptos<<letra;
			if(k==6) inscriptos<<", ";//Separo apellido
		}
		inscriptos<<endl;//Guarda el fin de linea (\n).-
	}
	inscriptos.close();//Cierra el archivo
}
//******************************************************
void leer(vector<string> &alumnos, string archi){//Paso vector por referencia y archivo
	ifstream archivo(archi.c_str());//Lo abro para lectura
	if(!archivo.is_open()){//Verifica la apertura del archivo
		cout<<"Error en apertura de archivo.";
		getchar();exit(0);}
	string al;
	while(getline(archivo,al))//Mientras hay palabras leo el archivo
		alumnos.push_back(al);//Agrego al vector
	archivo.close();
}
//******************************************************
void repartir(vector<string> &alumnos){
	int comisiones= (alumnos.size()/30)+1;
	cout<<"Cantidad de comisiones: "<<comisiones<<endl;
	stringstream nombArchi;
	ofstream salida("");
	for(int x=0,comis=0;x<(int)alumnos.size();x++){
		if(x%30==0){comis++;
		if(salida.is_open())salida.close();//Cierro el archivo.
		nombArchi.str("");//Limpio el contenido
		nombArchi<<"Comision_"<<comis;//Concateno letras y numeros
		cout<<nombArchi.str()<<endl;//Muestro en pantalla
		nombArchi<<".txt";//Concateno extensión 
		salida.open(nombArchi.str());//Abro el arcivo nuevo
		if(!salida.is_open()){cout<<"Error";getchar();exit(0);}//Valido
		}
		cout<<alumnos[x]<<endl;//Muestro en pantalla
		salida<<alumnos[x].c_str()<<endl;//Guardo en el archivo
	}
	salida.close();
}
//******************************************************
int main(int argc, char *argv[]) {
	vector<string> alumnos;
	crear_lista();
	leer(alumnos,"inscriptos.txt");
	cout<<"Cantidad de Inscriptos: "<<alumnos.size()<<endl;
	for(int n=0; n<(int)alumnos.size(); n++){
		cout<<n<<" - "<<alumnos[n]<<endl;
	}
	repartir(alumnos);
	return 0;
}

