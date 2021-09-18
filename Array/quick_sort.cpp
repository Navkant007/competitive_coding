/*
6
4 8 2 7 10 1
*/


#include<bits/stdc++.h>
using namespace std;

int quick_sort_util(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;
    for(int j = low; j<high; j++){
        if(arr[j]<pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}


void quick_sort(int arr[], int low, int high){
    if(low<high){
        int pi = quick_sort_util(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    quick_sort(arr, 0, n-1);
    for(int i = 0; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}