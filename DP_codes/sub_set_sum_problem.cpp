//subset sem problem

#include<bits/stdc++.h>
using namespace std;
int tab[2000][2000];
bool check_sum(int a[], int n, int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(sum < a[n-1]){
        return check_sum(a, n-1, sum);
    }
    return check_sum(a, n-1, sum - a[n-1]) || check_sum(a, n-1, sum);
}


    0    1    2    3    4    5    6

0   T    F    F    F    F    F    F

3   T    F    F    T    F    F    F
     
4   T    F    F    T    T    F    F   
      
5   T    F    F    T    T    T    F

2   T    F    T    T    T    T    T

a = {3, 4, 5, 2}
sum = 6

bool dp_check_sum(int a[], int n, int sum){
    bool subset[n+1][sum+1];
    for(int i = 0; i<n+1;i++){
        subset[i][0] = true;
    }
    for(int i = 1; i<sum+1; i++){
        subset[0][i] = false;
    }
    for(int i = 1 ; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(a[i-1] > j){
                subset[i][j] = subset[i-1][j];
            }
            if(a[i-1]<=j){
                subset[i][j] = subset[i-1][j] || subset[i-1][j - a[i-1]];
            }
        }
    }
    return subset[n][sum];
}

bool op_check_sum(int a[], int n, int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(tab[n-1][sum] != -1){
        return tab[n-1][sum];
    }
    if(a[n-1]> sum){
        return tab[n-1][sum] = op_check_sum(a, n-1, sum);
    }
    return tab[n-1][sum] = op_check_sum(a, n-1, sum) || op_check_sum(a, n-1, sum - a[n-1]);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    memset(tab, -1, sizeof(tab));
    int sum;
    cin>>sum;
    bool result;
    // result = check_sum(a, n, sum);
    // result = dp_check_sum(a, n, sum);
    result = op_check_sum(a, n, sum);
    cout<<result<<endl;
}

