#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class ConfigFile{
	struct Par{
		string campo, valor;
	};	
	vector<Par> m_datos;
	string m_ruta_archivo;
public:
	ConfigFile(string ruta_archivo){ 
		m_ruta_archivo = ruta_archivo;
		ifstream archi(m_ruta_archivo);
		string Linea;
		while(getline(archi,Linea)){
			if(Linea.empty() || Linea[0] == '#') //empty para saber si la linea esta vacia: equivale a "Linea.size()==0"
			continue;
			size_t pos = Linea.find("=");
			if(pos==string::npos){   //npos es un valor que lo da el SO
				cout << "Ha ocurrido un error. "<<endl;
				return;
			}
			Par p;
			p.campo = Linea.substr(0,pos);	//para 
			p.valor = Linea.substr(pos+1/**,Linea.size()-(pos+1)**/) //si no se coloca nada mas ;
			m_datos.push_back(p);
			}
			
		}
	}
	string Ver(string campo){
		for(size_t i=0;i<m_datos.size();i++) { 
			if(m_datos[i].campo == campo)
			   return m_datos[i].valor
		}
//		for(Par p : m_datos){
//			if(p.campo == campo){
//				return p.valor;
//			}
//		}
	}
	void Modificar(string campo, string nuevo_valor){
		
		for(size_t i=0;i<m_datos.size();i++) { 
			if(m_datos[i].campo == campo)
			   return m_datos[i].valor
		}
	}
	bool Guardar(){
		ofstream archi(m_ruta_archivo);
		if(!archi.is_open()) 
		   return false;
		for(int i=0;i<m_datos.size();i++) { 
			archi << m_datos[i].campo << "="<<m_datos[i].valor<< endl;
		}		
			 
	}
};
int main(int argc, char *argv[]) {
	ConfigFile Archi("Ejercicio 04.txt");
	if
	cout << "Univer: " << datos.Ver("universidad")<<endl;
	cout << "Facu: " << datos.Ver("facultad")<<endl;
	cout << "Carrera: " << datos.Ver("carrera")<<endl;
	cout << "Materia: " << datos.Ver("materia")<<endl;
	
	cin.get();
	cout << "Unidad: "<< datos.Ver("unidad")<<endl;
	cout << "Nombre: "<< datos.Ver("nombre")<<endl;
	cout << "Dificultad: "<< datos.Ver("dificultad")<<endl; //s3e puede ir agregando datos que no existan
	cin.get();
	
	
	
	return 0;
}

