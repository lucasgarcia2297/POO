#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
using namespace std;
/**Generar una lista**/
template<typename T>
void mostrar(T &L){
	for(int x:L)	cout << x << "  ";
	cout << endl;
}

int main(int argc, char *argv[]) {
//	vector<int> v;
//	for( vector<int>::iterator it=v.begin(); it!=v.end(); ++it) {   
//		v.push_back(1+rand()%100);
//	}	
//	mostrar(v);
//	int pos;
//	cin >> pos;
//	auto it = v.begin()+pos;
//	v.erase(it);
//	mostrar(v);
//	
//	
	
	list<int> L;
	for( auto it=L.begin(); it!=L.end(); ++it) { 
		L.push_back(1+rand()%100);
	}	
	mostrar(L);
	
	int pos;
	cin >> pos;
	auto it = L.begin();
	advance(it, pos);
	L.erase(it);
	
	mostrar(L);
	return 0;
}

