#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;
//----------------------------------------------------------
struct persona{//El codigo en el main esta configurado para este tipo de datos
	char apeynomb[50];
	int diaNac, mesNac, anioNac;
};
//----------------------------------------------------------
//Para usar este registro hay que recodificar el main, la clase funciona igual
struct animal{
	char apeynomb[50];
	int anioNac;
};
//----------------------------------------------------------
template<class T>
class ManejadorArchivo{
	string nombreArchi;//Aqui se guardará el nombre físico del archivo
	vector<T> p;//Este arreglo cargará todos los registros del disco a memoria
public:
	ManejadorArchivo(string nArch){nombreArchi=nArch;}//Constructor
	void carga();//Metodo que permitira la carga de los registros al vector
	T buscar(string cad);//Buscara el nombre (cad) en el arreglo
	T VerReg(int x){return p[x];};//Devuelve registro en posicion x
	void guardar();//Permitira guardar el arreglo en disco;
	bool eliminar(string cad);//Elimina un nombre del arreglo y guarda en disco el vector midificado
		void agregar(T per);//Agrega un registro en el arreglo y en el archivo en disco.
	int ver_cantidad(){return p.size();}//Devuelve la cantidad de registros o posiciones del arreglo
};
//Interface -----------------------------------------------------------------------------------------
template<class T>
void ManejadorArchivo<T>::carga(){
	fstream archi_in(nombreArchi,ios::binary|ios::in);//Declaro el objeto archi_in para leer datos del archivo
		if(!archi_in.is_open()){//Si no se abrio informo del error
		cout<<"Error en apertura de archivo"<<endl;
		//cout<<"Se creara un archivo vacio"<<endl;
		fstream archi(nombreArchi,ios::binary|ios::in|ios::out|ios::trunc);
		archi.clear();//Limpio
		archi.close();//Cierro el archivo
	}else{
			archi_in.seekg(0,ios::end);//Voy con el puntero de lectura al final del archivo
			int total = archi_in.tellg()/sizeof(T);//Calculo el tamaño
			T x;//Declaro el objeto x de tipo T
			archi_in.seekg(0,ios::beg);//Vuelvo el puntero de lectura al principio
			for(int i=0;i<total;i++) {
				archi_in.read((char*)&x, sizeof(T));//cout<<cantidad<<"- "<<p[cantidad].apeynomb<<endl;//Voy mostrando lo que leo
					p.push_back(x);//Agrego el objeto x al final del arreglo p[]
			}//Fin del for de lectura de archivo
			archi_in.close();//Cierro el archivo
		}
}
//-------------------------------------------------------------------
template<class T>
T ManejadorArchivo<T>::buscar(string cad){
	T aux;//Declaro aux de tipo T
	//Es necesario que el tipo de datos T tenga el campo apeynomb
	for(int i=0;i<p.size();i++) {
		if(strcmp(p[i].apeynomb,cad.c_str())==0){//Compara nombres y si lo encuentra
			aux= p[i];//Devuelvo el struct completo
			return aux;
		}
	}//Si pasa es porque no lo encontro.
	strcpy(aux.apeynomb,"No Encontrado");//Asigno el mensaje y devuelvo el struct
	return aux;
}
//--------------------------------------------------------------------
template<class T>
void ManejadorArchivo<T>::guardar(){
	//Abro el archivo para sobreescribirlo con el arreglo de struct
	fstream archi_out(nombreArchi,ios::binary|ios::out|ios::trunc);
	if(!archi_out.is_open()){
		cout<<"Error en apertura de archivo"<<endl;
		//getchar();
	}else{
		archi_out.seekg(0,ios::beg);//Vuelvo al principio
		for(int i=0;i<p.size();i++) {
			archi_out.write((char*)&p[i], sizeof(T));
		}
		archi_out.close();//Cierro el archivo
	}
}
//--------------------------------------------
template<class T>
bool ManejadorArchivo<T>::eliminar(string cad){
	int i=0;
	while(i< p.size()) {
		if(strcmp(p[i].apeynomb,cad.c_str())==0){//Compara nombres
			break;//Si lo encuentra sale
		}else
		   i++;//Si no lo encuentra, i avanza una posicion
	}//fin del while
	if (i<p.size()){//Si salio del while e i es menor al tamaño del arreglo
		p.erase(p.begin()+i);//quiere decir que lo encontro y lo elimina
		guardar();//Guardo en disco el arreglo modificado
	}else {
		cout<<"NO Encontrado "<<cad.c_str()<<endl;}
	return 0;
}
//---------------------------------------------
template<class T>
void ManejadorArchivo<T>::agregar(T per){
	fstream archi_out(nombreArchi,ios::binary|ios::out|ios::ate);
	if(!archi_out.is_open()){
		cout<<"Error en apertura de archivo"<<endl;
		//getchar();
	}else{
		//archi_out.seekp(0,ios::end);//al final
		archi_out.write((char*)&per, sizeof(T));
		p.push_back(per);
	}
	archi_out.close();
}
int menu(){
	int op;
	cout<<"Manejador de Archivo - Configurado para Personas"<<endl;
	cout<<"1) Salir"<<endl;
	cout<<"2) Ver archivo"<<endl;
	cout<<"3) Buscar Persona"<<endl;
	cout<<"4) Guardar datos en Archivo"<<endl;
	cout<<"5) Eliminar Persona"<<endl;
	cout<<"6) Ver cantidad de personas en el archivo"<<endl;
	cout<<"7) Agregar Persona"<<endl;
	cout<<endl<<"Elija una Opcion: ";cin>>op;
	return op;
}
int main(int argc, char *argv[]) {
	ManejadorArchivo<persona> A("archivo.bin");
	A.carga();
	int opcion=0;
	while(opcion != 1){
		opcion = menu();
		switch (opcion){
		case 1: {A.guardar(); return 0;};
		break;
		case 2:{int c=0;
		for(c=0;c < A.ver_cantidad(); c++){
			cout<<"Nombre : "<<A.VerReg(c).apeynomb<<", Fecha Nac: "
				<<A.VerReg(c).diaNac<<"/"<<A.VerReg(c).mesNac<<"/"<<A.VerReg(c).anioNac<<endl;
		}
		};break;
		case 3:{persona dato,encontro;
		cout<<"Ingrese el nombre y apellido a buscar: "; cin>>dato.apeynomb;
		encontro= A.buscar(dato.apeynomb);
		if(strcmp(encontro.apeynomb, "No Encontrado") == 0){cout<<"Nombre no encontrado."<<endl;
		}else{
			cout<<"Nombre: "<<encontro.apeynomb<<endl;
			cout<<"Fecha de Nacimiento: "<<encontro.diaNac<<"/"<<encontro.mesNac <<"/"<<encontro.anioNac<<endl;
		};break;
		}//switch
		case 4:{A.guardar();};break;
		case 5:{persona dato,encontro;
		cout<<"Ingrese el nombre y apellido a Eliminar: ";
		cin.ignore();gets(dato.apeynomb);
		encontro= A.buscar(dato.apeynomb);
		if(strcmp(encontro.apeynomb,"No Encontrado")== 0){
			cout<<"Nombre no encontrado."<<endl;
		}else{
			cout<<"Nombre: "<<encontro.apeynomb<<endl;
			cout<<"Fecha de Nacimiento:"<<encontro.diaNac<<"/"<<encontro.mesNac<<"/"<<encontro.anioNac<<endl;
			A.eliminar(encontro.apeynomb);
			cout<<"ELIMINADO"<<endl;
		}};break;
		case 6:{cout<<"Cantidad de personas en al archivo: "<<A.ver_cantidad()<<endl;
		};break;
		case 7:{ persona dato;
		cin.ignore();
		cout<<"Ingrese Apellido y Nombre: "; cin.getline(dato.apeynomb,50);
		cout<<"Ingrese dia de Naciminento: "; cin>>dato.diaNac;
		cout<<"Ingrese mes de Naciminento: "; cin>>dato.mesNac;
		cout<<"Ingrese Anio de Naciminento: "; cin>>dato.anioNac;
		A.agregar(dato);};break;
		}//del switch
	}//del while
	return 0;
}
