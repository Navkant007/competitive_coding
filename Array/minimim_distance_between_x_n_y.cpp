/*
12
3 5 4 2 6 3 0 0 5 4 8 3
3 6
3
3 4 5
3 5
*/

#include<bits/stdc++.h>
using namespace std;
int get_minimum_distance(int arr[], int n, int x, int y){
    int p = -1;
    int temp = 0;
    int min_dis = INT_MAX;
    for(int i = 0; i<n; i++){
        if(arr[i] == x || arr[i] == y){
            if(p != -1 && arr[i] != arr[p]){
                if(min_dis > i - p){
                    min_dis = i - p;
                }
            }
            p = i;
        }
    }
    return min_dis;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int x,y;
    cin>>x>>y;
    cout<<get_minimum_distance(arr, n, x, y);
    return 0;
}