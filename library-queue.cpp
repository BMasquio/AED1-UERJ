#include <iostream>
#include <queue>
using namespace std;

void imprime(queue<int> q){
	cout << "----------------" << endl;
	cout << "Impressão da fila:" << endl;
	while(!q.empty()){
		cout << q.front() << ", ";
		q.pop();
	}
	cout << endl;
}

int main() {
	queue<int> q;
	
	q.push(10);
	q.push(20);
	q.push(30);
	imprime(q);
	
	cout << "Desenfilando " << q.front() << endl;
	q.pop();
	
	q.push(40);
	q.push(50);
	
	
	imprime(q);
	
	cout << "Desenfilando " << q.front() << endl;
	q.pop();
	
	imprime(q);
	
	return 0;
}
