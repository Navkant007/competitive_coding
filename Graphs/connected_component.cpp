5 3
0 1
2 3
3 4


#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];

void call_dfs(int v){
    visited[v] = true;
    for(int i = 0; i<adj[v].size(); i++){
        if(visited[adj[v][i]] == false){
            call_dfs(adj[v][i]);
        }
    }
}

int main(){
    int edges, nodes,x, y, connected_component = 0;
    cin>>nodes;
    cin>>edges;
    for(int i  = 0; i<edges;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i<=nodes;i++){
        visited[i] = false;
    }
    for(int i = 1; i<=nodes; i++){
        if(visited[i] == false){
            connected_component++;
            call_dfs(i);
        }
    }
    cout<<connected_component;
    return 0;
}



// Advanced Code 


#include<bits/stdc++.h>
using namespace std;
vector<int> g[100];
bool visited[100];
vector<int> vec[100];

void dfs(int u, int count){
    if(visited[u])
    return;
    visited[u] = true;
    cout<<u<<"-->";
    vec[count].push_back(u);
    for(int v = 0; v<g[u].size(); v++){
        if(!visited[g[u][v]]){
            dfs(g[u][v], count);
        }
    }
}
int main(){
    int n, e;
    cin>>n>>e;
    int x, y;
    
    for(int i = 0; i<e; i++){
        cin>>x>>y;
        g[x].push_back(y);
        // g[y].push_back(x);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<g[i].size(); j++){
            cout<<i<<"->"<<g[i][j]<<" "<<endl;
        }
    }
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            count++;
            dfs(i, count);
            cout<<endl;
        }
    }
    cout<<"this is count ="<<count<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<vec[i].size(); j++){
            cout<<i<<"->"<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}