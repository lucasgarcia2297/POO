#include <iostream>
using namespace std;

//Ejemplo en clases
template<typename T>
class Vector3D{
	T m_datos[3];
public:
	Vector3D();
	Vector3D(T a,T b,T c);
	T VerX() const;
	T VerY() const;
	T VerZ() const;
};
template<typename T>		//Se debe volver a declarar template para la implementacion de cada método.
Vector3D<T>::Vector3D(){ 	//Tambien se debe especificar el tipo con <T> a cada metodo
	m_datos[0] = m_datos[1] = m_datos[2] = 0;  
}
template<typename T>	
Vector3D<T>::Vector3D(T a, T b, T c){ 
	m_datos[0] = a; m_datos[1] = b;m_datos[2] = c;  
}

template<typename T>
T Vector3D<T>::VerX() const{
	return m_datos[0];
}

template<typename T>
T Vector3D<T>::VerY() const{
	return m_datos[1];
}

template<typename T>
T Vector3D<T>::VerZ() const{
	return m_datos[2];
}

template<typename T>
ostream &operator<<(ostream &o, const Vector3D<T> &v){
	o <<"(" <<v.VerX() <<" , "<<v.VerY()<< " , "<<v.VerZ()<<")";
	return o;
}
template<typename T, typename U>
Vector3D<T> operator^(const Vector3D<T> &v1, const Vector3D<U> &v2){
	Vector3D<T> i(1.0,0.0,0.0);
	Vector3D<T> j(0.0,1.0,0.0);
	Vector3D<T> k(0.0,0.0,1.0);
	auto c1 = (v1.VerY()*v2.VerZ()-v1.VerZ()*v2.VerY());
	auto c2 = (v1.VerZ()*v2.VerX()-v1.VerX()*v2.VerZ());
	auto c3 = (v1.VerX()*v2.VerY()-v1.VerY()*v2.VerX());
	
	Vector3D<T> ProdVectorial= c1*i + c2*j+ c3*k;
	return ProdVectorial;
}
template<typename U, typename T>
Vector3D<T> operator+(const Vector3D<T> &v1, const Vector3D<U> &v2){
	Vector3D<T> R(v1.VerX()+v2.VerX() , v1.VerY()+v2.VerY() , v1.VerZ()+v2.VerZ());
	return R;
}

template<typename U, typename T>
Vector3D<T> operator*(const U &escalar, const Vector3D<T> &v){
	Vector3D<T> R(escalar*v.VerX(),escalar*v.VerY(),escalar*v.VerZ());
	return R;
}

template<typename T, typename U>
T operator*(const Vector3D<T> &v1, const Vector3D<U> &v2){
	T escalar = v1.VerX() * v2.VerX() + v1.VerY()*v2.VerY() + v1.VerZ()*v2.VerZ();
	return escalar;
}
int main(int argc, char *argv[]) {
	Vector3D<int> vi(1,5,6);
	Vector3D<double> vd(-43.5,11,51.006);
	Vector3D<float> vf(0,-1,5.6);
	cout << "V = "<< vi << endl;
	cout << "W = "<< vd << endl;
	cout << "U = "<< vf << endl;
///	Equivale a:
/**	operator<< <float> (operator<<(cout,"U = "), vf)<< endl;  **/	//No hace falta el <float> porque el 
																	//compilador deduce que "vf" es de tipo float
	cout << "\nProducto por un escalar: V y escalar = 4" << endl;
	auto resultado = 4*vi;
	cout << vi << " * 4 = " << resultado << endl;
	cout << "\nProducto escalar entre: V y U" << endl;
	cout << vi << " * "<<vi<< " = " << vi*vi << endl;
	cout << "\nProducto cruz entre: V y W" << endl;
	auto ProdVectorial = (vi^vd);
	cout << vi << " x "<< vd <<" = "<< ProdVectorial << endl;
	
	return 0;
}

