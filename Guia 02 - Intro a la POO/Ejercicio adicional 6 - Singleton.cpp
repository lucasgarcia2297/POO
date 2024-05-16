#include <iostream>
using namespace std;

class Singleton { 
private: 
	static Singleton* pinstance; 
protected: 
	Singleton();
	Singleton(const Singleton & ) ; 
	Singleton &operator= (const Singleton & );
		
public:
	static Singleton* Instance();
	void setValue(int); 
	int getValue(); 
	int *i;
		
};
Singleton* Singleton::pinstance = nullptr;// Inicializar el puntero 
Singleton* Singleton::Instance (){
	if (pinstance == nullptr){ // ¿Es la primera llamada? 
		pinstance = new Singleton; // Creamos la instancia 
	}
	return pinstance; // Retornamos la dirección de la instancia
}
Singleton::Singleton(){ 
	//... Realizar inicializaciones necesarias de la instancia
	i= new int; 
}
void Singleton::setValue(int v){ 
	*i=v;
}
int Singleton::getValue(){ 
	return *i;
}
	
//*********************************************************************** 
int main(int argc, char *argv[]) {
	int valor; 
	Singleton *p1 = Singleton::Instance();
	Singleton *p2 = p1->Instance();
	Singleton &ref = * Singleton::Instance();
	cout<<"Ingrese valor para el atributo i: ";
	cin>>valor;
	p1->setValue(valor);
	cout<<"Singleton *p1 = Singleton::Instance(); "<<p1->getValue()<<endl;
	cout<<"Singleton *p2 = p1->Instance(); "<<p2->getValue()<<endl;
	cout<<"Singleton &ref = * Singleton::Instance(); "<<ref.getValue()<<endl;
	return 0;
}
