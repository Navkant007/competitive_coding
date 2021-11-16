/*
9
5 8 1 4 2 9 3 7 6
*/

#include<bits/stdc++.h>
using namespace std;
int rearrange_small_large_2ndsmall_2ndlarge(int arr[], int n){
    sort(arr, arr+n);
    int i = 1;
    int j = n-1;
    int new_arr[n];
    int count = 0;
    for(int i = 0, j = n-1; i<=n/2 || j>n/2; i++, j--){
        new_arr[count++] = arr[i];
        new_arr[count++] = arr[j];
    }
    for(int i = 0; i<n; i++){
        arr[i] = new_arr[i];
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    rearrange_small_large_2ndsmall_2ndlarge(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}