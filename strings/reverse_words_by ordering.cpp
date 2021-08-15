#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.size();
        vector<string> ss;
        int start = 0;
        string s;
        while(start<n){
            if(S[start] == '.'){
                ss.push_back(s);
                s = '\0';
            }
            else{
                s = s + S[start];
            }
            start++;
        }
        ss.push_back(s);
        string final_string;
        for(int i = ss.size()-1; i>0; i--){
            // cout<<ss[i]<<" ";
            final_string = final_string + ss[i] + ".";
        }
        final_string = final_string + ss[0];
        // cout<<final_string<<" ";
        return final_string;
    } 
    
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends