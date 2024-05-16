#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
//	Estructura de datos para guardar todo el contenido inicial:
	struct Alumno{
		string nombre;
		float n1,n2,n3, prom;
	};
	ifstream archi_in("Notas.txt");
	vector<Alumno> v;
	Alumno aux;
	
///	--Paso 1: cargar todos los datos del archivo en el vector:--
	while(getline(archi_in,aux.nombre)){
		archi_in >> aux.n1 >> aux.n2 >> aux.n3;
		archi_in.ignore();
		v.push_back(aux);
	}
	archi_in.close();
///-------------------------------------------------------------
///	------Paso 2: trabajar con el vector-------
	for(size_t i=0;i<v.size();i++) {
		float suma = v[i].n1 + v[i].n2+ v[i].n3;
		v[i].prom = suma/3.0; 
	}
///--------------------------------------------
///	----Paso 3: Reescribir todo el archivo:----
	ofstream archi_out("Promedios.txt", ios::trunc);  //si no se especifica en ofstream por defecto es trunc
	for(size_t i=0;i<v.size();i++) { 
		archi_out << v[i].nombre << endl
			<< fixed << setprecision(2)
			<< v[i].prom << endl;
		
		cout<< "Alumno: "<<v[i].nombre<<endl;
		cout<< "Nota 1:"<<v[i].n1<<" - Nota 2:"<<v[i].n2<<" - Nota 3:"<<v[i].n3<<endl;
		cout<< "Promedio: " <<v[i].prom<<endl<<endl;
	}
	archi_out.close();	//si no lo coloco lo cierra el destructor de la clase
///--------------------------------------------
	
	
	
	return 0;
}

