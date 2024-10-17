/*

Método russo para multiplicação de dois números

*/
#include <iostream>
using namespace std;

int main() {
	int n1,n2;
	cin >> n1;
	cin >> n2;
	
	int result = 0;
	
	while(n1 != 1){
		if(n1 % 2 == 1){
			result += n2;
		}
		
		n1 = n1/2;
		n2 = n2 * 2;
	}
	
	cout << result+n2 << endl;
	
	
	return 0;
}