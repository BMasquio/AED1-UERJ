#include <iostream>
using namespace std;

int main() {
	int s,n;
	int cont = 0;
	
	cin >> n;
	cin >> s;
	
	int v[n];
	int i,j;
	
	for(i=0;i<n;i++){
		cin >> v[i];
	}
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(v[i]+v[j] == s){
				cout << "{" << v[i] << "," << v[j] << "}" << endl;
				cont++;
			}
		}
	}
	
	cout << cont << endl;
	
	return 0;
}
