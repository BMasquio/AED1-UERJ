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
	
	
	i=0; j=n-1;
	while(i < j){
		int soma = v[i]+v[j];
		
		cout << "i = " << i << ", " << "j = " << j << endl;
		
		if(soma == s){
			//cout << "{" << v[i] << "," << v[j] << "}" << endl;
			cont++; i++; j--;
		}else{
			if(soma > s){
				j--;
			}else{
				i++;
			}
		}
	}
	
	
	
	
	cout << cont << endl;
	
	return 0;
}
