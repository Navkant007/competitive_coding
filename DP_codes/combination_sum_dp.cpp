// combination sum
//2                                                                                                                                      
//2 3                                                                                                                                  
//5


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n; 
    int c[n];
    for(int i = 0; i<n; i++){
        cin>>c[i]; //1 2 3
    }
    int sum;
    cin>>sum; //4
    int dp[sum+1] = {0};
    dp[0] = 1;
    for(int i = 1; i<=sum; i++){
        int k = 0;
        while(k<n){
            if(i-c[k]<0)
            break;
            dp[i]= dp[i] + dp[i-c[k]];
            k++;
        }
        cout<<"i-"<<i<<endl;
        for(int i = 0; i<=sum; i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[sum];
    return 0;
}
