4 6                                                                                                                                    
0 1                                                                                                                                    
0 2                                                                                                                                    
1 2                                                                                                                                    
2 0                                                                                                                                    
2 3                                                                                                                                    
3 3

////

13 15
0 7
0 9
0 11
7 11
7 6
7 3
6 5
3 4
2 3
2 12
12 8
8 1
1 10
10 9
9 8
0 5


#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000]; 
int main(){
    int nodes, edges, x, y;
    cin>>nodes>>edges;
    for(int i =0; i<edges; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0;i<nodes;i++){
        visited[i] = false;
    }
    queue <int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        // cout<<"hiii"<<endl;
        int p = q.front();
        cout<<p<<" ";
        // cout<<"hiii"<<endl;
        q.pop();
        for(int v = 0; v<adj[p].size(); v++){
            // cout<<adj[p][v]<<"gg"<<endl;
            if(visited[adj[p][v]] == false){
                visited[adj[p][v]] = true;
                q.push(adj[p][v]);
            }
        }
    }
    return 0;
}












#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e, x, y;
    cin>>n>>e;
    vector<int> adj[1000];
    bool visited[n];
    for(int i = 0; i<e; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    int s, d;
    // cin>>s>>d;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int a = q.front();
        cout<<a<<" ";
        q.pop();
        for(int i = 0; i<adj[a].size(); i++){
            if(!visited[adj[a][i]]){
                q.push(adj[a][i]);
                visited[adj[a][i]] = true;
            }
        }
    }
    return 0;
}



0 7 9 11 6 3 10 8 5 4 2 1 12