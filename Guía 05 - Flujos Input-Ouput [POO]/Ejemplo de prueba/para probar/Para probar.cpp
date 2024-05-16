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
	vector<Alumno> v;
	ifstream archi_in("Promedios.txt",ios::binary| ios::in);
	if(!archi_in.is_open()){
		cout << "No se pudo abrir";
		return 1;
	}else{
	Alumno aux;
	
	///	--Paso 1: cargar todos los datos del archivo en el vector:--
	while(getline(archi_in,aux.nombre)){
		archi_in >> aux.n1 >> aux.n2 >> aux.n3;
		archi_in.ignore();
		v.push_back(aux);
	}
	archi_in.close();}
	///-------------------------------------------------------------
	///	------Paso 2: trabajar con el vector-------
	for(size_t i=0;i<v.size();i++) {
		float suma = v[i].n1 + v[i].n2+ v[i].n3;
		v[i].prom = suma/ v.size(); 
	}
	///--------------------------------------------
	///	----Paso 3: Reescribir todo el archivo:----
	ofstream archi_out("Promedios.txt", ios::binary|ios::trunc);  //si no se especifica en ofstream por defecto es trunc
	if(!archi_out.is_open()){
		cout << "No se abrio capo.";
		return 1;
	}else{
	for(size_t i=0;i<v.size();i++) { 
		archi_out << v[i].nombre << endl
			<< fixed << setprecision(2)
									 << v[i].prom << endl;
	}
	archi_out.close();}	//si no lo coloco lo cierra el destructor de la clase
	///--------------------------------------------
	
	
	
	return 0;
}

