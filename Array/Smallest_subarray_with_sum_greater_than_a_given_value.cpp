/*
6
1 4 45 6 0 19
51
5
1 10 5 2 7
9
10
1 11 100 1 0 200 3 2 1 250
280
*/
#include<bits/stdc++.h>
using namespace std;
int get_minimum_subarray_with_sum_than_greater_value(int arr[], int n, int k){
    int current_sum = 0;
    int min_len = INT_MAX;
    int i = 0, j = 0;
    while(j<n){
        while(current_sum <= k && j<n){
            current_sum += arr[j++];
        }
        while(current_sum>k && i<n){
            if(min_len > j-i){
                min_len = j-i;
            }
            current_sum -= arr[i++];
        }
    }
    return min_len;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<get_minimum_subarray_with_sum_than_greater_value(arr, n, k);
    return 0;
}