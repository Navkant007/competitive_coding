/*
8
-1 5 0 -2 8 3 0 -9
*/

#include<bits/stdc++.h>
using namespace std;
void segrigate(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<high){
        if(arr[mid] < 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 0){
            mid++;
        }
        else{
            swap(arr[high], arr[mid]);
            high--;
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
    segrigate(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}