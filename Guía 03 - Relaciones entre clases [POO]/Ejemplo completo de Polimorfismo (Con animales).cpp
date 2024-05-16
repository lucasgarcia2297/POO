#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/**Solo con la clase abstracta y la funcion **/
//-----------clase abstracta por tener al menos un metodo virtual puro--------------------
class Animal {   
	string m_nombre, m_especie;
public:
	Animal(string especie, string  nombre){
		m_especie = especie; 
		m_nombre = nombre;
	}
	string VerNombre(){ return m_nombre; }
	string VerEspecie(){ return m_especie; }
	virtual string Hablar() = 0;				//metodo virtual puro
	virtual string HacerGracia() { return "no hace nada";}	//metodo virtual pero no puro
	virtual ~Animal() {} /**el destructor debe ser virtual para que cuando se vaya a destruir
						  desde un puntero de clase hija se destruya todo el animal y
						  no solo la parte de la clase hija**/
};
//--------------------------------------------------------------------------------------
//----------Aca es donde se van a ejecutar las acciones----------------
void gran_funcion_que_hace_cosas_interesantes(vector<Animal*> &v){
	srand(time(0));
	do{
		int i = rand()%v.size();
		cout << "El "<<v[i]->VerEspecie()
			<<	" " << v[i]->VerNombre() << " dice "
			<< v[i]->Hablar() << " y "
			<< v[i]->HacerGracia() << endl;
	}while(cin.get()=='\n');  //continua mientras se pulsa enter
}
//----------------------------------------------------------------------
class Conejo : public Animal {
public:
	Conejo(string nombre) : Animal("Conejo", nombre) {}
	string Hablar() {return "Que hay de nuevo viejo?";}
	string HacerGracia() override { return "muerde una zanahoria";}
};
class Gato : public Animal {
public:
	Gato(string nombre) : Animal("gato", nombre) {}
	string Hablar() {return "miau!";}
};

class TortugaNinja : public Animal {
public:
	TortugaNinja(string nombre) : Animal("tortuga", nombre) {}
	string Hablar() {return "kawabunga!";}
	string HacerGracia() override { return "come pizza";}
};
class Pulga{
	
};
class Perro : public Animal {
	Pulga *v;
public:
	Perro(string nombre) : Animal("perro", nombre) {
		v= new Pulga[200];
	}
	string Hablar() {return "guauu!";}
	string HacerGracia() override { return "da la patita y mueve la cola";}
	~Perro(){
		cout << "El perro se sacude las pulgas. . ."<< endl; 
		delete [] v;
	}
};

class Oso : public Animal {
public:
	Oso(string nombre) : Animal("oso", nombre) {}
	string Hablar() {return "Skadoosh!";}
	string HacerGracia() override { return "baja el meñique derecho";}
};
int main(int argc, char *argv[]) { 
	
	vector<Animal*> v;
	v.push_back(new Perro("Coraje"));
	v.push_back(new Perro("Firulais"));
	v.push_back(new Gato("Bola de Nieve"));
	v.push_back(new TortugaNinja("Donatello"));
	v.push_back(new TortugaNinja("Michelangelo"));
	v.push_back(new TortugaNinja("Rafael"));
	v.push_back(new TortugaNinja("Leonardo"));
	v.push_back(new Oso("Po"));
	v.push_back(new Conejo("Bugs"));
	gran_funcion_que_hace_cosas_interesantes(v);
	
//	for(Animal *p:v) delete p;  //Animal *p:v significa que "Para cada puntero del vector se ejecute la accion siguiente (delete p)"
	for(size_t i=0;i<v.size();i++) { 
		Animal *p = v[i];
		delete p;
	}
	return 0;
}

