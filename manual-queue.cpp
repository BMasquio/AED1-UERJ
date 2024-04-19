#include <iostream>
using namespace std;

//fila = queue

typedef struct fila{
	int V[4]; // V[1..m]
	int f,r;
	int m=3;
}fila;

void imprime(fila q){
	int i;
	cout << "----------------" << endl;
	cout << "Impressão da fila:" << endl;
	cout << "f = " << q.f << endl;
	cout << "r = " << q.r << endl;
	cout << "m = " << q.m << endl;
	i=q.f;
	if(q.f == 0){
		cout << "Fila vazia" << endl;
	}else{
		while(q.f != q.r){
			cout << q.V[q.f] << ", ";
			q.f = (q.f % q.m)+1;
		}
		cout << q.V[q.f] << endl;
	}
}

void esvazia(fila &q){
	q.r = q.f = 0;
}

int enfila(fila &q, int k){
	q.r = (q.r % q.m) + 1;
	q.V[q.r] = k;
	if(q.f == 0){
		q.f = 1;
	}
	return q.r;
}

int desenfila(fila &q){
	int k;
	k = q.V[q.f];
	if(q.f == q.r){
		esvazia(q);
	}else{
		q.f = (q.f % q.m) + 1;		
	}
	return k;
}


int main() {
	fila q;	
	
	esvazia(q);
	enfila(q,10);
	enfila(q,20);
	enfila(q,30);
	imprime(q);
	cout << "Desenfilando " << desenfila(q) << endl;
	imprime(q);
	enfila(q,40);
	imprime(q);
	/*
	cout << "Desenfilando " << desenfila(q) << endl;
	enfila(q,40);
	cout << "Desenfilando " << desenfila(q) << endl;
	cout << "Desenfilando " << desenfila(q) << endl;
	enfila(q,50);
	cout << "Desenfilando " << desenfila(q) << endl;
	cout << "Desenfilando " << desenfila(q) << endl;
	imprime(q);
	*/
	
	
	
	return 0;
}
