#include <iostream>
#include <list>
using namespace std;

/**Cambiar los -1 por valor promedio entre el anterior y el siguiente**/
template<typename T>
void mostrar(T &L){
	for(int x:L)	cout << x << "  ";
	cout << endl;
}
int main(int argc, char *argv[]) {
	list<int> L = {1, -1, 7, 10, 15, -1, 23};
	mostrar(L);
	for( auto it=L.begin(); it!=L.end(); ++it) { 
		if(*it == -1){
			*it = ((*prev(it) + *next(it))/2);
		}
	}
	mostrar(L);
	return 0;
}

