#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
class Polinomio{
	private:
		int g;
		vector<float> coef;
	public:
		Polinomio(int grado=0);  //El constructor no lleva tipo y se llama igual que la clase
		void cargar_coef(int termino, float valor);
		void CambiarCoef(int g, float c);
		float EvaluarP(float x);
		Polinomio suma(Polinomio p2);
		void mostrar_pol();
};
Polinomio::Polinomio(int grado){
	g = grado;
	coef.resize(g+1,0);
}
void Polinomio::CambiarCoef(int g, float c){
	coef[g]=c;
}
void Polinomio::cargar_coef(int termino, float valor){
	if(termino<=g){
		coef[termino] = valor;
	}
}
float Polinomio::EvaluarP(float x){
	float suma = 0;
	for(size_t i=0;i<coef.size();i++){ 
		suma= suma+(coef[i]*(pow(x,i)));
	}
	return suma;
}
Polinomio Polinomio::suma(Polinomio p2){
	Polinomio res;
	int g_res; vector<float> v_menor, v_mayor;
	if(g>p2.g){
		g_res = g;
		v_menor = p2.coef;
		v_mayor = coef;
	}else{
	   g_res = p2.g;
	   v_menor= coef;
	   v_mayor = p2.coef;
	}
	   res.coef.resize(g_res+1,0);
	for(size_t i=0;i<v_menor.size();i++) { 
		res.coef[i] = v_menor[i];
	}
	for(size_t i=0;i<res.coef.size();i++) { 
		res.coef[i] = res.coef[i] + v_mayor[i];
	}
	return res;
}

void Polinomio::mostrar_pol(){
	for(size_t i=g;i>0;i--) { 
		cout << "("<<coef[i]<<"x^"<< i<<")+";
	}
}
int main(int argc, char *argv[]) {
	int grado1, grado2;
	cout << "Grado Polinomio 1: ";
	cin >> grado1;
//	cout << "Grado del polinomio 2:";
//	cin >> grado2;
	Polinomio p1(grado1);
//				 , p2(grado2);
	srand(time(0));
	for(int i=0;i<=grado1;i++) { 
		p1.cargar_coef(i,3);
	}
//	for(int i=0;i<grado2;i++) { 
//		p2.cargar_coef(i,rand()%10);
//	}
	p1.mostrar_pol();
	
	return 0;
}

