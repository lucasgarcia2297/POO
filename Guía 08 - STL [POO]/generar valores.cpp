#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
using namespace std;
///cargar datos en (o recorrer) un vector
int main(int argc, char *argv[]) {
	vector<int> v1(15,0);
	for(vector<int>::iterator it = v1.begin();it!=v1.end();  ++it) {   // != o < 
		*it = 1+rand()%100;
	}
		
	vector<int> v2(15,0);
	for(auto it = v2.begin(); it != v2.end(); ++it)
	auto x = 0; 	//"auto" deduce de acuerdo al tipo de elemento al que le asigne
	
	
 //.-------------------------------------------------------------
	vector<int>v(15,0);
	for( int &x : v){		//"Para cada elemento del vector"
		x = 1 + rand()%100;
	}
	//es igual a . . . 
	for( vector<int>::iterator it=v.begin(); it!=v.end(); ++it) { 
		int x = *it;
		cout << x<< endl;
	}
//.-------------------------------------------------------------
	return 0;
}

