#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Alumno{
	int N1,N2;
	string NyA;
};
void modificar(vector<Alumno> v,string nombre, int n1, int n2){
	for(size_t i=0;i<v.size();i++) { 
	if(v[i].NyA.find(nombre) != string::npos){ 	//find devuelve la posicion de uno o varios caracteres juntos
		v[i].									//npos 
	}
}

int main(int argc, char *argv[]) {
	vector<Alumno> v;
	ifstream Lista;
//	ofstream promedios;
	Alumno A;
	Lista.open("Lista.txt");
	if(Lista.is_open()){
		while(getline(Lista,A.NyA)){
		Lista >> A.N1 >> A.N2;
		v.push_back(A);
		Lista.ignore();
		}
	}
	for(size_t i=0;i<v.size();i++) { 
		cout << "Nombre: "<< v[i].NyA << endl;
		cout << "Nota 1: "<< v[i].N1<< " ";
		cout << "Nota 2: "<< v[i].N2<< endl;
	}
	Lista.close();
	
//	promedios.open("Promedios.txt");
	
	return 0;
}

