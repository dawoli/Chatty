#include <bits/stdc++.h>
using namespace std;
#define N 200010
int t, n, a[N], c[N], ans;
void dfs(int u) {
	if(u > n) {
		int m0 = 0, m1 = 0, sum = 0;
		for(int i = 1; i <= n; i++)
			if(c[i] == 0) {
				if(a[m0] == a[i]) sum += a[i];
				m0 = i;
			}else {
				if(a[m1] == a[i]) sum += a[i];
				m1 = i;
			}
		ans = max(ans, sum);
		return;
	}
	c[u] = 1;
	dfs(u + 1);
	c[u] = 0;
	dfs(u + 1);
} 
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--) {
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}

