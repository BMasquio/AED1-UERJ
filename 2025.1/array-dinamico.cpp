#include <iostream>
using namespace std;

int realocacoes = 0;
int valoresCopiados = 0;

typedef struct arrayDin{
  int *v;
  int tam, cap;
} arrayDin;

void inicializa(arrayDin &a){
  a.v = (int *)malloc(1 * sizeof(int));
  a.cap = 1;
  a.tam = 0;
}

bool cheio(arrayDin &a){
  return (a.cap == a.tam);
}

void dobra(arrayDin &a){
  int* aux = (int *)malloc((a.cap*2) * sizeof(int));
  realocacoes++;
  valoresCopiados+=a.cap;
  for(int i=0;i<a.cap;i++){
    aux[i] = a.v[i];
  }
  a.cap = a.cap*2;
  delete a.v;
  a.v = aux;
}

void insere(arrayDin &a, int k){
  if (cheio(a)){
    dobra(a);
  }
  a.v[a.tam] = k;
  a.tam = a.tam+1;
}

void imprime(arrayDin &a){
  cout << a.tam << "/" << a.cap << endl;
  for (int i=0;i<a.cap;i++){
    cout << a.v[i] << " ";
  }
  cout << endl;
}

int main()
{
    int n;
    cin >> n;
    
    arrayDin arr;
    inicializa(arr);
    
    for (int i=0; i<n; i++){
      insere(arr,i);
      imprime(arr);
    }
    
    cout << "Quantidade de realocações -> " << realocacoes << endl;
    cout << "Quantidade de valores copiados -> " << valoresCopiados << endl;
    cout << "Valores copiados/n -> " << (double)valoresCopiados/n << endl;
    
    
    return 0;
}