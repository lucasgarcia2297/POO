#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
struct Par{
	int i;
	double d;
};
Par rand_100(){
	Par p;
	p.i = rand()%100;
	p.d = (rand()%10000)/100.0;
	return p;
}
//template<typename T>
//void cargar_archivo(T v, fstream archi){
//	
//}
int main(int argc, char *argv[]) {
	vector<Par> v(15);
	fstream archi("Mayor.bin", ios::binary|ios::in|ios::out|ios::trunc);
	if(!archi.is_open()){
		cerr << "NO se pudo abrir el archivo." << endl;
		return 1;
	}
	else{
		srand(time(0));
		generate(v.begin(),v.end(), rand_100);
		cout << "Valores cargados: "<< endl;
		for(size_t i=0;i<v.size();i++) { 
			Par p;
			p.i = v[i].i;
			p.d = v[i].d;
			archi.write(reinterpret_cast<char*>(&p),sizeof(Par));
			cout <<setw(6)<<left<<"Par N°"<< setw(2)<<right<<i <<":"<<setw(5)<<right<< p.i << "  y  " <<setw(5)<< p.d <<endl;
		}
//		cargar_archivo(v,archi);
		archi.close();
	}
	
	archi.open("Mayor.bin", ios::binary|ios::in|ios::out|ios::ate);
	if(!archi.is_open()){
		cerr << "NO se pudo abrir el archivo." << endl;
		return 1;
	}
	else{
		int tam_bytes = archi.tellg();
		int cant_pares = tam_bytes/sizeof(Par);
		cout << "\nCantidad de Bytes: "<< tam_bytes<< endl;
		cout << "Cantidad de Pares: "<< cant_pares << endl;
		archi.seekg(0);
		int may_int = 0, posMayor;
		for(int j=0;j<cant_pares;j++) { 
			Par pa;
			archi.read(reinterpret_cast<char*> (&pa), sizeof(Par));
			if(pa.i > may_int){
				may_int = pa.i;
				posMayor = j*sizeof(pa);
				//	posMayor = archi.tellg()-sizeof(p);
			}
		}	
		archi.seekp(posMayor);
		Par p1 = {0,0};
		archi.write(reinterpret_cast<char*> (&p1), sizeof(Par));
		cout << "El entero mayor es: "<< may_int;
		cout << " y empieza en el byte número: "<< posMayor<< endl;
		cout << "Par N°" << posMayor/sizeof(Par)<< endl << endl;
		archi.seekg(0);
		cout << "Valores con el mayor modificado:"<<endl;
		for(int i=0;i<cant_pares;i++) {
			Par valores;
			archi.read(reinterpret_cast<char*> (&valores), sizeof(Par));
			cout <<setw(6)<<left<<"Par N°"<< setw(2)<<right<< i <<":"<<setw(5)<<right<< valores.i << "  y  " <<setw(5)<< valores.d <<endl;
		}
		archi.close();
		return 0;
	}
}

