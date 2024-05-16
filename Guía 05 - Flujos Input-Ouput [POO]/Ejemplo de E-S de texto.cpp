#include <iostream>
#include <fstream>
using namespace std;
//se recomienda guardar el programa antes de ejecutar para que
int main(int argc, char *argv[]) {
//	ofstream Archi("Primera prueba.txt", ios::app);  
//	ofstream Archi("Primera prueba.txt", ios::trunc);  
//	int a = 19;
//	Archi << "Primer valor: "<< 23+23<<endl;
//	Archi << "segundo valor: "<<a <<endl; 		
	ofstream archi;
	archi.open("Primeraprueba.txt",ios::app);
	if (!archi.is_open()){	//is_open devuelve un booleano
		archi.open("Primera prueba.txt",ios::trunc);
	}
	for(int i=0;i<20;i++) { 
		archi<< "Linea: " << i << endl;
	}
	archi.close();
	ifstream arch("Primeraprueba.txt",ios::app);
	if (!arch.is_open()){	//is_open devuelve un booleano
		arch.open("Primera prueba.txt",ios::trunc);
	}
	string a;
	for(int i=0;i<20;i++) { 
		archi>>a;
	}
	archi.close();
	return 0;
}

