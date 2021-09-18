#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[largest]<arr[l]){
        largest = l;
    }
    if(r<n && arr[largest]<arr[r]){
        largest = r;
    }
    if(i != largest){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int get_max_candy(int arr[], int n){
    for(int i = (n/2) - 1; i>=0;i--){
        heapify(arr, n, i);
    }
    int sum = 0;
    for(int i = 0;i<3; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        sum = sum + arr[0]/2;
        arr[0] = arr[0]/2;
        heapify(arr, n, 0);
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<<get_max_candy(arr, n);
    return 0;
}
