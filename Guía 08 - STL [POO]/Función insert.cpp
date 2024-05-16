#include <iostream>
#include <list>
using namespace std;
template<typename T>
void mostrar(T &L){
	for(int x:L)	
		cout << x << "  ";
	cout << endl;
}
int main(int argc, char *argv[]) {
	list<int> L = {1,3,5,7,9};
	mostrar(L);
	for( auto it = next(L.begin()); it!=L.end(); advance(it,2)) { 
		int prom = (*it  + *prev(it))/2;
		it = L.insert(it, prom);
	}
	mostrar(L);
	return 0;
}


