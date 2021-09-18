/*
6
7 11 13 5 15 8
*/


#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[largest]<arr[l]){
        largest = l;
    }
    if(r<n && arr[largest]<arr[r]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n){
    for(int i = (n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(int i = n-1; i>=0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    heap_sort(arr, n);
    return 0;
}