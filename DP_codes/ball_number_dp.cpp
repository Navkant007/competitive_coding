#include<bits/stdc++.h>
using namespace std;
int get_ball_number(int n){
    long long int a[n+1][n+1];
    a[0][0] = 1;
    // cout<<n<<"-gg-"<<a[n][0]<<endl;
    for(int i = 1; i<=n; i++){
        a[i][0] = a[i-1][i-1];
        for(int j = 1;j<=i;j++){
            a[i][j] = a[i-1][j-1] +a[i][j-1];
        }
    }
    return a[n][0];
    // int bell[n+1][n+1];
    // bell[0][0] = 1;
    // for (int i=1; i<=n; i++)
    // {
    //   // Explicitly fill for j = 0
    //   bell[i][0] = bell[i-1][i-1];
    
    //   // Fill for remaining values of j
    //   for (int j=1; j<=i; j++)
    //      bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
    // }
    // return bell[n][0];
}
int main(){
    int n;
    cin>>n;
    cout<<get_ball_number(n);
    return 0;
}
