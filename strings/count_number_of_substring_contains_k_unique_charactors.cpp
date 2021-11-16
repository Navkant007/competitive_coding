/*
abc
2
aba
2
abcbaa
3
*/



#include<bits/stdc++.h>
using namespace std;
int count_number_of_substring_contains_k_unique_charactors(string s, int n, int k){
    int ans = 0;
    int hash_map[26];
    for(int i = 0; i<n; i++){
        int dist_count = 0;
        memset(hash_map, 0, sizeof(hash_map));
        for(int j = i; j<n; j++){
            if(hash_map[s[j] - 'a'] == 0){
                dist_count++;   
            }
            hash_map[s[j] - 'a']++;
            if(dist_count == k){
                ans++;
            }
            if(dist_count>k){
                break;
            }
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<count_number_of_substring_contains_k_unique_charactors(s, s.size(), k);
    return 0;
}