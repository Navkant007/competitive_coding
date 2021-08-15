#include<bits/stdc++.h>
using namespace std;

void rotate_array(int a[], int start, int end){
    while(start<end){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
    
}

void left_rotated(int a[], int d, int n){
    if(d == 0)
    return;
    d = d % n;
    rotate_array(a, 0, d-1);
    rotate_array(a, d, n-1);
    rotate_array(a, 0, n-1);
    
}

void print_rotated(int a[], int n){
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i <n; i++){
        cin>>a[i];
    }
    int d;
    cin>>d;
    left_rotated(a, d, n);
    print_rotated(a, n);
    return 0;
}