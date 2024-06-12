#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct node{
	int c;
	node *left, *right;
	int bal;
} node;
 
typedef struct tree{
	int size;
	node *root;	
} tree;

void insert(node *&p, int c, int bal=0){
	p = new node();
	p->c = c;
	p->bal = bal;
}

void fillTabular(node *p, int h, int &index, vector<vector<string> > &tabular, int n){
    if(p == NULL) return;
    
    if(tabular.size()<h+1){
        vector<string> s;
        s.resize(n, "    ");
        tabular.push_back(s);
    }
    fillTabular(p->left, h+1, index, tabular, n);
    tabular[h][index++] = " "+to_string(p->c);//+"("+to_string(p->bal)+")";
    
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

void singleRotLeft(node *&p){
	node *pf = p->left;
	p->left = pf->right;
	pf->right = p;
	p->bal = 0;
	p = pf;   
	p->bal = 0;
}

void singleRotRight(node *&p){
	node *pf = p->right;
	p->right = pf->left;
	pf->left = p;
	p->bal = 0;
	p = pf;
	p->bal = 0;
}

void doubleRotRight(node *&p){
	node *pf = p->right;
	node *pn = pf->left;
	pf->left = pn->right;
	pn->right = pf;
	p->right = pn->left;
	pn->left = p;
	if(pn->bal == 1)
		p->bal = -1;
	else
		p->bal = 0;
	if(pn->bal == -1)
		pf->bal = 1;
	else
		pf->bal = 0;
	p = pn;
	p->bal = 0;
}

void doubleRotLeft(node *&p){
	node *pf = p->left;
	node *pn = pf->right;
	pf->right = pn->left;
	pn->left = pf;
	p->left = pn->right;
	pn->right = p;
	if(pn->bal == 1)
		p->bal = -1;
	else
		p->bal = 0;
	if(pn->bal == -1)
		pf->bal = 1;
	else
		pf->bal = 0;
	p = pn;
	p->bal = 0;
}

void insertAVL(int k, node *&p, bool &h){
	if (p == NULL){   
		insert(p, k);
		h = true;
	}
	else if(k < p->c){
		insertAVL(k, p->left, h);
		if(h){
			switch(p->bal){
				case 1:
					p->bal = 0;
					h = false;
					break;
				case 0:
					p->bal = -1;
					break;
				case -1:
					if(p->left->bal == -1){
						singleRotLeft(p);
					}else{
						doubleRotLeft(p);
					}	
					p->bal = 0;
					h=false;
					break;
			}
		}
	}else if(k > p->c){
		insertAVL(k, p->right, h);
		if(h){
			switch(p->bal){
				case -1:
					p->bal = 0;
					h = false;
					break;
				case 0:
					p->bal = 1;
					break;
				case 1:
					if(p->right->bal == 1){
						singleRotRight(p);
					}else{
						doubleRotRight(p);
					}
					p->bal = 0; h = false;
					break;
			}
		}
	}else{
		h = false;
	}
}




int main() {
	int n,i,j;

    tree t;
    t.root = NULL;
    t.size = 0;
    
 
    
    bool h = false;
    insertAVL(40, t.root, h); t.size++;
    printTabular(t.root,t.size);
    insertAVL(30, t.root, h); t.size++;
    printTabular(t.root,t.size);
    insertAVL(20, t.root, h); t.size++;
    printTabular(t.root,t.size);
    //insertAVL(35, t.root, h); t.size++;
    //printTabular(t.root,t.size);
    //insertAVL(45, t.root, h); t.size++;
    //printTabular(t.root,t.size);
    //insertAVL(36, t.root, h); t.size++;
    //printTabular(t.root,t.size);
    insertAVL(25, t.root, h); t.size++;
	printTabular(t.root,t.size);
	insertAVL(15, t.root, h); t.size++;
	printTabular(t.root,t.size);
	insertAVL(26, t.root, h); t.size++;
	printTabular(t.root,t.size);
	
	return 0;
}