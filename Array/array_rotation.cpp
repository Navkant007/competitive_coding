/*
7
1 2 3 4 5 6 7
2
*/


#include<bits/stdc++.h>
using namespace std;

int find_gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        find_gcd(b, a%b);
    }
}

void array_rotation(int n, int d, int arr[]){
    d = d % n;
    int gcd = find_gcd(n, d);
    for(int i = 0; i<gcd; i++){
        int temp = arr[i];
        int j = i;
        while(1){
            int k = j + d;
            if(k >= n){
                k = k - n;
            }
            if(k == i){
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
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