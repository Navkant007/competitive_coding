// max sum go up right , right , go down
4 4
10 33 13 15
22 21 4 1
5 0 2 3
0 6 14 2


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int a[n][m];
    int dp[n][m] = {0};
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    for(int col = 0; col<m; col++){
        for(int row = 0; row< n; row++){
            int top_left, left, left_bot;
            if(col == 0 or row == 0)
                top_left = 0;
            else
                top_left = dp[row-1][col-1];
            if(col == 0){
                left = 0;
            }
            else{
                left = dp[row][col-1];
            }
            if(row == n-1){
                left_bot = 0;
            }
            else{
                left_bot = dp[row+1][col-1];
            }
            dp[row][col] = a[row][col] + max(top_left, max(left, left_bot));
        }
    }
    int max = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int row = 0; row<n; row++){
        cout<<dp[row][m-1]<<endl;
        if(dp[row][m-1]>max){
            max = dp[row][m-1];
            // cout<<max<<endl;
        }
    }
    // }
    // cout<<endl;
    cout<<max;
}



