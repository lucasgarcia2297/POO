#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;
void crear(string nomb, int cant){
	/*Para este caso como no tengo el archivo de puntajes voy a generarlo
	1) Creo un vector con numeros al azar.
	2) Utilizo el algotitmo sort para ordenarlo de menor a mayor
	3) Utilizo el algoritmo reverse para invertir el orden
	4) Guardo en el archivo, la lista ordenada
	5) Ahora que tengo el archivo
	*/
	string nombArchi;//Nombre del archivo fisico
	vector<double> V;//Vector que guarda el Puntaje
	nombArchi= nomb;
	fstream archi(nomb.c_str() , ios::binary |ios::in|ios::out|ios::trunc);
	if(!archi.is_open()){cout<<"E R R O R "; exit(0);};
	double f;
	for (int c=1; c<= cant; c++){
		f=(double)(rand()%10000)+100; // genera flotantes
		V.push_back(f);//Agrego al final del vector
	};// del for
	sort(V.begin(),V.end());//Ordeno el vector de meno a mayor
	reverse(V.begin(),V.end());//Invierto el orden (Mayor a Menor)
	for (int c=1; c<= cant; c++){
		archi.write(reinterpret_cast<char*>(&V[c]), sizeof(V[c]));//escribe en el archivo
	};// del for
}
//****************
class Puntaje{
	string nombArchi;//Nombre del archivo fisico
	vector<double> V;//Vector que guarda el Puntaje
public:
	Puntaje( string);//Constructor (nombre de archivo, cantidad de Puntajes)
	void agregar(double dato);//Agrega un puntaje en orden decreciente, pero no crece la lista
	void ver_puntajes();
};
Puntaje::Puntaje( string nomb){
	nombArchi= nomb;
	fstream archi(nomb.c_str() , ios::binary |ios::in|ios::out);
	if(!archi.is_open()){cout<<"E R R O R "; exit(0);};
	double f;
	V.clear();//Borro el vector
	//calculo el largo
	archi.seekp(0,ios::end);int c, largo= (archi.tellp()/(sizeof(f)));
	cout<<endl<<"Cantidad de puntajes: "<<largo<<endl;
	archi.seekg(0,ios::beg);//muevo el puntero de lectura al principio del archivo
	for(c=0; c<largo; c++){//Comienza la lectura
		archi.read(reinterpret_cast<char*>(&f), sizeof(f));
		V.push_back(f);//Agrego dato leido en el vector
		cout<<c<<" "<<setw(10)<<f<<", "<<setw(10) //Muestro
			<<", tellg(): "<<setw(10)<<archi.tellg()<<endl;
	}
	archi.close();
}
void Puntaje::agregar(double dato){
	V.push_back(dato);//Agrego el dato al final
	sort(V.begin(),V.end());//Ordeno el vector
	reverse(V.begin(),V.end());//Doy vuelta de orden
	V.pop_back();//Elimino el ultimo
	//Creo un objeto de la clase fstream para manejar el archivo binario
	fstream archi(nombArchi.c_str() , ios::binary |ios::in|ios::out|ios::trunc);
	if(!archi.is_open()){cout<<"E R R O R "; exit(0);};
	for (int c=1; c<= (int)V.size(); c++){
		archi.write(reinterpret_cast<char*>(&V[c]), sizeof(V[c]));//escribe en el archivo
	};// del for
}
void Puntaje::ver_puntajes(){
	for(int c=0; c< (int)V.size(); c++){//Comienza la lectura
		cout<<c<<" "<<setw(10)<<V[c]<<endl;
	}
}
int main(int argc, char *argv[]) {
	//Creo un objeto de la clase Puntaje
	crear("Puntaje.bin", 10);
	Puntaje P("Puntaje.bin");
	double d;
	cout<<"Ingrese puntaje a agregar: ";cin>> d;
	P.agregar(d);
	P.ver_puntajes();
	return 0;
}
