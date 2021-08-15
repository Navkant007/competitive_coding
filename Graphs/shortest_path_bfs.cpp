/*
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
*/



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
        // adj[y].push_back(x);
    }
    int prev[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
        prev[i] = -1;
    }
    int s, d;
    cin>>s>>d;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    prev[s] = -1;
    while(!q.empty()){
        int a = q.front();
        cout<<a<<" ";
        q.pop();
        for(int i = 0; i<adj[a].size(); i++){
            if(!visited[adj[a][i]]){
                q.push(adj[a][i]);
                visited[adj[a][i]] = true;
                prev[adj[a][i]] = a;
            }
        }
    }
    cout<<"gg";
    cout<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<<prev[i]<<" ";
    // }
    vector<int> path;
    int crawl = d;
    path.push_back(crawl);
    while(prev[crawl] != -1){
        crawl = prev[crawl];
        path.push_back(crawl);
    }
    if(path[path.size()-1] != s){
        cout<<"no path exist";
        return 0;
    }
    cout<<endl;
    for(auto i = path.rbegin(); i!= path.rend(); i++){
        cout<<*i<<" ";
    }
    return 0;
}