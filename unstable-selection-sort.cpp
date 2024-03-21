#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct aluno{
	string nome;
	int nota;
}aluno;

void selectionSort(vector<aluno> &v){
	int i,j,indiceMenor;
	
	for(i=0;i<v.size()-1;i++){
		indiceMenor = i;
		
		for(j=i+1;j<v.size();j++){
			if(v[j].nota < v[indiceMenor].nota){
				indiceMenor = j;
			}
		}
		
		swap(v[i], v[indiceMenor]);
	}
}

void print(vector<aluno> &v){
	int i;
	for(i=0;i<v.size();i++){
		cout << "(" << v[i].nota << "," << v[i].nome << ") ";
	}
	cout << endl;
}

int main() {
	vector<aluno> v;
	
	aluno a;
	
	
	a.nome = "Lucas";
	a.nota = 7;
	v.push_back(a);
	
	a.nome = "Paulo";
	a.nota = 9;
	v.push_back(a);
	
	
	a.nome = "Rafa";
	a.nota = 9;
	v.push_back(a);
	
	a.nome = "João";
	a.nota = 7;
	v.push_back(a);
	
	
	a.nome = "Duda";
	a.nota = 9;
	v.push_back(a);
	
	print(v);
	selectionSort(v);
	print(v);
	
	return 0;
}