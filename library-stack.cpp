#include <iostream>
#include <stack>
using namespace std;

void imprime(stack<int> s){
	cout << "----------------" << endl;
	cout << "Impressão da pilha:" << endl;
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
}

int main() {
	stack<int> s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	imprime(s);
	
	cout << "Ao retirar o elemento do topo da pilha, retiramos o " << s.top() << endl;
	s.pop();
	s.pop();
	
	imprime(s);
	s.push(60);
	imprime(s);
	
	
	return 0;
}
