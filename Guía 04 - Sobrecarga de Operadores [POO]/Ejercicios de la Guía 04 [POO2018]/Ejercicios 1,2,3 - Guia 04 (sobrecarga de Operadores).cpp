#include <iostream>
using namespace std;
class Racional{
	float num, den;
public:
	Racional(float n=0, float d=1) : num(n), den(d) {}  //{ num = n;  den = d;}
	float VerNum()const{ return num;};
	float VerDen()const{ return den;};
	void cargarNum(const float &Numerador){
		num = Numerador;
	}
	void cargarDen(const float &Denominador){
		den = Denominador;
	}
	Racional operator+(const Racional &N)const;
	Racional operator*(const Racional &N)const;
//	Racional operator++(int);
//	Racional &operator++();
//	bool operator< (Racional const &r)const;
};
Racional Racional ::operator*(const Racional &N){
	float n,d;
	n = this->num*N.VerNum();   //puedo acceder al num mediante el metodo ver o directamente con el atributo.
	d = this->den*N.VerDen();	//debido a que pertenece a la misma clase
	Racional aux(n,d);
	return aux;
}
Racional Racional:: operator+(const Racional &N){
	Racional aux;
	aux.cargarNum(0);
	aux.cargarDen(1);
	aux.num = num*N.den+N.num*den;
	aux.den = den*N.den;
	return aux;
}
//bool Racional::&operator++(){
//	num +=den;
//	return *this;
//}

ostream &operator<<(ostream &out, Racional &N){
	out<<N.VerNum()<<"/"<<N.VerDen();  //como no pertenece a la clase debo acceder
	return out; 						//al num y den mediante los metodos VerNum() y VerDen().
}
istream &operator>>(istream &in, Racional &N){
	int a,b; 
	in >> a; N.cargarNum(a);
	in >> b; N.cargarDen(b);
	return in;
}
int main(int argc, char *argv[]) {
	Racional N1, N2, N3;
	cout << "Ingrese numerador y denominador: " << endl;
	cin >> N1;
	cout << N1<<endl;
	cout << "Ingrese numerador y denominador: " << endl;
	cin >> N2;
	cout << N2<< endl;
	cout << "Ingrese numerador y denominador: " << endl;
	cin >> N3;
	cout << N3<< endl;
	cout << "N3 = N1 + N2"<< endl;
	N3 = N1 + N2;
	cout << "N3 = "<<N3;
//	cout << N3.VerNum() << "/" << N3.VerDen()<< endl;
//	N3 = N1*N2;
//	N3 
	
	return 0;
}

