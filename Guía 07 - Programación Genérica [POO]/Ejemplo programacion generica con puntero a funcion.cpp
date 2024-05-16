#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
/** Ejemplo de Puntero a Funcion**/
template<typename T, typename U>
//void muestra(vector<T> a, bool (*f)(T &a)){
void muestra(vector<T> a, U f){
	for(int i=0;i<a.size();i++) { 
		if(f(a[i]))
		   cout << a[i];
	}
}

struct Alumno{
	string ape, nom;
	int dni;
	float prom;
};
ostream &operator<<(ostream &o, Alumno &a){
	o << " Apellido y Nombre: " <<a.ape << ", "<< a.nom <<"  |  DNI: "<<a.dni<< "  |  Promedio: ";
	o << a.prom << endl;
	return o;
}

bool Aprobado(Alumno &a){ 
	return a.prom>=60.0;
}
bool Desprobado(Alumno &a){ 
	return a.prom<60.0;
}
int main(int argc, char *argv[]) {
	vector<Alumno> a = {{"Perez", "Juan", 40404903, 67.5},{"Lopez", "Hector", 40439439, 75},{"Garcia", "Ricardo", 40324230, 34.8}};
	cout << "_____________________________________Aprobados__________________________________"<< endl;
	muestra(a,Aprobado);
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "____________________________________Desprobados_________________________________"<< endl;
	muestra(a,Desprobado);
	cout << "--------------------------------------------------------------------------------"<<endl;
	return 0;
}

