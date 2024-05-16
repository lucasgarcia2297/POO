#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
/**Ejercicio 01**/

int rand_100(){
	int x = rand()%100;
	return x;
}
void mostrar(vector<int> &v){
//	for(int x:v)	cout << x << "  ";
//	cout << endl;
	for( vector<int>::iterator it=v.begin(); it!=v.end(); ++it) { 
		cout << *it <<"   ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	vector<int> v(10);
	srand(time(0));
	generate(v.begin(), v.end(), rand_100);
//	for(int i=0;i<15;i++) { 
//		valor = rand()%100;
//		v.push_back(valor);
//		cout << "v["<< i << "] = "<< valor;
//	}
//	
//	
//	for(int &x: v){
//		cout << x << endl;
//	}
	cout << "Vector original:"<<endl;
	mostrar(v);
	cout << endl;
//	vector<int>::iterator it_max = max_element(v.begin(),v.end());
//	o tambien podria ser..
	auto it_max = max_element(v.begin(),v.end());
	cout << "El valor máximo es: "<< *it_max<< endl;
	auto it_min = min_element(v.begin(),v.end());
	cout << "El valor máximo es: "<< *it_min<< endl;
	
	int suma = accumulate(v.begin(),v.end(), 0);   //accumulate(InicioDelVector, FinalDelVector, ValorInicialDeLaSuma)
	cout << "La suma de los valores es: "<< suma<< endl;
	
	float prom = suma/(v.size()*1.0);
	cout << "El promedio es: "<< prom << endl;
	
	
	sort(v.begin(),v.end());
	cout << "Vector modificado:"<<endl;
	mostrar(v);
	auto it_med = v.begin();
	advance(it_med,v.size()/2);
	cout << "La mediana es: " << *it_med<< endl;	
	return 0;
}

