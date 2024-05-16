#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm>
using namespace std;
template<typename T>
void mostrar(T L){
	for(float x : L)
		cout << x << "  ";
	cout << endl;
}
float rand_100(){	
	float x= (rand()%1000/100);
	return x;
}

int main(int argc, char *argv[]) {
	int n = 6;
	list<float> L(n);
	float valor;
//	cout << "Valor: ";
//	cin >> valor;
//	while(valor != -1) { 
//		L.push_back(valor);
//		cout << "Valor: ";
//		cin >> valor;
//	}	
	srand(time(0));
	generate(L.begin(),L.end(),rand_100);
	mostrar(L);
	
	//	list<float>::iterator a, b;
	//	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it) {  
	//		a = it;
	//		b = ++it;
	//		L.insert(++it,(*(a)+*(b))/(-2.0));
	//	}
/**	b) Inserte en medio de cada par de elementos contiguos el promedio de dichos 
		elementos y guarde la lista resultante en un archivo de texto llamado “listafloat.txt”	**/
	
	list<float>::iterator it2;
	for( auto it = next(L.begin()); it!=L.end(); advance(it,2)) { 
		float prom = (*it  + *prev(it))/2.0;
		it = L.insert((it), prom);
	}
	cout << "Lista modificada: "<< endl;
	mostrar(L);
	return 0;
}

