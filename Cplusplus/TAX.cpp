#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
struct node {
    double index;
    int value,children,priority;
    long long sum;
    node *parent,*left,*right;
    *node();
};
node *root,*null;

node* At(int index){
    node *current=root;
    while(true){
        if (index==current->left->children+1) return current;
        if (index<current->left->children+1)
            current=current->left;
        else{
            index-=current->left->children;
            current=current->right;
        }
    }
}

void Update(node *current){
    current->children=current->left->children+current->right->children+1;
    current->sum = current->left->sum+current->right->sum+current->value*current->value;
}

void SetLink(node *parent, node *child,bool inRight){
    child->parent=parent;
    if (inRight) parent->right=child;
    else parent->left=child;
}

void UpNode(node *x){
    node *y=x->parent;
    node *z=y->parent;
    if (x==y->left){
        SetLink(y,x->right,0);
        SetLink(x,y,1);
    }
    else {
        SetLink(y,x->left,1);
        SetLink(x,y,0);
    }
    SetLink(z,x,z->right==y);
    Update(y);
    Update(x);
    Update(z);
}

void Insert(int value, double index){
    node *current=root,*parent;
    while (current!=null){
        parent->children++;
        parent->sum+=value*value;
        parent=current;
        if (current->index>index)
            current=current->left;
        else
            current=current->right;
    }
    current->index=index;
    current->value=value;
    current->children=1;
    current->priority=rand();
    current->sum=value*value;
    current->parent=parent;
    current->left=null;
    current->right=null;
    SetLink(parent,current,current->value>parent->value);
    while(current->parent!=null && current->priority>current->parent->priority)
        UpNode(current);
    if (current->parent==null) root=current;
}



void init(){
    srand(time(0));
    null->index=0;
    null->value=0;
    null->children=0;
    null->priority=0;
    null->sum=0;
    null->parent=NULL;
    null->left=NULL;
    null->right=NULL;
    root=null;
}

int main(){
    freopen("TAX.INP","r",stdin);
    freopen("TAX.OUT","w",stdout);
    init();
}