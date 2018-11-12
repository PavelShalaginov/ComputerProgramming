#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int key, priority;
	Node *left=NULL,*right=NULL;
};
Node *rotate_right(Node *node){
	Node *tmp=node->left;
	node->left = tmp->right;
	tmp->right = node;
	return tmp;
}
Node *rotate_left(Node *node){
	Node *tmp=node->right;
	node->right=tmp->left;
	tmp->left = node;
	return tmp;
}
Node *insert(Node *node,const int &key,const int &priority){
	if (!node){
		node = new Node;
		node->key=key;
		node->priority=priority;
		return node;
	}
	if (node->key>key){
		insert(node->left,key,priority);
		if ((node->left)->priority<node->priority)
			return rotate_right(node);
	}
	else{
		insert(node->right,key,priority);
		if ((node->right)->priority<node->priority)
			return rotate_left(node);
	}
}

int find(Node *node, const int &val){
	
}

Node *root;
int n,m;

int main(){
	freopen("DADY.INP","r",stdin);
	freopen("DADY.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
}