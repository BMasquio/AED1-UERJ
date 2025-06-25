#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef struct no{
  no *le,*ld;
  int c;
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

void inOrdem(no *p, int &cont, int h, vector<vector<int>> &m){
	if (p != NULL){
		inOrdem(p->le,cont,h+1,m);
		m[h][cont] = p->c;
		cont = cont+1;
		inOrdem(p->ld,cont,h+1,m);
	}
}

void printM(vector<std::vector<int>>& grid) {
    int width = 0;
    for (const auto& row : grid)
        for (int x : row)
            width = max(width, (int)to_string(x).size());
    ++width;
    
    for (const auto& row : grid) {
        for (int x : row)
            cout << right << setw(width) << x;
        cout << right << setw(width) <<  endl;
    }
}

void criaTabularHorizontal(arvore &t){
	pair<int,int> pairR;
	pairR = calculaAlturaENos(t.r);
	
	int h,n;
	h = pairR.first;
	n = pairR.second;
	
	vector<vector<int>> m;
	m.resize(h);
	int i;
	for(i=0;i<h;i++){
	  m[i].resize(n, 0);
	}
	
	int cont = 0;
	inOrdem(t.r,cont,0,m);
	
	printM(m);
}

void insere(no *&p, int k){
  if(p == NULL){
    p = new no;
    p->le = NULL;
    p->ld = NULL;
    p->c = k;
  }else if (k > p->c){
    insere(p->ld,k);
  }else if (k < p->c){
    insere(p->le,k);
  }
}

int main()
{
  int n,i,k;
  cin >> n;
  
  arvore t;
  t.r = NULL;
  
  for(i=0;i<n;i++){
    cin >> k;
    insere(t.r, k);
  }
  
  criaTabularHorizontal(t);
  
  return 0;
}
