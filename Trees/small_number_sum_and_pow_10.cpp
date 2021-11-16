/*
5

20
*/
#include<bits/stdc++.h>
using namespace std;
string get_Smallest_number_with_sum_of_digits_as_N_and_divisible_by_10(int n){
    string s = "";
    if(n==0){
        return s;
    }
    if(n%9 != 0){
        s = s + char(n%9 + 48);
    }
    for(int i = 1; i<=(n/9); i++){
        s = s + "9";
    }
    for(int i = 1; i<=n; i++){
        s = s + "0";
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    cout<<get_Smallest_number_with_sum_of_digits_as_N_and_divisible_by_10(n);
    // for(int i = 1; i< 100; i++){
    //     cout<<char(i)<<endl;
    // }
    return 0;
}