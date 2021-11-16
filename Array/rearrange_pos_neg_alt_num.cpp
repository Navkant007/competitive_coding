/*
10
-5 -2 5 2 4 7 1 8 0 -8
*/

#include<bits/stdc++.h>
using namespace std;
void rearrange_array_pos_neg_alt(int arr[], int n){
    int j = 0;
    for(int i = 0; i<n ;i++){
        if(arr[i]<0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    int pos = j, neg = 0;
    while(pos<n && neg<pos && arr[neg]<0){
        swap(arr[neg], arr[pos]);
        pos++;
        neg+=2;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    rearrange_array_pos_neg_alt(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}