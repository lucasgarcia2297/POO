#include <iostream>
#include <vector>
using namespace std;
struct integrante{
	string m_nom, m_ape;
	int m_edad;
};
class Equipo{
	string nom, m_dep;
	vector<integrante> v;
public:
	Equipo(int cant, string deporte, string nombre){ v.resize(cant); nom = nombre; m_dep = deporte;}
	void cargarDatos(int edad, string NomJugador, string ApeJugador){
		integrante a;
		a.m_nom = NomJugador;
		a.m_ape = ApeJugador;
		a.m_edad = edad;
		v.push_back(a);
	}
	string VerNombre() { return nom;}
	string VerDeporte() { return m_dep;}
	integrante VerJugador(int numero) { return v[numero];}
//	void cargarDatos(string nombre, string apellido, int edad){v.push_back() }
};
class EquipoFutbol : public Equipo{

public: 
	EquipoFutbol(string NombreEquipo) : Equipo(5,"Futbol", NombreEquipo){}
};

int main() {
	string nombre, apellido;
	int edad;
	EquipoFutbol EF1("C.A. River Plate");
	cout << "Datos de jugadores: "<< endl;
	for(int i=0;i<5;i++) {
		cout << "Jugador N°"<<i+1<<": "<<endl;
		cout << "Nombre: ";
		cin >> nombre;
		cout << "Apellido: ";
		cin >> apellido;
		cout << "Edad:";
		cin >> edad;
		cout << endl;
		EF1.cargarDatos(edad,nombre,apellido);
	}
	cout << endl << endl<< "----------Datos de Equipo-------"<<endl;
	cout << "Equipo de "<< EF1.VerDeporte()<<": "<<endl;
	cout << "Nombre del equipo: "<<EF1.VerNombre()<<  endl;
	cout << "Lista de jugadores: "<<endl;
	for(int i=0;i<5;i++) { 
		integrante a = EF1.VerJugador(i);
		cout << a.m_nom<<endl;
	}
	Equipo E1(5,"Basquet", "San Antonio");
	cout << endl<<E1.VerNombre();
	return 0;
}

