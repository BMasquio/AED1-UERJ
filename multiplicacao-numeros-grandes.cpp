#include <iostream>
using namespace std;

int main() {
	int n1, n2;
	int i;
	int j,l;
	
	cin >> n1;
	int V1[n1+1];
	for(i=1;i<=n1;i++){
		cin >> V1[i];
	}
	
	cin >> n2;
	int V2[n2+1];
	for(i=1;i<=n2;i++){
		cin >> V2[i];
	}
	
	int n3 = (n1*n2);
	int V3[n3+1];
	for(i=0;i<n3+1;i++){
		V3[i] = 0;
	}
	
	l = n1*n2;
	
	int k;
	
	for(i=n1;i>0;i--){
		for(j=n2;j>0;j--){
			l = n3 - n2 + i - n1 + j;
			
			int aux = V3[l];
			V3[l] = (V1[i]*V2[j]+V3[l]) % 10;
			V3[l-1] = ((V1[i]*V2[j]+aux)/10)+V3[l-1];
		}
	}
	
	i=1;
	while(V3[i] == 0){
		i++;
	}
	while(i < n3+1){
		cout << V3[i];
		i++;
	}
	
	return 0;
}
