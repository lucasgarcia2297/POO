#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	string NyA;
	string n1, n2;
	float p;
	ifstream archi;
	archi.open("PrimeraPrueba.txt");
	if(archi.is_open()){
		while(getline(archi,NyA)){
			archi>>n1>>n2;
			p = (n1+n2)/2.0;
			cout << NyA << " : "<< p << endl;
			archi.ignore();
		}
		
	}
	archi.close();
	return 0;
}

