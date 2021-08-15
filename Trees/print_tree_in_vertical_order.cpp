#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int hd;
    struct node *left, *right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void vertical_traverse(struct node * root){
    queue<node *> q;
    root->hd = 0;
    q.push(root);
    map<int, list<int>> m;
    while(!q.empty()){
        struct node * temp = q.front();
        q.pop();
        int hd = temp->hd;
        m[hd].push_back(temp->data);
        if(temp->left != NULL){
            temp->left->hd = hd -1;
            q.push(temp->left);
        }
        if(temp->right != NULL){
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }
    for(auto i = m.begin(); i!=m.end(); i++){
		for(auto j = i->second.begin(); j!=i->second.end(); j++){
		    cout<<*j<<" ";
		}
	}
}

int main(){
    struct node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    vertical_traverse(root);
    return 0;
}

//out - 4 2 1 5 6 3 8 7 9