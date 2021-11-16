/*
#GeeKs01fOr@gEEks07
*/

#include<bits/stdc++.h>
using namespace std;
void count_upper_lower_number_special_characters(string s){
    int upper = 0, lower = 0, number = 0, special = 0;
    for(int i = 0;i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z'){
            upper++;
        }
        else if(s[i]>='a' && s[i]<='z'){
            lower++;
        }
        else if(s[i]>='0' && s[i]<='9'){
            number++;
        }
        else{
            special++;
        }
    }
    cout<<upper<<" "<<lower<<" "<<number<<" "<<special<<" "<<endl;
}
int main(){
    string s;
    cin>>s;
    count_upper_lower_number_special_characters(s);
    return 0;
}