/*
Let us calculate initial value of i*arr[i] with no rotation
R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]

After 1 rotation arr[n-1], becomes first element of array, 
arr[0] becomes second element, arr[1] becomes third element
and so on.
R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]

R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]

After 2 rotations arr[n-2], becomes first element of array, 
arr[n-1] becomes second element, arr[0] becomes third element
and so on.
R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n-1)*arr[n-3]

R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]

If we take a closer look at above values, we can observe 
below pattern

Rj - Rj-1 = arrSum - n * arr[n-j]

Where arrSum is sum of all array elements, i.e., 

arrSum = ∑ arr[i]
        0<=i<=n-1 
        
        
10
10 1 2 3 4 5 6 7 8 9
*/

#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[], int n){
    int arr_sum = 0;
    int m_sum = 0;
    for(int i = 0;i <n; i++){
        arr_sum += arr[i];
        m_sum = m_sum + i * arr[i];
    }
    int new_m_sum = m_sum;
    for(int i = 1; i<n; i++){
        new_m_sum = new_m_sum + arr_sum - n * arr[n-i];
        if(new_m_sum > m_sum){
            m_sum = new_m_sum;
        }
    }
    return m_sum;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<<max_sum(arr, n);
    return 0;
}