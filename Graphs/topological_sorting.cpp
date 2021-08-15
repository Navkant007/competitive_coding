/*
6 6                                                                                                                                    
5 2                                                                                                                                    
5 0                                                                                                                                    
4 0                                                                                                                                    
4 1                                                                                                                                    
2 3                                                                                                                                    
3 1 
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];

int dfs(int k, int u, int ordering[]){
    visited[u] = true;
    for(int i = 0; i<adj[u].size(); i++){
        if(visited[adj[u][i]] == false){
            k = dfs(k, adj[u][i], ordering);
        }
    }
    ordering[k] = u;
    return k-1;
}

int main(){
    int nodes, edges, x, y;
    cin>>nodes>>edges;
    for(int i = 0 ; i < edges; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i = 0; i<nodes; i++){
        visited[i] = false;
    }
    int ordering[nodes];
    int k = nodes -1;
    for(int u = 0 ;u <nodes; u++){
        if(visited[u]==false){
            k = dfs(k, u, ordering);
        }
    }
    for(int i = 0; i<nodes; i++){
        cout<<ordering[i]<<" ";
    }
    return 0;
}