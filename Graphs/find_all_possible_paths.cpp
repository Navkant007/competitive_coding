#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	queue<int> a;
	queue<int> b;
	int i = 0, j = 0;
	a.push(i);
	b.push(j);
	int count = 1;
	while(!a.empty()){
		int x, y;
		x = a.front();
		y = b.front();
		if(x == n and y == m){
			break;
		}
		a.pop();
		b.pop();
		int aa[] = {0, 1};
		int bb[] = {1, 0};
		int index_count = 0;
		for(int xx = 0; xx<2; xx++){
			if(x + aa[xx]< n and y + bb[xx] < m){
				a.push(x + aa[xx]);
				b.push(y + bb[xx]);
				index_count++;
			}
		}
		if(index_count == 2)
		count++;
	} 
	cout << count << endl;
	return count;
}

