//minimum possible coins Problem 

3                                                                                                                                      
1 2 5                                                                                                                                  
11

#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
int main(){
    int n;
    cin>>n; 
    int c[n];
    for(int i = 0; i<n; i++){
        cin>>c[i]; //1 2 3
    }
    int sum;
    cin>>sum; //4
    int dp[sum+1];
    dp[0] = 0;
    for(int i = 1; i<=sum; i++)
    {
        dp[i] = 10000;
        // cout<<dp[i]<<" ";
    }
    cout<<endl;
    for(int i = 1; i<=sum; i++){
        int k = 0;
        while(k<n){
            if(i-c[k]<0)
            break;
            dp[i]= min(dp[i], dp[i-c[k]] + 1);
            k++;
        }
        // cout<<"i-"<<i<<endl;
        // for(int i = 0; i<=sum; i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
    }
    cout<<dp[sum];
    return 0;
}

