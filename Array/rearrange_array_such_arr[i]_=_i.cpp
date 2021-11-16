/*
10
-1 -1 6 1 9 3 2 -1 4 -1
*/
#include<bits/stdc++.h>
using namespace std;
void rearrange_array(int arr[], int n){
	int i = 0;
	while(i<n){
        if(i != arr[i] && arr[i] >= 0){
            int temp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = temp;
        }
        else{
            i++;
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
    rearrange_array(arr, n);
    
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}