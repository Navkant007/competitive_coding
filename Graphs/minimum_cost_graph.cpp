#include<bits/stdc++.h>
using namespace std;
int call_dfs(int u, bool visited[], vector<int> adj[], int count, int colour[]){
    if(visited[u]){
        return 0;
    }
    visited[u] = true;
    colour[u] = count;
    for(int v = 0; v<adj[u].size(); v++){
        if(!visited[adj[u][v]]){
            call_dfs(adj[u][v], visited, adj, count, colour);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, c_lib, c_road;
        cin>>n>>m>>c_lib>>c_road;
        int x, y;
        vector<int> adj[2*m];
        for(int i = 0; i<m; i++){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool visited[n+1];
        int colour[n+1];
        for(int i = 1; i<=n; i++){
            visited[i] = false;
            colour[i] = -1;
        }
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                count++;
                colour[i] = count;
                call_dfs(i, visited, adj, count, colour);
            }
        }
        int cost_of_making_lib_at_each_city = n * c_lib;
        int final_cost = 0;
        for(int k = 1; k<= count; k++){
            int city_group_count = 0;
            for(int j = 1; j<n+1; j++){
                if(colour[j] == k){
                    city_group_count++;
                    // cout<<j<<" ";
                }
            }
            // cout<<endl<<city_group_count;
            final_cost = final_cost + (city_group_count - 1) * c_road + c_lib;
        }
        // cout<<endl<<"r->"<<final_cost<<"l->"<<cost_of_making_lib_at_each_city;
        if(final_cost> cost_of_making_lib_at_each_city){
            cout<<cost_of_making_lib_at_each_city<<endl;
        }
        else{
            cout<<final_cost<<endl;
        }
    }
    return 0;
}