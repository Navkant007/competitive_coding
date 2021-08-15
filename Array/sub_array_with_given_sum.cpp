#include<bits/stdc++.h>
using namespace std;
void find_index_with_sum(int a[], int sum, int n){
	int curr_sum = a[0], start = 0;
	for(int i = 1; i<=n; i++){
		while(curr_sum>sum && start < i-1){
			curr_sum -= a[start];
			start++;
		}
		if(curr_sum == sum){
			cout<<start<<" "<<i-1;
		}
		if(i<n)
			curr_sum += a[i];
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	find_index_with_sum(a, sum, n);
	return 0;
}