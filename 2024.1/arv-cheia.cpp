#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

typedef struct no{
	string c;
	no *le, *ld;
} no;

typedef struct arvore{
	no *raiz;	
} arvore;


void init(arvore *T){
	no *p;
	p = new no;
	p->c = "+";
	T->raiz = p;
	
	p = new no;
	p->c = "*";
	T->raiz->le = p;
	
	p = new no;
	p->c = "-";
	T->raiz->ld = p;
	
	p = new no;
	p->c = "A";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->le = p;
	
	p = new no;
	p->c = "B";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->ld = p;
	
	p = new no;
	p->c = "C";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->le = p;
	
	p = new no;
	p->c = "/";
	T->raiz->ld->ld = p;
	
	p = new no;
	p->c = "D";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->ld->le = p;
	
	p = new no;
	p->c = "E";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->ld->ld = p;
}

void init2(arvore *T){
	no *p;
	p = new no;
	p->c = "1";
	T->raiz = p;
	
	p = new no;
	p->c = "2";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le = p;
	
	p = new no;
	p->c = "3";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld = p;
	
	p = new no;
	p->c = "4";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->ld = p;
	
	p = new no;
	p->c = "6";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->ld->ld = p;
	
	p = new no;
	p->c = "9";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->ld->ld->le = p;
	
	p = new no;    
	p->le = NULL;
	p->ld = NULL;
	p->c = "10";
	T->raiz->le->ld->ld->ld = p;
	
	p = new no;
	p->c = "3";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld = p;
	
	p = new no;
	p->c = "5";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->le = p;

    p = new no;
	p->c = "7";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->le->le = p;

    p = new no;
	p->c = "8";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld->le->ld = p;
}


void init3(arvore *T){
	no *p;
	p = new no;
	p->c = "1";
	T->raiz = p;
	
	p = new no;
	p->c = "2";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le = p;
	
	p = new no;
	p->c = "3";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->ld = p;
	
	p = new no;
	p->c = "4";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->le = p;
	
	p = new no;
	p->c = "5";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->ld = p;
	
	p = new no;
	p->c = "6";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->le->le = p;
	
	p = new no;
	p->c = "7";
	p->le = NULL;
	p->ld = NULL;
	T->raiz->le->le->ld = p;
}

pair<bool, int> cheia(no *p){
	if(p == NULL) return make_pair(true, 0);
	else{
		pair<bool,int> p1, p2;
		p1 = cheia(p->le);
		p2 = cheia(p->ld);
		return make_pair(p1.first && p2.first && p1.second == p2.second, 1+max(p1.second, p2.second));
	}
}

void init4(arvore *T){
	no *p;
	p = new no;
	p->c = "+";
	T->raiz = p;
	
	p = new no;
	p->c = "*";
	T->raiz->le = p;
	
	p = new no;
	p->c = "-";
	T->raiz->ld = p;
}


int main() {
	arvore T;
	
	//init(&T);
	//init2(&T);
	//init3(&T);
	init4(&T);
	
	cout << cheia(T.raiz).first << endl;
	
	return 0;
}


