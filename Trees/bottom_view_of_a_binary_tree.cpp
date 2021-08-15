#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int hd;
	struct Node *left, *right;
	Node(int data){
		this->data = data;
		hd = INT_MAX;
		left= right= NULL;
	}
};

void bottem_view(Node *root){
	if(root == NULL){
		return;
	}
	int hd = 0;
	map<int, int> m;
	queue<Node *> q;
	root->hd = hd;
	q.push(root);
	while(!q.empty()){
		Node *temp = q.front();
		hd = temp->hd;
		m[hd] = temp->data;
		q.pop();
		if(temp->left != NULL){
			temp->left->hd = hd - 1;
			q.push(temp->left);
		}
		if(temp->right != NULL){
			temp->right->hd = hd + 1;
			q.push(temp->right);
		}
	}
	for(auto i = m.begin(); i!=m.end(); i++){
		cout<<i->second<<" ";
	}
	// int sum = 0;
	// for(auto i = m.begin(); i!=m.end(); i++){
	// 	cout<<i->second<<" ";
	// 	sum = sum + i->second;
	// }
	// cout<<sum;

}

int main(){
	Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    bottem_view(root);
    return 0;
}