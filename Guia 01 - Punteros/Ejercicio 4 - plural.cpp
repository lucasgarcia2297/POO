#include <iostream>
#include <cstring>
using namespace std;
void plural(char *p){ 
	char *aux=new char[25];
	int tam= strlen(p);
	strcpy(aux,p);
	switch (*(aux+tam-1)){
		case 'a':;case 'e':;case 'i':; case 'o':;case 'u':
			strcat(aux,"s");
			break; 
		default:
			strcat(aux,"es");break; }//del switch
	strcpy(p,aux); 
	delete []aux;//Libero Memoria de aux
	
}

int main(int argc, char *argv[]) {
	char *cadena= new char[20];
	
	cout<<"Ingrese cadena: ";
	cin>>(cadena);
	plural(cadena);
	
	cout<<cadena<<endl;
	
	delete []cadena;//Libero Memoria de cadena; 
	
	return 0;
}

