#include<bits/stdc++.h>
using namespace std;
void all_sub_strings(string s, int n){
    for(int len = 1; len<=n; len++){
        for(int j = 0; j<n-len+1; j++){
            int k = j+len-1;
            for(int p = j; p<=k; p++){
                cout<<s[p];
            }
            cout<<endl;
        }
    }
}
int main(){
    string s;
    cin>>s;
    all_sub_strings(s, s.size());
    return 0;
}

//-----------------------------

#include<bits/stdc++.h>
using namespace std;
void all_sub_strings(string s, int n){
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=n-i; j++){
            cout<<s.substr(i,j)<<endl;
        }
    }
}
int main(){
    string s;
    cin>>s;
    all_sub_strings(s, s.size());
    return 0;
}

//-----------------------------

#include <iostream>
using namespace std;
void printSubstrings(string str)
{
     
    // finding the length of the string
    int n = str.length();
     
    // outermost for loop
    // this is for the selection
    // of starting point
    for (int i = 0; i < n; i++) {
       
        // 2nd for loop is for selection
        // of ending point
        for (int j = i; j < n; j++) {
           
            // 3rd loop is for printing from
            // starting point to ending point
            for (int k = i; k <= j; k++) {
                cout << str[k];
            }
           
            // changing the line after printing
            // from starting point to ending point
            cout << endl;
        }
    }
}
 
// Driver Code
int main()
{
    string str = "abcd";
    printSubstrings(str);
 
    return 0;
}