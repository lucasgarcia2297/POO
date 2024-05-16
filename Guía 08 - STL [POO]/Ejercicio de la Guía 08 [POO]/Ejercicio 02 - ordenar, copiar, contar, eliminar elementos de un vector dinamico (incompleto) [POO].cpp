#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;
///Ejercicio 02
int rand_25(){
	int x = rand()%25;
	return x;
}
void mostrar(int *v,int n){
	for(int i=0;i<n;i++) {  	
		cout <<setw(5)<<v[i];
	}
	cout << endl;
}
int main(int argc, char *argv[]) {
	int n = 30;
	int *v = new int [n];
	srand(time(0));
	generate(v+0, v+n, rand_25);  // v+0 = begin()  y  v+30 = end()
	mostrar(v,n);
	
	cout << "---------------Vector modificado:-----------------------" << endl;
	sort(v+10, v+21);
	mostrar(v,n);
	cout << "--------------------------------------------------------" << endl;
	
	cout << "2do Vector: "<<endl;
	int *v2 = new int[10];
	copy(v+10,v+21,v2);    //copia los valores desde v+10 hasta v+21 y se lo asigna a v2;
	mostrar(v2,10);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	delete [] v;
	for(int i=0;i<n;i++) { 
		int *x = v+i;
		x = nullptr;
		delete x;
	}
	return 0;
}

