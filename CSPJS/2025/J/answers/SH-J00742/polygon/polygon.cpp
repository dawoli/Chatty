#include <bits/stdc++.h> 
using namespace std;
int n, a[5010], c, t;
bool enabled[5010];
void dfs(int nkk) {
	if( nkk + 1 > n ) {
		int m = 0, s = 0;
		for(int i = 0;i<n;++i){
			if (enabled[i] == 1){
				t = a[i];
				if(t > m) {
					m = t;
				}
				s += t;
			}
		}
		if(s > 2*m) {
			c++;
			c %= 998244353;
		}
		return;
	}
	enabled[nkk] = 0;
	dfs(nkk + 1);
	enabled[nkk] = 1;
	dfs(nkk + 1);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie();cout.tie();
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	dfs(0);
	cout << c << endl;
	return 0;
}
