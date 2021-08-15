/*
8                                                                                  
5 6 7 8 9 1 2 3                                                                    
5
*/


#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[], int low, int high, int key){
    int mid = low + (high - low)/2;
    if(high<low){
        return -1;
    }
    if(key == a[mid]){
        return mid;
    }
    if(a[mid]>key){
        return binary_search(a, low, mid-1, key);
    }
    return binary_search(a, mid+1, high, key);
}
int find_pivot(int a[], int start, int end){
    if(end == -1){
        return -1;
    }
    if(start == end){
        return start;
    }
    int mid = start + (end- start)/2;
    if(mid<end && a[mid] > a[mid+1]){
        return mid;
    }
    if(mid>start && a[mid -1 ] > a[mid] ){
        return mid;
    }
    if(a[start] >= a[mid]){
        return find_pivot(a, start, mid-1);
    }
    return find_pivot(a, mid+1, end);
}
int perform_binary_search(int a[], int n, int key){
    if(n == 0)
        return -1;
    int pivot = find_pivot(a, 0, n-1);
    cout<<pivot<<endl;
    if(pivot == -1){
        return binary_search(a, 0, n-1, key);
    }
    if(a[pivot] == key){
        return key;
    }
    if(a[0] <= key){
        cout<<pivot-1<<endl;
        return binary_search(a, 0, pivot-1, key);
    }
    cout<<pivot+1<<" "<<a[pivot+1]<<endl;
    return binary_search(a, pivot+1, n-1, key);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    int index = perform_binary_search(a, n, key);
    cout<<index+1;
    return 0;
}
