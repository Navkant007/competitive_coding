#include<bits/stdc++.h>
using namespace std;

void rotate_by_one(int a[], int n){
    int temp;
    temp = a[0];
    for(int i = 1; i<n; i++){
        a[i-1] = a[i];
    }
    a[n-1] = temp;
}

void print_rotated(int a[], int d, int n){
    for(int i = 0; i<d; i++)
        rotate_by_one(a, n);
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
    print_rotated(a, d, n);
    return 0;
}