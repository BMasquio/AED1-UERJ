#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef struct no{
  no *le,*ld;
  int c, bal;
}no;

typedef struct arvore{
  no *r;
}arvore;

pair<int,int> calculaAlturaENos(no *p){
	if (p == NULL){
		return make_pair(0,0);
	}
	else{
	  int esqH,esqN,dirH,dirN;
		pair<int,int> pairR;
		
		pairR = calculaAlturaENos(p->le);
		esqH = pairR.first;
		esqN = pairR.second;
		
		pairR = calculaAlturaENos(p->ld);
		dirH = pairR.first;
		dirN = pairR.second;
		
		int qtdNos = esqN+dirN+1;
		int h = max(esqH,dirH)+1;
		return make_pair(h,qtdNos);
	}
}

void inOrdem(no *p, int &cont, int h, vector<vector<pair<int,int>>> &m){
	if (p != NULL){
		inOrdem(p->le,cont,h+1,m);
		m[h][cont] = make_pair(p->c,p->bal);
		cont = cont+1;
		inOrdem(p->ld,cont,h+1,m);
	}
}

void printM(vector<std::vector<pair<int,int>>>& grid) {
    int width = 0;
    for (const auto& row : grid)
        for (auto x : row)
            width = max(width, (int)to_string(x.first).size());
    ++width;
    
    for (const auto& row : grid) {
        for (auto x : row){
            if(x.second == -2)
              cout << right << setw(width) << "x" << "(x)";
            else
              cout << right << setw(width) << x.first << "(" << (x.second == -1 ? "-" : (x.second == 1 ? "+" : "0")) <<  ")";
        }
        cout << right << setw(width) <<  endl;
    }
}

void criaTabularHorizontal(arvore &t){
	pair<int,int> pairR;
	pairR = calculaAlturaENos(t.r);
	
	int h,n;
	h = pairR.first;
	n = pairR.second;
	
	vector<vector<pair<int,int>>> m;
	m.resize(h);
	int i;
	for(i=0;i<h;i++){
	  m[i].resize(n, make_pair(0,-2));
	}
	
	int cont = 0;
	inOrdem(t.r,cont,0,m);
	
	printM(m);
}

void rotSimplDir(no *&p){
  no *pf;
  pf = p->le;   
  p->le = pf->ld;
  pf->ld = p;
  p->bal = 0;
  pf->bal = 0;
  p = pf;
}

void rotSimplEsq(no *&p){
  no *pf;
  pf = p->ld;
  p->ld = pf->le;
  pf->le = p;
  p->bal = 0;
  pf->bal = 0;
  p = pf;
}

void rotDuplDir(no *&p){
  no *u = p->le;      // filho à esquerda
  no *v = u->ld;      // neto à direita

  /* 1º passo – rot. simples à esquerda em u */
  u->ld = v->le;
  v->le = u;

  /* 2º passo – rot. simples à direita em p   */
  p->le = v->ld;
  v->ld = p;
  
  /* reajuste dos fatores de balanceamento */
  switch (v->bal){
      case -1:  p->bal =  1;  u->bal = 0;  break;
      case 1:  p->bal =  0;  u->bal = -1; break;
      case 0:  p->bal =  0;  u->bal = 0;  break;
  }
  v->bal = 0;

  /* v torna-se a nova raiz da subárvore */
  p = v;
}

void rotDuplEsq(no *&p){
  no *u = p->ld;      // filho à direita
  no *v = u->le;      // neto à esquerda

  /* 1º passo – rot. simples à direita em u */
  u->le = v->ld;
  v->ld = u;

  /* 2º passo – rot. simples à esquerda em p */
  p->ld = v->le;
  v->le = p;

  /* reajuste dos fatores de balanceamento */
  switch (v->bal){
      case 1:  p->bal = -1;  u->bal = 0;  break;
      case -1:  p->bal =  0;  u->bal = 1;  break;
      case 0:  p->bal =  0;  u->bal = 0;  break;
  }
  v->bal = 0;

  /* v passa a ser a nova raiz da subárvore */
  p = v;
}


bool insereAvl(no *&p, int k){
  if(p == NULL){
    p = new no;
    p->le = NULL;
    p->ld = NULL;
    p->c = k;
    p->bal = 0;
    return true;
  }else if (k < p->c){
    if(insereAvl(p->le,k)){
      switch(p->bal) {
        case 1:
          p->bal = 0;
          return false; 
          break;
        case 0:
          p->bal = -1;
          return true;
          break;
        case -1:
          if(p->le->bal == -1){
            rotSimplDir(p);
          }
          else{
            rotDuplDir(p);
          }
          return false;
          break;
      }
      return false;
    }
    return false;
  }else if (k > p->c){
    if(insereAvl(p->ld,k)){
      switch(p->bal) {
        case -1:
          p->bal = 0;
          return false; 
          break;
        case 0:
          p->bal = 1;
          return true;
          break;
        case 1:
          if(p->ld->bal == 1){
						rotSimplEsq(p);
          }
          else{
            rotDuplEsq(p);
          }
          return false;
          break;
      }
    }
    return false;
  }
  return false;
}

int main()
{
  int n,i,k;
  cin >> n;
  
  arvore t;
  t.r = NULL;
  
  for(i=0;i<n;i++){
    cin >> k;
    insereAvl(t.r, k);
    //cout << endl;
    //criaTabularHorizontal(t);
  }
  
  criaTabularHorizontal(t);
  
  return 0;
}

/*
80
113 66 144 182 195 68 80 55 143 85 63 198 48 36 62 38 198 93 141 187 156 136 1 165 137 188 159 199 53 170 119 111 176 195 44 23 45 129 111 195 35 123 150 183 29 159 71 147 63 185 196 188 3 54 154 151 187 136 3 137 140 196 194 139 123 62 21 48 39 16 135 83 138 35 103 47 94 18 62 117

20
161 175 182 93 99 128 23 197 22 19 144 40 63 168 65 39 20 47 99 166

13
21 26 30 9 4 14 28 18 15 10 2 3 7 1
*/
