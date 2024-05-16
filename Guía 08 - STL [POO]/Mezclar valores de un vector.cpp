#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T>
void mostrar(T &L){
	for(int x:L)	cout << x << "  ";
	cout << endl;
}
int main(int argc, char *argv[]) {
	vector<int> v = {2, 34, 42, 45, 12, 1, 4};
	sort(v.begin(),v.end());
	mostrar(v);
	//volvera mezclar (no funciona para list)
	random_shuffle(v.begin(),v.end());
	mostrar(v);
	return 0;
}

