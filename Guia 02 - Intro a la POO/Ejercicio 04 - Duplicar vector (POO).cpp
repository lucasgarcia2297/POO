#include <iostream>
#include <cstdlib>
using namespace std;
class VectorDinamico{
	private:
		int* p;
		int tam;
	public:
		VectorDinamico(int t);
		~VectorDinamico();
		void duplicar();
		int VerValor(int x);
		int VerTam();
		
};
VectorDinamico::VectorDinamico(int lar){
	tam = lar;
	p = new int[tam]; //lugares continuos
	for(int i=0;i<tam;i++) { 
		*(p+i)=rand()%100;
	}
}

int VectorDinamico::VerTam(){
	return tam;
}
int VectorDinamico::VerValor(int i){
	return *(p+i);
}
void VectorDinamico::duplicar(){
	tam *= 2;
	int *aux = new int[tam];
	for(int i=0;i<(tam/2);i++) { 
		*(aux+i)=*(p+i);
	}
	for(int i=(tam/2);i<tam;i++) { 
		*(aux+i)= rand()% 100; 
	}
	delete []p; 
	p= aux; 
}
VectorDinamico::~VectorDinamico(){//Item (b) (Destructor)
	delete []p; 
}
//-Item e) Programa cliente  
int main(int argc, char *argv[]) { 
	VectorDinamico v(3); 
	cout<<"Crea el Vector Dinamico. Direccion: "<<&v<<endl; 
	for(int k= 0; k < v.VerTam(); k++) 
		cout << "V[" << k << "]= " << v.VerValor(k) << ", " << endl; 
		v.duplicar(); 
		cout<<"\nDuplicado: - Direccion: "<<&v<<endl; 
		for(int k= 0; k < v.VerTam(); k++) 
			cout<<"V["<<k<<"]= "<<v.VerValor(k)<<endl; 
			VectorDinamico x= v;//item (f) 
			cout<<endl<<"Utilizo el constructor de copia por defecto: X[] = V[] - Dirección:  "<<&x<<endl; 
				for(int k= 0; k < x.VerTam(); k++) 
					cout<<"X["<<k<<"]= "<<x.VerValor(k)<<", "; 
	return 0; 

}

