#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 1e5+10;
int n, like[N][5], ans;

void dfs(int pos, int sum1, int sum2, int sum3, int cnt) {
	if (sum1>n/2||sum2>n/2||sum3>n/2) return;
	if (pos==n+1) {
		ans = max(ans, cnt);
		return;
	}
	dfs(pos+1, sum1+1, sum2, sum3, cnt+like[pos][1]);
	dfs(pos+1, sum1, sum2+1, sum3, cnt+like[pos][2]);
	dfs(pos+1, sum1, sum2, sum3+1, cnt+like[pos][3]);
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		ans = 0;
		memset(like, 0, sizeof(like)); 
		cin>>n;
		for (int i = 1; i <= n; i ++) {
			cin>>like[i][1]>>like[i][2]>>like[i][3];
		}
		if (n<=10) {
			dfs(1, 0, 0, 0, 0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
