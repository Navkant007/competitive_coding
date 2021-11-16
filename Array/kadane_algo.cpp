/*
8
-2 -3 4 -1 -2 1 5 -3
*/

#include<bits/stdc++.h>
using namespace std;
int kadanes_algorithms(int arr[], int n){
    int max_till_now = 0;
    int max_current = 0;
    for(int i = 0; i<n; i++){
        max_current = max_current + arr[i];
        // cout<<max_current<<" ";
        if(max_current < 0){
            max_current = 0;
        }
        if(max_current > max_till_now){
            max_till_now = max_current;
        }
    }
    // cout<<endl;
    return max_till_now;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<kadanes_algorithms(arr, n);
    return 0;
}