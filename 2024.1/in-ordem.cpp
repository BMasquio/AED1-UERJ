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

void percursoInOrdem(arvore T){
	stack<no*> s;
	no *p;
	p = T.raiz;
	
	while(p != NULL || !s.empty()){
		while(p != NULL){
			s.push(p);
			p = p->le;
		}
		p = s.top(); s.pop();
		visita(p);
		p = p->ld;
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
	
	percursoInOrdem(T);
	
	return 0;
}

