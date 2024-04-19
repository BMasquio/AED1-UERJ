#include <iostream>
using namespace std;

//pilha = stack

typedef struct pilha {
	int V[11]; //Só estaremos utilizando V[1..m]
	int topo;
	int m=10;
} pilha;

void esvazia(pilha &s){
	//s é uma variável local
	s.topo = 0;
}

int push(pilha &s, int k){
	if(s.topo != s.m){
		s.topo = s.topo + 1; //topo++
		s.V[s.topo] = k;
	}else{
		s.topo = -1;
	}
	return s.topo;
}

int pop(pilha &s){
	int k;
	
	if(s.topo > 0){
		//não vazia
		k = s.V[s.topo];
		s.topo = s.topo - 1; //s.topo--
	}else{
		//vazia
		//cria exceção
		k = -1;
	}
	return k;
}

void imprime(pilha &s){
	int i;
	cout << "----------------" << endl;
	cout << "Impressão da pilha:" << endl;
	cout << "m = " << s.m << endl;
	cout << "topo = " << s.topo << endl;
	for(i=s.topo;i>=1;i--){
		cout << s.V[i] << endl;
	}
	cout << "----------------" << endl;
}

int main() {
	pilha s;
	
	esvazia(s);
	
	push(s,10);
	push(s,20);
	push(s,30);
	push(s,40);
	push(s,50);
	imprime(s);
	
	cout << "Ao retirar o elemento do topo da pilha, retiramos o " << pop(s) << endl;
	pop(s);
	
	push(s,60);
	imprime(s);
	
	// your code goes here
	return 0;
}
