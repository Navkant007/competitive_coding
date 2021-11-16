/*
5
1 2 90 10 110
7
2 3 10 6 4 8 1
6
7 9 5 6 3 2
*/

#include<bits/stdc++.h>
using namespace std;
int max_profit(int arr[], int n){
    int min_element = arr[0];
    int max_diff = (arr[1] - arr[0]);
    for(int i = 1; i<n; i++){
        if((arr[i] - min_element) > max_diff){
            max_diff = arr[i] - min_element;
        }
        if(min_element > arr[i]){
            min_element = arr[i];
        }
    }
    return max_diff;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<max_profit(arr, n);
    return 0;
}
