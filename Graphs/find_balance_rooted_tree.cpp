/*
10 9
0 1
1 3
1 4
4 5
4 8
3 2
3 6 
3 7
6 9
*/



#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, e;
	cin>>n>>e;
	map<int, list<int>> adj;
	int degree[n];
	for(int i = 0; i<e; i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// cout<<adj[0].size();
	vector<int> leaves;
	for(int i = 0; i<n;i++){
		degree[i] = adj[i].size();
		if(degree[i] == 1 || degree[i] == 0){
			leaves.push_back(i);
			degree[i] = 0;
		}
	}
	
	int count = leaves.size();
// 	cout<<"gg->"<<count<<endl;
	while(count<n){
		vector<int> new_leave;
		for(auto i = leaves.begin(); i!=leaves.end(); i++){
		    
			for(auto j = adj[*i].begin(); j!=adj[*i].end(); j++){
			 //   cout<<*j<<" ";
			 //   cout<<"hihelk"<<endl;
				degree[*j] = degree[*j] - 1;
				if(degree[*j] == 1){
					new_leave.push_back(*j);
					degree[*j] = 0;
				}
			}
		}
// 		cout<<endl;
		leaves = new_leave;
		count = count + new_leave.size();
// 		cout<<"count->"<<count<<endl;
	}
	cout<<"center-> ";
	for(auto it = leaves.begin(); it!=leaves.end(); it++){
	    cout<<*it<<" ";
	}
	return 0;
}