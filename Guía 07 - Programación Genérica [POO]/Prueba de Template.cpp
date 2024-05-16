#include <iostream>
#include <vector>
using namespace std;
template<typename T, typename U>
U promedio(const vector<T> &v){
	T suma = 0;
	for(size_t i=0;i<v.size();i++) { 
		suma += v[i];
	}
	U prom = suma/(v.size()*1.0);
	return prom;
}
int main(int argc, char *argv[]) {
	vector<int> v;
	int n;
	cout << "Valor: ";
	cin >> n;
	while(n>=0){
		v.push_back(n);
		cout << "Valor: ";
		cin >> n;
	}
	float prom = promedio<int, float>(v);
	cout << "\nEl promedio es: "<< prom;
	
		  
	return 0;
}

