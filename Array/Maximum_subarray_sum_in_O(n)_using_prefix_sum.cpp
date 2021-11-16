/*
8
-2 -3 4 -1 -2 1 5 -3

8
4 -8 9 -4 1 -8 -1 6
*/

#include<bits/stdc++.h>
using namespace std;
int maximum_contiguas_subarry_sum(int arr[], int n){
    int sum[n];
    sum[0] = arr[0];
    for(int i = 1; i<n; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    int minimum_sum = 0;
    int maximum_sum = INT_MIN;
    for(int i = 0; i<n; i++){
        maximum_sum = max(maximum_sum, sum[i] - minimum_sum);
        minimum_sum = min(minimum_sum, sum[i]);
    }
    return maximum_sum;
}
int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maximum_contiguas_subarry_sum(arr, n);
    return 0;
}