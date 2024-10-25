#include <iostream>
using namespace std;

typedef struct pilha  {
  int *v;
  int capacidade;
  int topo;
} pilha;

void imprime(pilha &s){
  int i;
  cout << "capacidade = " << s.capacidade << endl;
  cout << "topo = " << s.topo << endl;
  for(i=0;i<s.capacidade;i++)
    cout << s.v[i] << " ";
  cout << endl << endl;
}

void init(pilha &s, int m){
  s.capacidade = m;
  s.topo = -1;
  s.v = (int*)malloc(m*sizeof(int));
}

void esvazia(pilha &s){
  s.topo = -1;
}

bool vazia(pilha &s){
  return s.topo == -1;
}

bool cheia(pilha &s){
  return s.topo == s.capacidade-1;
}

void push(pilha &s, int k){
	if (cheia(s)){
		//lançar exceção(‘Pilha cheia’)
		cout << "Pilha cheia" << endl;
		return;
	}
	s.topo = s.topo + 1;
  s.v[s.topo] = k;
}

int pop(pilha &s){
	if (vazia(s)){
		//lançar exceção(‘Pilha vazia’)
		cout << "Pilha vazia" << endl;
		return -1;
	}
  int k = s.v[s.topo];
  s.topo = s.topo - 1; 
	return k;
}

int top(pilha &s){
	if (vazia(s)){
    //lançar exceção(‘Pilha vazia’)
    cout << "Pilha vazia" << endl;
		return -1;
	}
	return s.v[s.topo];
}

int main() 
{
    pilha s;
    init(s, 5);
    push(s, 1);
    push(s, 6);
    push(s, 3);
    imprime(s);
    cout << "Tirando o elemento da pilha " << pop(s) << endl;;
    imprime(s);
    push(s,9);
    imprime(s);
    cout << "Visitando o elemento da pilha " << top(s) << endl;;
    imprime(s);
    
    return 0;
}
