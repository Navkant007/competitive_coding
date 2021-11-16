/*
5
3 1 2 2 5
*/
#include<bits/stdc++.h>
using namespace std;
void even_pos_greater_then_odd(int arr[], int n){
    for(int i = 1; i<n; i++){
        if(i%2 == 0){
            if(arr[i]>arr[i-1]){
                swap(arr[i], arr[i-1]);
            }
        }
        else{
            if(arr[i-1]> arr[i]){
                swap(arr[i], arr[i-1]);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    even_pos_greater_then_odd(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}