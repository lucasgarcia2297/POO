#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
//ejemplo stringstream
int main(int argc, char *argv[]) {
	vector<int> v(10);
	ifstream f;
	for(size_t i=0;i<v.size();i++) { 
		stringstream s;
		s << "Comision "<< i << ".txt";
		f.open(s.str(), ios::trunc);
		f.close();
		s.str(" ");
	}
	return 0;
}

