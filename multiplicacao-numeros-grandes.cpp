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
	
	int n3 = (n1*n2)+1;
	int V3[n3];
	for(i=0;i<n3;i++){
		V3[i] = 0;
	}
	
	l = n1*n2;
	
	for(i=n1;i>0;i--){
		for(j=n2;j>0;j--){
			V3[l-n1-i] += (V1[i]*V2[j]) & 10;
			V3[l-1-n1-i] += (V1[i]*V2[j]) / 10;
		}
		l = l-1;
	}
	
	for(i=1;i<(n1*n2)+1;i++){
		cout << V3[i];
	}
	
	return 0;
}