#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iterator>
using namespace std;
/**Ejercicio 01:
	Escriba un programa que permita al usuario ingresar 15 valores por teclado, los                          
	almacene en un vector y luego:	**/

int rand_100(){
	int x= rand()%100;
	return x;
}
/**	a) 	Muestre el vector generado utilizando 3 mecanismos de iteración diferentes. **/
void mostrar(vector<int> &v){
///		1. utilizando el operador [] 
//	for(int i=0;i<v.size();i++) { 
//		cout << v[i] << "   "; 
//	}
	
///		2. utilizando iteradores 
	for( vector<int>::iterator it=v.begin(); it!=v.end(); ++it) { 
		cout << *it <<"   ";
	}
	cout << endl;
	
///		3. utilizando el for basado en rangos 
//	for(int x:v)	cout << x << "  ";
//	cout << endl;
	
///		4. ¿en qué caso es conveniente utilizar cada mecanismo?

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
/**Calcule y muestre  **/
///		1. los valores de los elementos máximo y mínimo 
//	vector<int>::iterator it_max = max_element(v.begin(),v.end());
//	o tambien podria ser..
	auto it_max = max_element(v.begin(),v.end());
	cout << "El valor máximo es: "<< *it_max<< endl;
	auto it_min = min_element(v.begin(),v.end());
	cout << "El valor mínimo es: "<< *it_min<< endl;
	
///		2. la suma de todos los elementos del arreglo 
	int suma = accumulate(v.begin(),v.end(), 0);   //accumulate(InicioDelVector, FinalDelVector, ValorInicialDeLaSuma)
	cout << "La suma de los valores es: "<< suma<< endl;
	
///		3. el promedio y la mediana de los elementos del arreglo 
	float prom = suma/(v.size()*1.0);
	cout << "El promedio es: "<< prom << endl;
	sort(v.begin(),v.end());
	cout << "Vector modificado:"<<endl;
	mostrar(v);
	auto it_med = v.begin();
	advance(it_med,v.size()/2);
	cout << "La mediana es: " << *it_med<< endl;
	
/**	c)	Permita al usuario ingresar un valor, e informe si se encuentra en el vector,                            
		y en caso afirmativo, en qué posición. **/
	int valor;
	cout<<  "Ingrese un valor:"<< endl;
	cin >> valor;
	auto pos = find(v.begin(),v.end(),valor);
	if(pos != v.end()){
		cout << "Esta en la posicion: "<< distance(v.begin(),pos);
	}else
	   cout << "No se encontro el valor."<<endl;
	
	return 0;
}

