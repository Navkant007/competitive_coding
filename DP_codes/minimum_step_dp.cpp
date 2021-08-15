/*
n = 5
i*2
i*3
i+1
*/

#include<bits/stdc++.h>
using namespace std;
int minimum_steps(int n){
	int dp[n+1];
	dp[1] = 0;
	for(int i = 2; i<=n; i++){
		dp[i] = INT_MAX;
		if(i % 2 == 0){
			int x = dp[i/2];
			if(x + 1 < dp[i]){
			    dp[i] = x+1;
			}
		}
		if(i % 3 == 0){
		    int x = dp[i/3];
			if(x+1 < dp[i]){
			    dp[i] = x + 1;
			}
		}
		int x = dp[i-1];
		if(x+1<dp[i]){
		    dp[i] = x+1; 
		}
	}
    return dp[n];


}
int main(){
	int n; 
	cin>>n;
	int steps = minimum_steps(n);
	cout<<steps;
	return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// int minimum_steps(int n){
// 	int dp[n+1];
// 	dp[1] = 0;
// 	for(int i = 2; i<=n; i++){
// 		dp[i] = INT_MAX;
// 		if(i % 2 == 0){
// 			dp[i] = min(dp[i], dp[i - (i/2)] + 1);
// 		}
// 		if(i % 3 == 0){
// 			dp[i] = min(dp[i], dp[i - (i/3)] + 1);
// 		}
// 		dp[i] = min(dp[i], dp[i-1] + 1);
// 	}
// 	return dp[n];


// }
// int main(){
// 	int n; 
// 	cin>>n;
// 	int steps = minimum_steps(n);
// 	cout<<steps;
// 	return 0;
}