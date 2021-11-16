/*
7
3 7 90 20 10 50 40
3
*/

#include<bits/stdc++.h>
using namespace std;
int get_subarray_avg(int arr[], int n, int k){
    int prifix_sum[n];
    prifix_sum[0] = arr[0];
    for(int i = 1; i<n; i++){
        prifix_sum[i] = prifix_sum[i-1] + arr[i];
    }
    int min_sum = 0;
    for(int i = 0; i<k; i++)
        min_sum = min_sum + arr[i];
    int curr_sum = min_sum;
    for(int i = k; i<n ;i++){
        curr_sum = curr_sum + arr[i] - arr[i-k];
        if(curr_sum< min_sum){
            min_sum = curr_sum;
        }
    }
    return min_sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int avg = get_subarray_avg(arr, n, k);
    cout<<avg/k;
    return 0;
}
