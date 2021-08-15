/*
There is one ap - 1,2,3,4,6
*/
//sum = n*(n+1)/2 - given_ap;

// a+(p)*d;



#include<bits/stdc++.h>
using namespace std;

int call_binary(int ap[], int low, int high, int d, int a){
    int mid = (high + low)/2;
    int mid_value = a+mid*d;
    if(low==high){
        return low+2;
    }
    if(mid_value<ap[mid]){
        return call_binary(ap, low, mid, d,a);
    }
    else{
        return call_binary(ap, mid, high, d,a);
    }
}


int main(){
    int n;
    cin>>n;
    int ap[n];
    for(int i = 0;i<n; i++){
        cin>>ap[i];
    }
    int d;
    if(ap[1] -ap[0] < ap[2] -ap[1])
        d = ap[1] -ap[0];
    else
        d = ap[2] -ap[1];
    
    int low = 0;
    int high = n-1;
    int a = ap[0];
    cout<<call_binary(ap, low, high, d, a);
    return 0;
}
