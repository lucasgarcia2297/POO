#include <iostream>
#include <cstring>
using namespace std;
struct alumno{ 
	char nombre[50];
	int dni, edad, calificacion;
	
}; 
//********************************************** 
alumno dni(alumno *al, int tam){ 
	alumno may=al[0];
	for(int x=0;x<tam;x++){
		if(al[x].dni>may.dni)
			may= al[x];
	} 
	return may;
} 
//********************************************** 
alumno edad(alumno *al, int tam){
	alumno may=al[0];
	for(int x=0;x<tam;x++){
		if(al[x].edad>may.edad)
			may= al[x];
	}
	return may;
} 
//**********************************************
alumno calificacion(alumno *al, int tam){
	alumno may=al[0];
	for(int x=0;x<tam;x++){ 
		if(al[x].calificacion>may.calificacion) 
			may= al[x];
	}
	return may;
} 
//********************************************** 
alumno nombre(alumno *al, int tam){ 
	alumno may=al[0]; 
	for(int x=0;x<tam;x++){ 
		if(strcmp(al[x].nombre,may.nombre) > 0) 
			may= al[x];
	}
	return may;
} 
//**********************************************
alumno buscar_mayor(alumno *al, int tam, alumno(*criterio)(alumno*, int)){ 
	alumno aa; 
	aa= (*criterio)(al,tam); 
	return aa;
}
int main(int argc, char *argv[]) { 
	alumno escuela[10];
	int largo= 5; 
	strcpy(escuela[0].nombre,"Perez Juan");
	escuela[0].dni= 11111111;
	escuela[0].edad= 20;
	escuela[0].calificacion= 8;
	//***************************************
	strcpy(escuela[1].nombre,"Silva Pepo");
	escuela[1].dni= 22222222; escuela[1].edad= 20;
	escuela[1].calificacion= 9;
	//*************************************** 
	strcpy(escuela[2].nombre,"Gonzalez Pepepo");
	escuela[2].dni= 3333333; escuela[2].edad= 21; 
	escuela[2].calificacion= 7; 
	//*************************************** 
	strcpy(escuela[3].nombre,"Gomez Kiko");
	escuela[3].dni= 44444444; escuela[3].edad= 20;
	escuela[3].calificacion= 5; 
	//***************************************
	strcpy(escuela[4].nombre,"Flores Tito"); 
	escuela[4].dni= 55555555;
	escuela[4].edad= 23;
	escuela[4].calificacion= 1; 
	//***************************************
	for(int x=0;x<largo; x++){ 
		cout<<escuela[x].nombre<<endl; 
		cout<<escuela[x].dni<<endl;
		cout<<escuela[x].edad<<endl; 
		cout<<escuela[x].calificacion<<endl; 
		cout<<"*******************************"<<endl;
	}

	int op = -1;
	while (op!=0){
		cout<<" MENU"<<endl;
		cout<<"0- Salir."<<endl;
		cout<<"1- Mayor DNI."<<endl;
		cout<<"2- Mayor Edad."<<endl; 
		cout<<"3- Mayor Calificacion."<<endl; 
		cout<<"4- Mayor Nombre."<<endl; 
		cin>>op;
		switch(op){ 
			case 1: {
				alumno MayDni= buscar_mayor(escuela,largo, dni); 
				cout<<"Mayor DNI"<<endl; 
				cout<<MayDni.nombre<<endl; 
				cout<<MayDni.dni<<endl; 
				cout<<MayDni.edad<<endl; 
				cout<<MayDni.calificacion<<endl; 
			};break;

			case 2:{
				alumno MayEdad= buscar_mayor(escuela,largo, edad); 
				cout<<"Mayor Edad"<<endl;
				cout<<MayEdad.nombre<<endl; 
				cout<<MayEdad.dni<<endl; 
				cout<<MayEdad.edad<<endl; 
				cout<<MayEdad.calificacion<<endl; 
			};break;
			case 3:{
				alumno MayCalif= buscar_mayor(escuela,largo, calificacion); 
				cout<<"Mayor Calificacion"<<endl;
				cout<<MayCalif.nombre<<endl; 
				cout<<MayCalif.dni<<endl;
				cout<<MayCalif.edad<<endl;
				cout<<MayCalif.calificacion<<endl;
			};break; 
			case 4:{
				alumno MayNombre= buscar_mayor(escuela,largo, nombre); 
				cout<<"Mayor Nombre"<<endl;
				cout<<MayNombre.nombre<<endl; 
				cout<<MayNombre.dni<<endl; 
				cout<<MayNombre.edad<<endl; 
				cout<<MayNombre.calificacion<<endl;
			};break;
		}//switch
	}//while 
	return 0;
}


