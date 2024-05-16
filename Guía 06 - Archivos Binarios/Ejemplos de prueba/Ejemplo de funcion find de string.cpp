#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string frase = "Ser el elegido es como estar enamorado.";
	string silaba;
	cout << "Ingrese un silaba: ";
	cin >> silaba;
	
	int cant = 0;
	size_t p = frase.find(silaba,0);
	while (p!=string::npos){
		cant++;
		p = frase.find(silaba, p+silaba.size());
	}
	cout << "La silaba está "<< cant << " veces." << endl;
	return 0;
}

