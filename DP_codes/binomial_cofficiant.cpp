#include<bits/stdc++.h>
using namespace std;
int binomial_coff(int n, int k){
    int a[n+1][n+1];
    memset(a, 0, sizeof(a));
    a[0][0] =1;
    for(int i = 1; i<=n; i++){
        a[i][0] = 1;
        for(int j = 1; j<=i; j++){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
            cout<<"i-"<<i<<"j-"<<j<<endl<<a[i-1][j-1]<<" - "<<a[i-1][j]<<endl;
        }
    }
    return a[n][k];
    
}
int main(){
    int n, k;
    cin>>n>>k;
    cout<<binomial_coff(n, k);
    return 0;
}