#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;
/**Ejercicio 02:
	Escriba un programa que defina un vector dinámico de 30 enteros aleatorios                        
	menores que 25. Luego: 
**/
int rand_25(){
	int x = rand()%25;
	return x;
}
void mostrar(int *v,int n){
	for(int i=0;i<n;i++) {  	
		cout <<"v["<<i<<"] = " <<v[i]<< endl;
	}
	cout << endl;
}
int main(int argc, char *argv[]) {
	int n = 30;
	int *v = new int [n];
	srand(time(0));
	generate(v+0, v+n, rand_25);  // v+0 = begin()  y  v+30 = end()
	mostrar(v,n);
	
/**	a) 	Ordene en forma descendente los elementos ubicados entre las posiciones                    
		10 y 20 inclusive, y muestre el vector	**/
	cout << "---------------Vector modificado:-----------------------" << endl;
	sort(v+10, v+20);
	reverse(v+10, v+20);
	mostrar(v,n);
	cout << "--------------------------------------------------------" << endl;
	
/**	b) Inserte en un nuevo vector los elementos que fueron ordenados en el                        
		apartado anterior, y quítelos del vector original. **/
	cout << "2do Vector: "<<endl;
	int *v2 = new int[10];
	copy(v+10,v+20,v2);    //copia los valores desde v+10 hasta v+21 y se lo asigna a v2;
	mostrar(v2,10);
	cout << "vector 1 acortado:" << endl;
	int *aux = new int[n-10];
	copy(v,v+11,aux);
	copy(v+20,v+n,aux+10);
	delete [] v;
	n = n-10;
	v = new int[n];
	copy(aux,aux+n,v);
	delete [] aux;
	mostrar(v,n);	 
	
/**	c)	Permita ingresar un valor por teclado, y muestre cuántas veces aparece                      
		dicho valor en el vector. 	**/
	int valor;
	cout << "Ingrese un valor para buscar: ";
	cin >> valor;
	int cant = count(v,v+n,valor); 
	cout << "El valor aparece " << cant << " veces."<<endl;
	
/**	d)	Elimine todas las ocurrencias del valor ingresado en el punto c, utilizando la                          
		función remove. Responda: ¿Pueden las funciones globales de la STL                    
		eliminar realmente los elementos (liberando la memoria de un contenedor)? **/
	n = n-cant;
	for(int i=0;i<cant;i++) { 
		remove(v,v+n+cant,valor);
	}
	cout << "Vector sin valor ingresado: "<<endl;
	mostrar(v,n);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	delete [] v;
	for(int i=0;i<n;i++) { 
		int *x = v+i;
		x = nullptr;
		delete x;
	}
	delete [] v2;
	return 0;
}

