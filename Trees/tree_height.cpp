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

int tree_height(struct node * root){
    if(root == NULL){
        return -1;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    return max(tree_height(root->left), tree_height(root->right)) + 1;
}


int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(5);
    root->left->left->right = new node(50);
    root->left->left->right->right = new node(510);
    int ans = tree_height(root);
    cout<<ans;
    return 0;
}