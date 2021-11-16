/*
aabbcc
2
*/

#include<bits/stdc++.h>
using namespace std;

bool check_map(int hash_map[], int k){
    for(int i = 0; i<26; i++){
        if(hash_map[i] && hash_map[i] != k){
            return false;
        }
    }
    return true;
}

int count_number_of_substring_with_count_of_each_character_as_k(string s, int n, int k){
    int count = 0;
    int hash_map[26];
    for(int i = 0;i <n; i++){
        memset(hash_map, 0, sizeof(hash_map));
        for(int j = i; j<n; j++){
            int index = s[j]-'a';
            hash_map[index]++;
            if(hash_map[index]>k){
                break;
            }
            else if(hash_map[index] == k && check_map(hash_map, k) == true){
                count++;
            }
        }
    }
    return count;
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<count_number_of_substring_with_count_of_each_character_as_k(s, s.size(), k);
    return 0;
}