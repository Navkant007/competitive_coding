/*
this is a test string
tist
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> all_sub_strings(string s, int n){
    vector<string> sub_strs;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=n-i; j++){
            sub_strs.push_back(s.substr(i,j));
        }
    }
    return sub_strs;
}
int main(){
    string s;
    getline(cin, s);
    string pat;
    getline(cin, pat);
    vector<string> sub_strs = all_sub_strings(s, s.size());
    int max_len = INT_MAX;
    string ans = "";
    cout<<pat.size()<<endl;
    for(int i = 0; i<sub_strs.size(); i++){
        int count = 0; 
        for(int j = 0; j<pat.size(); j++){
            if(sub_strs[i].find(pat[j]) != string::npos){
                count++;
            }
        }
        if(count == pat.size()){
            // cout<<count<<endl;
            // cout<<sub_strs[i]<<endl;
            if(sub_strs[i].size() < max_len){
                ans = sub_strs[i];
                max_len = sub_strs[i].size();
            }
        }
    }
    cout<<ans;
    return 0;
}



// # ----------------------------------- new code for same problem



#include<bits/stdc++.h>
using namespace std;
const int no_of_chars = 256;
string findSubString(string str, string ptr){
    int n = str.length();
    int m = ptr.length();
    if(m>n){
        return "No pattarn exist!";
    }
    int has_str[no_of_chars] = {0};
    int has_ptr[no_of_chars] = {0};
    for(int i = 0; i<m; i++){
        has_ptr[ptr[i]]++;
    }
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;
    for(int i = 0; i<n; i++){
        has_str[str[i]]++;
        if(has_str[str[i]] <= has_ptr[str[i]]){
            count++;
        }
        if(count == m){
            while(has_str[str[start]] > has_ptr[str[start]] || has_ptr[str[start]] == 0){
                if(has_str[str[start]] > has_ptr[str[start]]){
                    has_str[str[start]]--;
                }
                start++;
            }
            int len_window = i - start + 1;
            if(min_len> len_window){
                min_len = len_window;
                start_index = start;
            }
        }
    }
    if (start_index == -1) {
        cout << "No such window exists";
        return "";
    }
    return str.substr(start_index, min_len);
}
int main(){
    string str;
    string ptr;
    getline(cin,str);
    getline(cin,ptr);
    cout<<findSubString(str, ptr);
    return 0;
}

