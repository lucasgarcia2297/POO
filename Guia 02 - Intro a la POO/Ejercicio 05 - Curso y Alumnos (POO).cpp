#include <iostream>
#include <cstring>
using namespace std;
struct Alumno{
	char nombre[40];
	float nota;
};
class Curso{
private:
	string nombre_curso; //nombre del Curso 
	int cantidad; //cantidad de alumnos cargados 
	Alumno *clase; //Arreglo de struct de Alumnos
public:
	Curso(string nom); //Crea una instancia de 40 Alumnos vacía 
	~Curso(); //Elimina la estructura creada 
	void cargar(Alumno al); //Añade el struct al arreglo y cuenta 1 en cantidad 
	Alumno ver_arreglo(int pos); //Devuelve el alumno en la posición 
	int ver_cantidad(){return cantidad;}; //Devuelve cantidad cargada 
	string ver_nombre(){return nombre_curso;}; 
	double promedio(); //Devuelve el promedio del Curso 
	Alumno max(); //Devuelve el alumno con más nota
};


Curso::Curso(string nombre){
	nombre_curso = nombre;
	cantidad = 0;
	clase = new Alumno[40];
	for(int i=0;i<40;i++) { 
		(clase+i)->nota = 0;   //en arreglos dinamicos no se utiliza el punto
							   //sino la flecha -> 
							   //(clase+i) es el puntero clase, como i es un
							   //un entero, ocupa 4 bytes; 
	}
}
Curso::~Curso(){ 
	delete []clase; //Elimina la estructura creada
}
void Curso::cargar(Alumno al){ //Añade el struct al arreglo y cuenta 1 en cantidad 
	*(clase+cantidad)= al; 
	cantidad++;
}

Alumno Curso::ver_arreglo(int pos){ 
	//Devuelve el alumno en la posición 
	return *(clase+pos);
}
double Curso::promedio(){ //Devuelve el promedio del Curso 
	int x;
	double prom=0; 
	for(x=0; x < cantidad; x++){ 
		prom += (clase+x)->nota;
	}
	prom/=cantidad; 
	return prom;
}
Alumno Curso::max(){ //Retorna el struct con la mayor nota 
	Alumno *max= clase;
	int x; 
	for(x=0; x < cantidad; x++){
		if(((clase+x)->nota)>(max->nota)) 
			max= (clase+x);
	}
	return *max;
}
void mostrar(Curso D){ 
	Alumno aux1; 
	cout<<"Materia: "<<D.ver_nombre()<<endl;
	for(int x=0; x<D.ver_cantidad(); x++){
		aux1= D.ver_arreglo(x);
		cout<<aux1.nombre<<" - "<<aux1.nota<<endl;
	}
}
int main(int argc, char *argv[]) { 
	Curso C("UNL-FICH-POO");
	Alumno aux; 
	strcpy(aux.nombre,"Jose");
	aux.nota= 9; 
	C.cargar(aux);
	strcpy(aux.nombre,"Carlos");
	aux.nota= 6; 
	C.cargar(aux); 
	strcpy(aux.nombre,"Marcelo");
	aux.nota= 10; 
	C.cargar(aux); 
	mostrar(C); 
	cout<<"Promedio del curso: "<<C.promedio()<<endl; 
	aux= C.max();
	cout<<"Mejor Promedio: "<<aux.nombre<<" - "<<aux.nota<<endl;
	return 0;
}
