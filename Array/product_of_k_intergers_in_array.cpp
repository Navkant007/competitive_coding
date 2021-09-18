/*
6
198 76 544 123 154 675
2

6
11 8 5 7 5 100
4
*/

#include<bits/stdc++.h>
using namespace std;

void get_sum(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }
    int count = 0, ans = 1;
    while(!pq.empty() && count<k){
        ans = ans * pq.top();
        pq.pop();
        count++;
    }
    cout<<ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    get_sum(arr, n, k);
    return 0;
}