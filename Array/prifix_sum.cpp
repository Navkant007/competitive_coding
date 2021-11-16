/*
4
10 4 16 20
*/

#include<bits/stdc++.h>
using namespace std;
void prifix_sum(int arr[], int n, int prifix_sum_arr[]){
    prifix_sum_arr[0] = arr[0];
    for(int i = 1; i<n; i++){
        prifix_sum_arr[i] = arr[i] + prifix_sum_arr[i-1];
        // cout<< prifix_sum_arr[i]<<endl;
    }
}


int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int prifix_sum_arr[n];
    prifix_sum(arr, n, prifix_sum_arr);
    for(int i = 0; i<n; i++){
        cout<<prifix_sum_arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}