#include <iostream>
#include <queue>
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

void percursoEmNiveis(arvore T){
	queue<no*> f;
	no *p;
	f.push(T.raiz);
	while(!f.empty()){
		p = f.front(); f.pop();
		visita(p);
		if(p->le != NULL){
			f.push(p->le);
		}
		if(p->ld != NULL){
			f.push(p->ld);
		}
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
	
	percursoEmNiveis(T);
	
	return 0;
}
