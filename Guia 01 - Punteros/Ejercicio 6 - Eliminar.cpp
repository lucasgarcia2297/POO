#include <iostream>
using namespace std;
void eliminar(void *dato, int t, int pos, int tipo){
	switch (tipo){
		case sizeof(char) :{
			*((char*)dato+pos)=*((char*)dato+t-1); 
			char *aux= new char[t-1]; 
			for(int k=0;k<t-1;k++) 
				*(aux+k)= *((char*)dato+k);
			void *aux2= dato;
			dato=aux; 
			delete []aux2;
		}; break;
		case sizeof(int):{
			*((int*)dato+pos)= *((int*)dato+t-1); 
			int *aux= new int[t-1]; 
			for(int k=0;k<t-1;k++) 
				*(aux+k)= *((int*)dato+k);
			void *aux2= dato; 
			dato=aux; 
			delete []aux2;
		}; break;
		case sizeof(double) :{ 
			*((double*)dato+pos)= *((double*)dato+t-1); 
			double *aux= new double[t-1];
			for(int k=0;k<t-1;k++) 
				*(aux+k)= *((double*)dato+k);
			void *aux2= dato; dato=aux; delete []aux2;
		}; break;
	} 
}
void mostrar(void *dato, int t, int tipo){
	switch (tipo){
		case sizeof(char) :{
			for(int k=0; k<t; k++) 
				cout<<*((char*)dato+k)<<", ";
			cout<<endl; 
		}; break;
		case sizeof(int): { 
			for(int k=0; k<t; k++) 
				cout<<*((int*)dato+k)<<", ";
			cout<<endl;
		} break;
		case sizeof(double) : {
			for(int k=0; k<t; k++) 
				cout<<*((double*)dato+k)<<", ";
			cout<<endl;
		} ; break;
	}
}
	
int main(int argc, char *argv[]) { 
	int tam=5, po;
	char c[5]= {'a','b','c','d','e'}; 
	int i[5]={1,2,3,4,5}; 
	double d[5]= {10,20,30,40,50};
	
	mostrar( &c[0],tam, sizeof(char)); 
	mostrar( &i[0],tam, sizeof(int));
	mostrar( &d[0],tam, sizeof(double));
	
	cout<<"Ingrese la posicion a borrar(0-4): ";
	cin>>po;
	
	eliminar(c,tam,po, sizeof(char));
	eliminar(i,tam,po, sizeof(int));
	eliminar(d,tam,po, sizeof(double));
	tam--;
	mostrar( &c[0],tam, sizeof(char));
	mostrar( &i[0],tam, sizeof(int));
	mostrar( &d[0],tam, sizeof(double));
	
	return 0;
}

