/*
6
1 12 -5 -6 50 3
4
*/
#include<bits/stdc++.h>
using namespace std;
void maximum_average_subarray_of_k_length(int arr[], int n, int k){
    int current_sum = 0;
    int max_sum = 0;
    int i = 0, j = 0;
    for(int i = 0;i<k; i++){
        current_sum += arr[i];
    }
    max_sum = current_sum;
    int x = 0, y = k-1;
    for(int i = k; i<n; i++){
        current_sum = current_sum +arr[i] - arr[i - k];
        if(current_sum> max_sum){
            max_sum = current_sum;
            x = i-k+1;
            y = i;
        }
    }
    cout<<x<<" "<<y;
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
    maximum_average_subarray_of_k_length(arr, n, k);
    return 0;
}