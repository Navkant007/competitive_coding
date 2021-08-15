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

int leaf_sum(struct node * root){
    if(root ==  NULL){
        return 0;
    }
    int total = root->data;
    cout<<root->data<<" ";
    // if(root->left == NULL && root->right == NULL){
    //     return total;
    // }
    // else{
        if(root->left != NULL){
            total += leaf_sum(root->left);
        }
        if(root->right != NULL){
            total += leaf_sum(root->right);
        // }
    }
    return total;
}

int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(50);
    int ans = leaf_sum(root);
    cout<<endl<<ans;
    return 0;
}