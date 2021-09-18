/*
3
20 -5 -1
3

4
10 -10 20 -40
6
*/


#include<bits/stdc++.h>
using namespace std;
int get_kth_Largest_Sum(int arr[], int n, int k){
    int sum[n+1];
    sum[0] = 0;
    sum[1] = arr[0];
    for(int i = 2; i<=n; i++){
        sum[i] = sum[i-1] + arr[i-1];
    }
    priority_queue<int, vector<int>, greater<int>> Q;
    for(int i = 1; i<=n;i++){
        for(int j = i; j<=n; j++){
            int x = sum[j] - sum[i-1];
            if(Q.size() < k){
                Q.push(x);
            }
            else{
                if(Q.top()<x){
                    Q.pop();
                    Q.push(x);
                }
            }
        }
    }
    return Q.top();
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<get_kth_Largest_Sum(arr, n, k);
    return 0;
}