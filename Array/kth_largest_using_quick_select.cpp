/*
7
12 3 5 7 4 19 26
6
*/
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int j = low;
    for(int i = low; i<high ;i++){
        if(arr[i]>pivot){
            swap(arr[j], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[high]);
    return j;
    
}
int kth_largest_number(int arr[], int low, int high, int k){
    if(k>0 && k<=high-low+1){
        int pivot = partition(arr, low, high);
        if(pivot == k-1){
            return arr[pivot];
        }
        if(pivot < k-1){
            kth_largest_number(arr, pivot+1, high, k);
        }
        else{
            kth_largest_number(arr, low, pivot-1, k);
        }
    }
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
    int pp = kth_largest_number(arr,0, n-1, k);
    cout<<pp;
    return 0;
}