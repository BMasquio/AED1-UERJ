#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string s;
	
	int n = 152;
	string V[n];
	
	for(i=0;i<n;i++){
		V[i] = "";
	}
	
	int t;
	cin >> t;
	
	for(i=0;i<t;i++){
		cin >> s;
		j=0;
		bool jaCapturado = false;
		while(V[j] != ""){
			if(V[j] == s) jaCapturado = true;
			j++;
		}
		if(!jaCapturado){
			V[j] = s;
		}
	}
	
	j=0;
	while(V[j] != ""){
		//cout << V[j] << endl;
		j++;
	}
	
	cout << "Falta(m) " << 151-j << " pomekon(s).";
	
	return 0;
}
