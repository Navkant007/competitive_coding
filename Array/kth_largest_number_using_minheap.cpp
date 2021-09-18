/*
6
12 11 13 5 6 7
3
*/


#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i){
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[smallest]>arr[l]){
        smallest = l;
    }
    if(r<n && arr[smallest]>arr[r]){
        smallest = r;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void extract_min(int arr[], int &j, int n){
    if(j == 0){
        cout<<INT_MAX<<endl;
    }
    int root = arr[0];
    if(j>1){
        arr[0] = arr[j-1];
        heapify(arr, n, 0);
    }
    j--;
}
void kth_largest_number(int arr[], int n, int k){
    for(int i = (n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int j = n;
    for(int i = 0; i<n-k;i++){
        extract_min(arr, j, n);
    }
    for(int i = 0;i <n;i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    kth_largest_number(arr, n, k);
    cout<<arr[0];
    return 0;
}