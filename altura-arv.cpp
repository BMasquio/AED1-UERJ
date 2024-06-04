#include <iostream>
#include <algorithm>
using namespace std;

typedef struct no{
	char c;
	no *le, *ld;
} no;

typedef struct arvore{
	no *raiz;	
} arvore;

int altura (no *p){
	if(p == NULL) return 0;
	else return 1+max(altura(p->le), altura(p->ld));
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
	
	cout << altura(T.raiz) << endl;
	
	return 0;
}


