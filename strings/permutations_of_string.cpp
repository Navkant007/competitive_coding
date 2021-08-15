// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void util_function(string s, string ans, vector<string> &vec){
	        if(s.size() == 0){
	            vec.push_back(ans);
	            return;
	        }
	        for(int i = 0; i<s.size(); i++){
	            char ch = s[i];
	            string left_string = s.substr(0,i);
	            string right_string = s.substr(i+1);
	            string rest = left_string + right_string;
	            util_function(rest, ans+ch, vec);
	        }
	    }
		vector<string>find_permutation(string S)
		{
			sort(S.begin(), S.end());
		    string ans = "";
		    vector<string> vec;
		    util_function(S, ans, vec);
		    return vec;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends