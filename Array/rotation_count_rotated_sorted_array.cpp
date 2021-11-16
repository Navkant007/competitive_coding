/*
6
15 18 2 3 6 12
5
7 9 11 12 5
5
7 9 11 12 15
*/

#include<bits/stdc++.h>
using namespace std;
int find_pivot(int low, int high, int arr[]){
    if(low == high){
        return low;
    }
    if(low>high){
        return 0;
    }
    int mid = low + (high - low)/2;
    if(mid<high && arr[mid] > arr[mid+1]){
        return mid+1;
    }
    if(low<mid && arr[mid-1]> arr[mid]){
        return mid;
    }
    if(arr[mid] < arr[high]){
        return find_pivot(low, mid-1, arr);
    }
    else{
        return find_pivot(mid+1, high, arr);
    }
}
int count_rotations(int arr[], int n){
    int pivot = find_pivot(0, n-1, arr);
    return pivot;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    cout<<count_rotations(arr, n);
    return 0;
}