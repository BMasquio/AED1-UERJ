#include <iostream>
#include <queue>
#include <math.h>
using namespace std;


typedef struct no {
	int c;
	no *le, *ld;
} no;
typedef struct arvore {
	no *raiz;
} arvore;


arvore T;

void constroi(int h){
	queue<no*> q;
	int n = pow(2,h-1) - 1;
	int i=1;
	no *no1, *no2, *p;
	
	T.raiz = new no;
	T.raiz->c = 1;
	T.raiz->le = NULL;
	T.raiz->ld = NULL;
	
	q.push(T.raiz);
	
	while(!q.empty()){
		p = q.front(); q.pop();
		no1 = new no; no1->c = i+1; no1->le = NULL; no1->ld = NULL;
		no2 = new no; no2->c = i+2; no2->le = NULL; no2->ld = NULL;
		p->le = no1;
		p->ld = no2;
		i+=2;
		if(i <= n){
			q.push(no1);
			q.push(no2);
		}
	}
	
}


void print(){
	
	no *p;
	
	cout << "Raiz" << endl;
	cout << T.raiz->c << endl;
	
	cout << "Filho da esquerda da raiz" << endl;
	p = T.raiz->le;
	cout << p->c << endl;
	
	cout << "Filho da direita da raiz" << endl;
	p = T.raiz->ld;
	cout << p->c << endl;
	
	cout << "Filhos do filho esquerdo da raiz" << endl;
	p = T.raiz->le->le;
	cout << p->c << endl;
	p = T.raiz->le->ld;
	cout << p->c << endl;
	
	cout << "Filhos do filho direito da raiz" << endl;
	p = T.raiz->ld->le;
	cout << p->c << endl;
	p = T.raiz->ld->ld;
	cout << p->c << endl;
}

int main() {
	int h = 3;
	constroi(h);
	print();
	
	
	return 0;
}
