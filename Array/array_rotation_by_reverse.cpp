/*
7
1 2 3 4 5 6 7
2
*/


#include<bits/stdc++.h>
using namespace std;

void reserver_array(int s, int e, int arr[]){
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}


void array_rotation(int n, int d, int arr[]){
    d = d %n;
    reserver_array(0,d-1,arr);
    reserver_array(d,n-1,arr);
    reserver_array(0,n-1,arr);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int d;
    cin>>d;
    array_rotation(n, d, arr);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}