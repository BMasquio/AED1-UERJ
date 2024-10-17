#include <iostream>
#include <stack>
using namespace std;

typedef struct no{
	char c;
	no *le, *ld;
} no;

typedef struct arvore{
	no *raiz;	
} arvore;

void visita(no *p){
	cout << p->c << " ";
}

void preOrdem(no *p){
	if(p != NULL){
		visita(p);
		preOrdem(p->le);
		preOrdem(p->ld);
	}
}

void inOrdem(no *p){
	if(p != NULL){
		inOrdem(p->le);
		visita(p);
		inOrdem(p->ld);
	}
}

void posOrdem(no *p){
	if(p != NULL){
		posOrdem(p->le);
		posOrdem(p->ld);
		visita(p);
	}
}

void init(arvore *T){
	
	no *p;
	p = new no;
	p->c = '+';
	T->raiz = p;
	
	p = new no;
	p->c = '*';
	T->raiz->le = p;
	
	p = new no;
	p->c = '-';
	T->raiz->ld = p;
	
	p = new no;
	p->c = 'A';
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->le = p;
	
	p = new no;
	p->c = 'B';
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->ld = p;
	
	p = new no;
	p->c = 'C';
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->le = p;
	
	p = new no;
	p->c = '/';
	T->raiz->ld->ld = p;
	
	p = new no;
	p->c = 'D';
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->ld->le = p;
	
	p = new no;
	p->c = 'E';
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->ld->ld = p;
}

int main() {
	arvore T;
	
	init(&T);
	
	cout << endl << "Pré ordem" << endl;
	preOrdem(T.raiz);
	cout << endl <<  "In ordem" << endl;
	inOrdem(T.raiz);
	cout << endl <<  "Pós ordem" << endl;
	posOrdem(T.raiz);
	
	return 0;
}


