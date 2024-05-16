#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
template<typename T>
void reemplazar(int pos, T x){
	archi.seekg(pos);
	archi.write(reinterpret_cast<char*> (&x), sizeof(CualquierTipo));
	return x;
}
int main(int argc, char *argv[]) {
	vector<int> v(78);
	ofstream f;
	for(size_t i=0;i<v.size();i++) { 
		stringstream s;
		s << "desing "<< i+1 << ".wds";
		f.open(s.str(),ios::binary | ios::trunc);
		f.close();
		s.str(" ");
	}
	
	string x;
	int p;
	cout << ""
	cout << ""
	
	char c[20];
	 
	
	
	return 0;
}

