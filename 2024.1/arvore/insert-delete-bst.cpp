#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int key;
    node *left, *right;
} node;

typedef struct tree{
	int size;
    node *root;
} tree;

void fillTabular(node *p, int h, int &index, vector<vector<string> > &tabular, int n){
    if(p == NULL) return;
    
    if(tabular.size()<h+1){
        vector<string> s;
        s.resize(n, "   ");
        tabular.push_back(s);
    }
    fillTabular(p->left, h+1, index, tabular, n);
    tabular[h][index++] = " "+to_string(p->key)+" ";
    
    fillTabular(p->right, h+1, index, tabular, n);
}

void printTabular(node *p, int n){
    vector<vector<string> > tabular;
    int index = 0;
    fillTabular(p, 0, index, tabular, n);
    
    
    cout << "Tabular view: " << endl;
    int i,j;
    for(i=0;i<tabular.size();i++){
        for(j=0;j<tabular[i].size();j++){
            cout << tabular[i][j] << " ";
        }
        cout << endl;
    }
}

void insert(tree &t, int key){
	node *p = t.root;
	node *f = t.root; 
	while (p != NULL && p->key != key){
		f = p;
		if (key < p->key)
			p = p->left;
		else	     
			p = p->right;
	}
	if(p == NULL){
		p = new node();  
		p->key = key;
		p->left = NULL;
		p->right = NULL;
		t.size++;
		
		if (t.root == NULL)
			t.root = p;
		else if (key < f->key)
			f->left = p;
		else
			f->right = p;
	}
}

void deleteKey(tree &t, int key){
	node *p = t.root;
	node *paiP = t.root; 
	while (p != NULL && p->key != key){
		paiP = p;
		if (key < p->key)
			p = p->left;
		else	     
			p = p->right;
	}
	if(p != NULL){
		node *repos = NULL;
		node *paiRepos = NULL;
		if(p->left != NULL){
			paiRepos = repos = p->left; //repos contém a maior chave na esq e paiRepos seu pai
			while(repos->right != NULL){
				paiRepos = repos;
				repos = repos->right;
			}
			if(paiRepos != repos)
				paiRepos->right = NULL; //repos será trocado por p. Portanto o ponteiro do pai de repos deverá ser NULL
			else
				p->left = repos->left; //repos é o único nó menor da esquerda
		}
		else if(p->right != NULL){
			paiRepos = repos = p->right; //repos contém a menor chave na dir e paiRepos seu pai
			while(repos->left != NULL){
				paiRepos = repos;
				repos = repos->left;
			}
			if(paiRepos != repos)
				paiRepos->left = NULL; //repos será trocado por p. Portanto o ponteiro do pai de repos deverá ser NULL
			else
				p->right = repos->right; //repos é o único nó maior da direita. Então deve ser filho de p
		}
		if (repos != NULL){ //troca repos com p e apaga o nó repos
			p->key = repos->key;
			free(repos);
		}else{
			//p é folha
			if(p == t.root){
				//p é a raiz
				t.root = NULL;
			}
			else if (p->key < paiP->key)
				//p está a esquerda de f. Então f->left deve ser NULL
				paiP->left = NULL;
			else
				//p está a direita de f. Então f->left deve ser NULL
				paiP->right = NULL;
			free(p);
		}
		t.size--;
	}
}

int main()
{
    int n,i,j;

    tree t;
    t.root = NULL;
    t.size = 0;
    
    insert(t, 3);
    printTabular(t.root,t.size);
    deleteKey(t, 3);
    printTabular(t.root,t.size);
    insert(t, 8);
    insert(t, 10);
    insert(t, 0);
    insert(t, 2);
    insert(t, 11);
    insert(t, 13);
    insert(t, 17);
    printTabular(t.root,t.size);
    deleteKey(t, 8);
    printTabular(t.root,t.size);
    
    return 0;
}