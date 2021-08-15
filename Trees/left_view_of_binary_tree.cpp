#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left, *right;
	node(int data){
		this->data = data;
		left = right = NULL;
	}
};

void tree_left_view(struct node *root, int level, int &max_level){
	if(root == NULL){
		return;
	}
	if(max_level < level){
		cout<<root->data<<" ";
		max_level = level;	
	}
	tree_left_view(root->left, level+1, max_level);
	tree_left_view(root->right, level+1, max_level);
}

void get_tree_left_view_helper(struct node * root){
	int max_level = 0;
	tree_left_view(root, 1,max_level);
}

int main(){
	struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(5);
    root->left->left->right = new node(50);
    root->left->left->right->right = new node(510); 
    root->left->left->right->right->right = new node(10);
    get_tree_left_view_helper(root);
    return 0;
}

//1 2 4 5 510 10 