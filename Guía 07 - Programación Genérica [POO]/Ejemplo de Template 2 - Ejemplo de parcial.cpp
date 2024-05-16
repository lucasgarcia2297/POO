#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
/**Escriba una clase generica para gestionar 
registros directamente sobre un archivo binario
La clase debe tener metodos para:
	*Obtener la cantidad de registros
	*añadir un registro 
	*consultar un registro 
	*modificar un registro
**/
template<typename T>
class ArchiBin{
	fstream archi;
public:
	ArchiBin(string ruta){
		archi.open(ruta, ios::in|ios::out|ios::binary | ios::trunc);
	}
	bool is_open(){
		return archi.is_open();
	}
	void Agregar(T x){
		archi.seekg(0,ios::end);	 
		archi.write(reinterpret_cast<char*>(&x),sizeof(x));
	}
	void Modificar(int i,T x){		// i es la posición
		archi.seekp(i*sizeof(T));	//voy al byte correspondiente a la posición i
		archi.write(reinterpret_cast<char*>(&x),sizeof(x));
/**		x.Escribir(archi) **/	/*para que pueda funcionar con string
								  .Escribir es un metodo que debería tener la  clase 
								  que utiliza strings */
	}
	T Ver(int i){  //i es la posición
/**		x.Leer(archi) **/		/*Para que pueda funcionar con string
								.Leer es un metodo que debería tener la  clase 
								que utiliza strings */
		archi.seekg(i*sizeof(T));   //voy al byte correspondiente a la posición i
		T x;
		archi.read(reinterpret_cast<char*>(&x),sizeof(x));
		return x;
	}
	int Cantidad(){
//		archi.seek(Desplazamiento, A_Partir_de_Donde);
		archi.seekg(0,ios::end);		/*para comenzar desde el final 
										(funciona como el ate)*/
//		archi.seekg(-10,ios::cur)			//para desplazarte 10 menos desde donde estoy
		int tam_bytes = archi.tellg();
		int cant = tam_bytes/sizeof(T);		//devuelve la cantidad;
		return cant;
	}
	~ArchiBin(){ archi.close();}
};
int main(int argc, char *argv[]) {
	ArchiBin<double> a("Doubles.dat");
	if(!a.is_open()){
		cerr << "No se pudo abrir el archivo.";
		return 1;
	}else{
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
		
		for(int i=0;i<a.Cantidad();i++) { 
			cout << "Posición "<<i << " -> valor: "<< a.Ver(i)<< endl;
		}
		cout <<endl <<  "Posicion a modificar: ";
		cin >> pos;
		cout << "Nuevo valor: ";
		cin >> x;
		a.Modificar(pos,x);
		for(int i=0;i<a.Cantidad();i++) { 
			cout << "Posición "<<i << " -> valor: "<< a.Ver(i)<< endl;
		}
		cout << "Cantidad de bytes: " << a.Cantidad()*sizeof(double);
		return 0;
	}
}

