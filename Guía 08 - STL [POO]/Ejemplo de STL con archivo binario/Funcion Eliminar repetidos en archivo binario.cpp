#include <iostream>
using namespace std;

/**escriba una funcion que reciba el nombre de un archivo binario que contenga un
**/
template<typename T>
int elimina_reps(string nom_arch){
	ifstream archi_in(nom_arch, ios::binary | ios::ate);
	int n = archi_in.tellg()/sizeof(T); //tamao del archivo
	archi_in.seekg(0);
	
	vector<T> v(n);
	for(T &x:v){
		archi_in.read(reinterpret_cast<char*>(&x), sizeof(T));
	}
	archi_in.close();
	
//---si no quiero mantener el orden-----------------
	sort(v.begin(),v.end());
	auto it = unique(v.begin(),v.end()); 	//como tercer parametro puedo pasarle otra condicion para que compare
											//si no coloco nada compara con ==
								//unique no elimina, solo ordena los elementos (primero los elementos no repetidos)
								//retorna un iterador al primer elemento donde empiezan los repetidos
								//funciona correctamente si el vector esta ordenado
	int cant = distance(it, v.end());
//	int cant = v.end()-it ;	
	v.erase(it, v.end());
//	v.resize(it - v.begin());
	
//--------------------------------------------------
//	para mantener el orden (no hay algun algoritmo stl)
	
/*	int cant = 0;
	for( vector<T>::iterator it=v.begin(); it!=v.end(); ++it) { 
		auto it2 = remove(next(it),v.end(),*it)  //el primer valor no lo borra, borra a partir del repetido
		cant+=v.end()-it2;
	}
	v.erase(it2,v.end()); //si no es vector, coloco el erase fuera del for.	
*/
	
	int cant = 0;
	for(int i=0;i<v.size();i++) { 
		auto it2 = remove(v.begin()+i+1,v.end(),v[i])  //el primer valor no lo borra, borra
		cant += v.end()-it2;
		v.erase(it2,v.end());  //de esta forma 	
	}
	

	ofstream archi_out(nom_arch, ios::binary | ios::trunc);
	for(T &x:v){
		archi_out.write(reinterpret_cast<char*> (&x), sizeof(T));
	}
	archi_out.close(); 	//si no lo cierro se 
	return cant;
//	return n-v.size();
}

//un struct que utilice string no puedo utilizarlo en la funcion anterior porque utilizo archivos binarios
struct Alumno{
	char nombre[50], apellido[50];
	int dni;
	float prom;
};

int main(int argc, char *argv[]) {
	vector<int> v = {3,4,1,2,2,4,4,1,5,7};
	
	return 0;
}

