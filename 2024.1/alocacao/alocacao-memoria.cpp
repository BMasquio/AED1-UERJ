#include <iostream>
using namespace std;

int main() {
	long long m = 500000000;
	int i,j;
	
	long long *V;

    int tamanhoPalavra = sizeof(long long)*8;
	
	for(i=0;i<500000;i++){
        if(i < 15){
            cout << tamanhoPalavra*i*m << endl;
            //cout << i << endl;        
        }
         
		V = new long long[m];
		//...
		//delete V;
	}
	
	
	return 0;
}
