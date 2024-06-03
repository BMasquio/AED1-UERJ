#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cmath>

using namespace std;

vector<int> V;

void merge(int e, int d, int i){
	//V1[e..i]
	//V2[i+1..d]
	vector<int> aux;
	aux.resize(d-e+1);
	int p3 = 0;
	
	int p1, p2;
	p1 = e;
	p2 = i+1;
	while(p1 <= i && p2 <= d){
		if(V[p1] <= V[p2]){
			aux[p3] = V[p1];
			p1++;
		}else{
			aux[p3] = V[p2];
			p2++;
		}
		p3++;
	}
	while(p1 <= i){
		aux[p3] = V[p1];
		p1++; p3++;
	}
	
	while(p2 <= d){
		aux[p3] = V[p2];
		p2++; p3++;
	}
	
	int j;
	for(j=0;j<aux.size();j++){
		V[j+e] = aux[j];
	}
	
}

void mergeSort(int e, int d){
	int i;
	cout << "mergeSort(" << e <<"," << d<<")" << endl;
	if(e != d){
		i = floor((e+d)/2);
		cout << "Fazendo as chamadas recursivas mergeSort("<<e<<", " <<i<< ") e mergeSort(" << i+1 << "," << d << ")" << endl;
		mergeSort(e,i);
		mergeSort(i+1,d);
		merge(e,d,i);
	}
}

void print(vector<int> &V){
	int i;
	for(i=0;i<V.size();i++){
		cout << V[i] << " ";
	}
	cout << endl;
}

void fillVector(vector<int> &V, int size){
	int i;
	V.resize(size);
	for(i=0;i<V.size();i++){
		V[i] = rand()%1000 + 1;
	}
}

int main() {
	srand (time(NULL));

	fillVector(V, 10);
	print(V);
	
	mergeSort(0, V.size()-1);
	
	print(V);
	// your code goes here
	return 0;
}
