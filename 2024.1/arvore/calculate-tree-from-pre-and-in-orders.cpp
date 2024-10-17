#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int key;
    node *left, *right;
} node;

typedef struct tree{
    node *root;
} tree;

bool inBounds(int n, int a, int b, int c, int d){
    if(a < 0 || a > n || a > b) return false;
    if(b < 0 || b > n) return false;
    if(c < 0 || c > n || c > d) return false;
    if(d < 0 || d > n) return false;
    return true;
}

void calcRecursive(node *&r, vector<int> &pre, vector<int> &in, int preBegin, int preEnd, int inBegin, int inEnd){
    //cout << "calcRecursive(" << preBegin << ", " << preEnd << ", " << inBegin << ", " << inEnd << ")" << endl;
    
    if(!inBounds(pre.size()-1, preBegin, preEnd, inBegin, inEnd)){
        //cout << "return" << endl;
        return;
    }
    
    int i = preBegin;
    
    r = new node();
    r->key = pre[i];
    r->right = r->left = NULL;
    
    //cout << r->key << endl;
    
    int j = inBegin;
    while(in[j] != r->key){
        j++;
    }
    int intervalSize = j - inBegin;
    
    calcRecursive(r->left, pre, in, preBegin+1, preBegin+intervalSize, inBegin, j-1);
    calcRecursive(r->right, pre, in, preBegin+intervalSize+1, preEnd, j+1, inEnd);
}

void printPreOrder(node *p, bool root = true){
    if(root){
        cout << "Pre Order:" << endl;    
    }
    
    if(p != NULL){
        cout << p->key << " ";
        printPreOrder(p->left, false);
        printPreOrder(p->right, false);
    }
    
    if(root){
        cout << endl;    
    }
}

void printInOrder(node *p, bool root = true){
    if(root){
        cout << "In Order:" << endl;    
    }
    
    if(p != NULL){
        printInOrder(p->left, false);
        cout << p->key << " ";
        printInOrder(p->right, false);
    }
    
    if(root){
        cout << endl;    
    }
}

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

int main()
{
    int n,i,j;
    cin >> n;

    tree t;
    t.root = NULL;
    
    vector<int> pre, in;
    pre.resize(n);
    in.resize(n);
    
    for(i=0;i<n;i++){
        cin >> pre[i];
    }
    
    for(i=0;i<n;i++){
        cin >> in[i];
    }
    
    calcRecursive(t.root, pre, in, 0, n-1, 0, n-1);
    
    printPreOrder(t.root);
    printInOrder(t.root);

    printTabular(t.root,n);
    return 0;
}
