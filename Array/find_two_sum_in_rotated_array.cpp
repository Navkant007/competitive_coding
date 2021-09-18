/*
6
11 15 6 8 9 10
16
*/


#include<bits/stdc++.h>
using namespace std;

int find_pivot(int arr[], int low, int high){
    if(low>high){
        return -1;
    }
    if(low == high){
        return low;
    }
    int mid = low + (high - low)/2;
    if(mid < high && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(mid > low && arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[low] >= arr[mid]){
        return find_pivot(arr, low, mid-1);
    }
    return find_pivot(arr, mid+1, high);
}

void pair_sum(int arr[], int sum, int n){
    int pivot = find_pivot(arr, 0, n);
    cout<<pivot<<endl;
    int l = (pivot+1) % n;
    int r = pivot;
    while(l != r){
        if(arr[l] + arr[r] == sum){
            cout<<"1->"<<arr[l]<<" 2->"<<arr[r]<<endl;
        }
        if(arr[l]+arr[r] > sum){
            r = (r + n - 1) %n;
        }
        else{
            l = (l + 1) % n;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    pair_sum(arr, sum, n);
    return 0;
}