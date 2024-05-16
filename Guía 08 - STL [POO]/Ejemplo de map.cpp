#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
//	El mapa se ordena de menor a mayor
	/**crear un mapa:**/
	map<string, int> agenda;	//asocia ints a strings 
								//string es la "clave", int es el valor
	
	/**guardar datos en el mapa:**/
	agenda["Fulano"] = 15456324;    //el indice es la clave(string)
	agenda["Mengueche"] = 15415124;    
	agenda["Chuck Norris"] = 1352524;    
	agenda["Juan Perez"] = 15456535;  
	
	/**consultar un dato del mapa. si se que existe**/
	cout << "El nro de Chuck es: " << agenda["Chuck Norris"] << endl; //si no esta en la agenda se crea automaticamente
	
	/**consultar un dato cuando no se si existe**/
	auto it = agenda.find("Wally"); //si no lo encuentra retorna end()
	if(it == agebda.end())
	   cout << "No encontrado a Wally";
	else 
		cout << "Nro de Wally: " << it->second; 	//cada elemento del mapa es un struct con su clave(first) y su valor(second)
	
	for( auto it=agenda.begin(); it!=agenda.end(); ++it) { //auto es map<string, int>::iterator
		cout << it -> first << "esta asociado a " << it -> second << endl;
	}
	for(auto &p : m){
		cout << p.first << "esta asociado a " << p.second << endl;
	}
	
	agenda.size() // para saber la cantidad de3 valores
				
				
	
	
	
	return 0;
}

