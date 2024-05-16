#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
template<typename T>
void mostrar(T &L){
	for(int x:L)	cout << x << "  ";
	cout << endl;
}

int rand_20(){ 
//	srand(time(0));
	return rand()%20;
}

bool es_primo(int x){
	if(x==1)
	   return false;
	if(x%2==0){
		return x==2;
	} else {
		for(int i=3;i<x;i+=2) { 
			if(x%i==0) 
			return false;
		}
		return true;
	}
}

int main(int argc, char *argv[]) {
	vector<int> L(20);
	srand(time(0));
	for(int &x : L){ 
		x = rand_20();
	}
//	generate(L.begin(), L.end(), rand_20);
	cout << "-------------------------Lista Original----------------------------"<<endl;
	mostrar(L);
	cout << "-------------------------------------------------------------------"<<endl;
	
	//buscar un valor
	int valor;
	cout << "Ingresa un valor para buscar: ";
	cin >> valor;
	auto it_v = find(L.begin(), L.end(), valor);
	if(it_v == L.end()){
		cout << "No se encontro." << endl;
	}else{
		cout << "Está en la posición: "<< distance(L.begin(), it_v) << endl; 		//distancia desde el comiendzo a donde esta el 7;
		
	}
	
	//acumulador
///	retorna un valor <- accumulate(InicioDelVector, FinDelVector, ValorInicialDeLaSuma)
	float sum = accumulate(L.begin(),L.end(),0); 
	cout << "Promedio: " << sum / L.size() << endl;
	
	//El mayor y el menor
	auto it_min = min_element(L.begin(),L.end()); 	//siempre devuelve un iterador
	cout << "Minimo: "<< *it_min << endl;
	auto it_max = max_element(L.begin(),L.end());	
	cout << "Máximo: "<< *it_max << endl;
	
	
	//ordenar la lista (de menor a mayor)
	sort(L.begin(),L.end());  // para list se utiliza L.sort (funcion propia de esa clase)
	cout << "------------------Lista ordenada en forma creciente (valores menores que )-----------------"<<endl;
	mostrar(L);
	cout << "--------------------------------------------------------------------"<<endl;
	
	//La mediana 
	auto it_mean = L.begin();
	advance(it_mean, L.size()/2);
	cout << "La mediana es: "<< *it_mean << endl;
	
	
	//dar vuelta la lista
	cout << "Lista dada vuelta desde el valor: " << *L.begin() << "  hasta el elemento que esta antes de la mediana"<<endl;
//	reverse(L.begin(), L.end());
	reverse(L.begin(), it_mean);
	mostrar(L);
	cout << "--------------------------------------------------------------------"<<endl;
	
	cout << "Volver a mezclar: "<< endl;
	//volvera mezclar (no funciona para list)
	random_shuffle(L.begin(),L.end());
	mostrar(L);
	
	//contar valor
	cout << "Cantidad de ceros: " << count(L.begin(),L.end(),0) << endl;
	cout << "Cantidad de N° primos: " << count_if(L.begin(),L.end(),es_primo)<<endl; //count_if(L.begin(),L.end(),FcionBooleana);
	
//	reemplazar
	cout << "-------------Lista reemplazando los numeros primos por -1 -----------------"<<endl;
	replace_if(L.begin(),L.end(), es_primo, -1);   //reemplaza los numeros primos por -1;
	mostrar(L);
	cout << "---------------------------------------------------------------------------"<<endl;
	
//	eliminar elementos repetidos
	sort(L.begin(),L.end());   //se debe ordenar la lista primero
	cout << "------------------Lista sin elementos repetidos sin primos----------------------"<<endl;
	auto it = unique(L.begin(), L.end()); 	//unique toma un solo valor si este esta repetido de forma contigua,
											//por ello, si se desea obtener valores que no se repitan en toda la lista
											//primero se debe ordenar la lista.
											//ordena primeramente los elementos unicos y deja ultimo a los repetidos 
	L.erase(it,L.end());				//unique no elimina valores, para eliminar los valores repetidos se utiliza erase.
	mostrar(L);
	cout << "---------------------------------------------------------------------"<<endl;
	
	//elimina los elementos que son primos
	cout << "----------------------------Lista sin -1 ----------------------------"<<endl;
//	auto it2 = remove_if(L.begin(), L.end(), es_primo);
	auto it2 = remove(L.begin(), L.end(), -1);
	L.erase(it2,L.end());
	mostrar(L);
	cout << "---------------------------------------------------------------------"<<endl;
	
	
	
	return 0;
}

