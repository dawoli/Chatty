#include <bits/stdc++.h>
using namespace std;
int n,m;
int easy,hard;
int ans;
int c[505];
bool vis[505];
void dfs(int i,int lst,int e,int h,int emp) {
	printf("%d %d %d %d %d\n",i,lst,e,h,emp);
	if(i == n+1) {
		ans += emp == m;
		return;
	}
	if(emp + n - i + 1 < m) return;
	if(emp + (easy-e) < m) return;
	if(emp > m) return;
	if(e < easy) {
		for(int j=1;j<=n;++j) {
			
		}
	}
	if(h < hard) {
		int j=i+1;
		++lst;
		while(j <= m && c[j] >= lst) {
			++j;
			++lst;
		}
		dfs(j,lst,e,h+1,emp);
	}
}
int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		char ch;
		cin >> ch;
		if(ch == '0') ++easy;
		else ++hard;
	}
	for(int i=1; i<=n; ++i) {
		cin >> c[i];
	}
	dfs(1,0,0,0,0);
	cout << ans << endl;
}
