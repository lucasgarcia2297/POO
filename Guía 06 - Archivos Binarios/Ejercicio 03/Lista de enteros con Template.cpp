#include <iostream>
using namespace std;
template<typename CualquierTipo>
class Archivo{
	ifstream archi;
public:
	Archivo(fstream ruta) : archi(ruta, 
								 ios::binary | ios::in | ios::out){}
	int size(){
		archi.seekg(0,ios::end);
		return archi.tellg()/sizeof(CualquierTipo);
	}

	CualquierTipo leer(int pos){
		CualquierTipo x;
		archi.seekg(pos*sizeof(int));
		archi.read(reinterpret_cast<char*> (&x), sizeof(CualquierTipo));
		return x;
	}

	void escribir(int pos, CualquierTipo x){
		archi.seekg(pos*sizeof(int));
		archi.write(reinterpret_cast<char*> (&x), sizeof(CualquierTipo));
		return x;
	}
};
template<typename CualquierTipo>
int donde_va (Archivo<CualquierTipo> &a, CualquierTipo valor){
	int pos = 0;
	while (pos<a.size() && a.leer(pos)<valor)
		++pos;
	return pos;
}
	
template<typename CualquierTipo>
void insertar(Archivo<CualquierTipo> &a, CualquierTipo valor, int pos){
	int n = a.size();
	for(int i=n-1;i>pos;i--) { 
		a.escribir(i, a.leer(i-1));
		a.escribir(pos,valor);
	}
}

int main(int argc, char *argv[]) {
	Archivo<int> a("Datos.binario") 	
	int valor = 14;
	int pos = donde_va(a,valor);
	insertar(a,valor,pos);
	return 0;
}
