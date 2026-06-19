#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 5e3+10;
int ls[N], n, ans;

void dfs(int pos, int maxn, int sum, int cnt) {
	if (pos==n+1) {
		if (sum>maxn*2&&cnt>=3) {
			ans++;
		}
		return;
	}
	dfs(pos+1, max(maxn, ls[pos]), sum+ls[pos], cnt+1);
	dfs(pos+1, maxn, sum, cnt);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for (int i = 1; i <= n; i ++) {
		cin>>ls[i];
	}
	dfs(1, 0, 0, 0);
	cout<<ans<<endl;
	return 0;
}
