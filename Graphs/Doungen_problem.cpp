#include<bits/stdc++.h>
using namespace std;
int main(){
    int R,C;
    cin>>R>>C;
    int a[R][C];
    for(int i = 0;i<R;i++){
        for(int j  = 0; j<C; j++){
            cin>>a[i][j];
        }
    }
    int move_count = 0;
    int nodes_left_in_layer = 1;
    int nodes_in_next_layers = 0;
    bool reached_end = false;
    int visited[R][C];
    for(int i = 0;i<R;i++){
        for(int j  = 0; j<C; j++){
            visited[i][j] = false;
        }
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int sr = 0;
    int sc = 0;
    queue<int> qr, qc;
    qr.push(sr);
    qc.push(sc);
    visited[sr][sc] = true;
    while(!qc.empty()){
        int r = qr.front();
        int c = qc.front();
        qr.pop();
        qc.pop();
        if(a[r][c] == 'E'){
            reached_end = true;
            break;
        }
        for(int i = 0; i<4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr<0 || cc<0 || rr>=R || cc >=C){
                continue;
            }
            if(visited[rr][cc] == true){
                continue;
            }
            if(a[rr][cc] == '#'){
                continue;
            }
            qr.push(rr);
            qc.push(cc);
            nodes_in_next_layers++;
        }
        nodes_left_in_layer--;
        if(nodes_left_in_layer == 0){
            nodes_left_in_layer = nodes_in_next_layers;
            move_count;
        }
    }
    if(reached_end)
        cout<<move_count;
    else
        cout<<"There is no path exist";
    return 0;
}