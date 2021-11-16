/*
3
16 16 16
2
2 3
2
2 1
*/



#include<bits/stdc++.h>
using namespace std;
int min_number_of_steps_to_reach_array(int arr[], int n){
    int min_steps = 0;
    while(1){
        int i;
        int zero_count = 0;
        for(i = 0; i<n; i++){
            if(arr[i] & 1){
                break;
            }
            if(arr[i] == 0){
                zero_count++;   
            }
        }
        if(zero_count == n){
            return min_steps;
        }
        // cout<<i<<" "<<n<<endl;
        if(i == n){
            for(int j = 0; j<n; j++){
                arr[j] = arr[j]/2;
            }
            min_steps++;
        }
        for(int j = 0; j<n; j++){
            if(arr[j] & 1){
                arr[j] = arr[j] - 1;
                min_steps++;
            }
        }
    }
}
int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<min_number_of_steps_to_reach_array(arr, n);
    return 0;
}