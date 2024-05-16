#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	string s = "Hola mundo!";
	char aux[256];
	strcpy(aux,s.c_str());
	fstream archi("Hola Mundo.dat", ios::binary|ios::out);
	if(!archi.is_open()){
		cerr << "No se pudo abrir el archivo.";
		return 1;
	}
	else{
		archi.write(aux, sizeof(aux));
		archi.close();
	}	
	archi.open("Hola Mundo.dat", ios::binary|ios::in);
	if(!archi.is_open()){
		cerr << "No se pudo abrir el archivo.";
		return 1;
	}
	else{
		char aux2[256];
		archi.read(aux2,sizeof(aux2));
		string s2 = aux2;
		cout << s2;
		return 0;
	}
}

