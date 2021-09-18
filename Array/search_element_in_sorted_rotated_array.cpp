/*
10
4 5 6 7 8 9 10 1 2 3
2
*/


#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int low, int high, int num){
    int mid = low + (high - low)/2;
    if(num == arr[mid]){
        return mid;
    }
    if(low > high){
        return -1;
    }
    if(num < arr[mid]){
        return binary_search(arr, low, mid -1, num);
    }
    return binary_search(arr, mid+1, high, num);
}


int find_pivot(int arr[], int low, int high){
    if(low>high){
        return -1;
    }
    if(low==high){
        return low;
    }
    int mid = (low+high)/2;
    if(mid < high && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(mid < high && arr[mid] < arr[mid-1]){
        return mid-1;
    }
    if(arr[low] >= arr[mid]){
        return find_pivot(arr, low, mid);
    }
    return find_pivot(arr, mid+1, high);
}


int find_index(int arr[], int n, int num){
    int pivot = find_pivot(arr,0, n);
    if(pivot == -1){
        return binary_search(arr, 0, n, num);
    }
    if(arr[pivot] == num){
        return pivot;
    }
    if(arr[0]<=num){
        return binary_search(arr, 0, pivot-1, num);
    }
    else{
        return binary_search(arr, pivot+1, n, num);
    }
}



int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int num;
    cin>>num;
    int ans = find_index(arr, n, num);
    cout<<ans;
    return 0;
}