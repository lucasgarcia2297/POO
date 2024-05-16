#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;
/**
**/
void actualizar_medallero(string prim, string seg, string ter){
	
	struct S{
		int oro, plata, bronce;
		S() { oro= plata = bronce = 0;}	//creo un nuevo "pais" y le asigno las medallas en 0.
	};
	
	map<string,S> m;
	
	ifstream archi_in("medallas.txt");
	string n ; int o, p, b;
	while(archi_in >> o >> p >> b && getline(archi_in,n)){
		m[n].oro = o;
		m[n].plata = p;
		m[n].bronce = b;
	}
	archi_in.close();
	
	m[prim].oro++;
	m[seg].plata++;
	m[ter].bronce++;

	ofstream archi_out("medallas.txt", ios::trunc);
	for(auto &p:m){
		cout << p.second.oro<< " ";
		cout << p.second.plata<< " ";
		cout << p.second.bronce<< " ";
		cout << p.first<< endl;
	}


}
int main(int argc, char *argv[]) {
	string S1, S2, S3;
	actualizar_medallero(S1,S2,S3);
	cout << S1;
	
	return 0;
}

