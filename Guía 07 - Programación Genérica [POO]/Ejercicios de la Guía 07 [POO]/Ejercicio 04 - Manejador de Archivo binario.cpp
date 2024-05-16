#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
/**Ejercicio 4 (Guía 7):
	Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos
	y atributos para manipular un archivo binario que contenga registros del tipo de
	dato especificado por el parámetro. La clase debe poseer métodos para:
**/
template<typename T>
class ManejadorArchivo{
	string M_NomArchi;
	vector<T> v;
public:
	ManejadorArchivo(string nombre){ 
		M_NomArchi = nombre;
	}
	int VerCantidad(){ return v.size();}
	
///	a) Abrir un archivo binario y cargar los registros en memoria.
	void Cargar(){
		ifstream archi_in(M_NomArchi, ios::binary|ios::ate);
		if(!archi_in.is_open()){
			cerr << "No se pudo abrir el archivo.";
			fstream archi(M_NomArchi,ios::binary|ios::trunc|ios::in|ios::out);
			archi.clear();
			archi.close();
		}else{
			T x;
			int total = archi_in.tellg()/sizeof(T);
			archi_in.seekg(0);
			for(int i=0;i<total;i++) { 
				archi_in.read(reinterpret_cast<char*>(&x), sizeof(x));
				v.push_back(x);
			}
			archi_in.close();
		}
	}
///	b) Obtener el registro en una posición especificada por el usuario.
	T VerRegistro(int i){ return v[i];}
///	c) Modificar el registro en una posición determinada.
	void Modificar(int i, T y){
		v[i] = y;
//		ofstream archi_out(M_NomArchi, ios::binary);
//		archi_out.seekp(i*sizeof(T));
//		archi_out.write(reinterpret_cast<char*>(&y), sizeof(T));
		Guardar();
//		archi_out.close();
	}
///	d) Actualizar la información del archivo con los cambios.
	void Guardar(){
		ofstream archi(M_NomArchi,ios::binary|ios::trunc);
		for(auto &x: v){
			archi.write(reinterpret_cast<char*>(&x), sizeof(x));
		}
		archi.close();
	}
// 	Otros métodos para probar el programa:
	void Agregar(T x){
		v.push_back(x);
		Guardar();
	}
	int VerCantidadBytes(){
		ifstream archi(M_NomArchi,ios::binary|ios::ate);
		return archi.tellg();
	}
	void Eliminar(size_t i){
		if(i>=v.size()){
			cerr << "ERROR: Posición no correspondiente.";
		}else{
			v.erase(v.begin()+i);
			cout << "ELIMINADO.";
		}
	}
	void EliminarTodo(){
		v.clear();
	}
};
//Struct para probar un nuevo tipo de dato:
struct persona{//El codigo en el main esta configurado para este tipo de datos
	char apeynomb[50];
	int diaNac, mesNac, anioNac;
};
//Una funcion "menu" para ingresar una opcion:
int menu(){
	int op;
	cout<<"Manejador de Archivo - Configurado para Personas"<<endl;
	cout<<"1) Agregar registro."<<endl;
	cout<<"2) Modificar registro."<<endl;
	cout<<"3) Eliminar registro."<<endl;
	cout<<"4) Eliminar todo."<<endl;
	cout<<"5) Deshacer acción."<<endl;
	cout<<"6) Ver registros."<<endl;
	cout<<"7) Ver cantidad de registros en el archivo."<<endl;
	cout<<"8) Guardar datos en Archivo."<<endl;
	cout<<"9) Propiedades del Archivo."<<endl;
	cout<<"9) Salir."<<endl;
	cout<<endl<<"Elija una Opcion: ";cin>>op;
	return op;
}
/**	e) Utilice la clase desde un programa cliente para leer los registros escritos en
el archivo binario.**/
int main() {
	ManejadorArchivo<persona> A("Datos.dat");
	A.Cargar();
	int opcion=0;
	while(opcion != 7){
		opcion = menu();
		switch (opcion){
		
		case 1:{ persona dato;
		cin.ignore();
//		char ApeyNom[50];
//		strcpy(ApeyNom,dato.apeynomb.c_str());
		cout<<"Ingrese Apellido y Nombre: "; cin.getline(dato.apeynomb,50);
		cout << "Tamaño char: " << sizeof(dato.apeynomb)<<endl;
		cout<<"Ingrese dia de Naciminento: "; cin>>dato.diaNac;
		cout<<"Ingrese mes de Naciminento: "; cin>>dato.mesNac;
		cout<<"Ingrese Anio de Naciminento: "; cin>>dato.anioNac;
		A.Agregar(dato);};
		break;
		
		case 2:{persona aux;
		int pos;
		cout << "Ingrese la posición de un registro que desea reemplazar: ";
		cin >> pos;
		cin.ignore();
		cout << "------Datos del nuevo registro------" << endl;
		cout<<"Ingrese Apellido y Nombre: "; cin.getline(aux.apeynomb,50);
		cout<<"Ingrese dia de Naciminento: "; cin>>aux.diaNac;
		cout<<"Ingrese mes de Naciminento: "; cin>>aux.mesNac;
		cout<<"Ingrese Anio de Naciminento: "; cin>>aux.anioNac;
		A.Modificar(pos,aux);
		};break;
		
		case 3:{size_t pos;
		cout << "Ingrese la posición de un registro que desea eliminar: ";
		cin >> pos;
		A.Eliminar(pos);
		};break;
		case 4:{
			A.EliminarTodo();
		};break;
		case 5:{
			A.Cargar();
		};break;
		
		case 6:{int c=0;
		cout << "\n---------------Lista de Registros-------------------"<<endl;
		for(c=0;c < A.VerCantidad(); c++){
			cout<<"Nombre : "<<A.VerRegistro(c).apeynomb<<", Fecha Nac: "
				<<A.VerRegistro(c).diaNac<<"/"<<A.VerRegistro(c).mesNac<<"/"<<A.VerRegistro(c).anioNac<<endl;
		}};break;
		
		case 7:{cout<<"Cantidad de personas en al archivo: "<<A.VerCantidad()<<endl;
		};break;
		
		case 8:{A.Guardar();
		cout << "Se guardo correctamente"<<endl;};break;
		
		case 9:{
			cout << "Tamaño del archivo: "<< A.VerCantidadBytes() <<endl;
		};break;
		
		case 10: {A.Guardar(); return 0;};
		break;
		
		}//del switch
	}//del while
	
	
	
/*	ManejadorArchivo<double> a("Doubles.dat");
	double x;
	int pos, cant;
	cout << "Cantidad de datos del archivo: "<<endl;
	cin >> cant;
	srand(time(0));
	for(int i=0;i<cant;i++) {  
		x = (-1+rand()%3);
		if(x == 0)
			x = rand()%10000000/100.0;
		else
			x = (rand()%10000000/100.0)*x;
		a.Agregar(x);
	}
	
	for(int i=0;i<a.VerCantidad();i++) { 
		cout << "Posición "<<i << " -> valor: "<< a.VerRegistro(i)<< endl;
	}
	cout <<endl <<  "Posicion a modificar: ";
	cin >> pos;
	cout << "Nuevo valor: ";
	cin >> x;
	a.Modificar(pos,x);
	for(int i=0;i<a.VerCantidad();i++) { 
		cout << "Posición "<<i << " -> valor: "<< a.VerRegistro(i)<< endl;
	}
	cout << "Cantidad de bytes: " << a.VerCantidad()*sizeof(double);*/
	return 0;
}

