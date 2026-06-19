#include <bits/stdc++.h>
using namespace std;
int n, m;
int mark[110], rmark[110];
int mark_v, pd;
int main(){
	freopen("seat.in",  "r", stdin);
	freopen("seat.out",  "w", stdout);
	cin.tie(); cout.tie();
	cin >> n >> m;
	for(int i = 0;i < (n*m);++i){
		cin >> mark[i];
	}
	mark_v = mark[0];
	sort(mark, mark+(n*m));
	for(int i = 0;i < n*m;++i){
		rmark[n*m-i-1] = mark[i];
	}
	for(int i = 0;i < m;++i){
		for(int j = 0;j < n;++j){
			if(j%2==0) {
				pd = rmark[j*m+i];
			}
			else {
				pd = rmark[(j+1)*m-i-1];
			}
			if(pd == mark_v )cout << j+1 << " " << i+1;
		}
	}
	return 0;
} 
