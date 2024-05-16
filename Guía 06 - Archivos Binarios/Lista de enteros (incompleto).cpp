#include <iostream>
using namespace std;
int donde_va (fstream &archi, int valor){
	int pos = 0, n;
	archi.seekg(0,ios::end)	//end -> final - cur -> se mueve tantos byte dependiendo del  
	n = archi.tellg()/sizeof(int);
	
	int x;
	archi.seekg(pos*sizeof(int));
	archi.read(reinterpret_cast<char*> (&x), sizeof(int));
	while (pos && x<valor){
		++pos;
		archi.seekg(pos*sizeof(int));
		archi.read(reinterpret_cast<char*> (&x), sizeof(int));
	}
	return pos;
}
void insertar(fstream &archi, int valor, int pos){
	v.resize(v.size()+1)
	for(int i=v.size();-1;i--) { 
		v[i] = v[i-1];
	}
}
int main(int argc, char *argv[]) {
	vector<int> v = {}
	
	fstream archi("Datos.binario", ios::binary | ios::in | ios::out ) //| ios::trunc 	
	int valor;
	int pos = donde_va(v,valor);
	insertar(archi,valor,pos);
	fori(int x:v)
	return 0;
}

