#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, ans, c[505], p[505], vis[505];
string s;
bool check_a = 1;
void dfs(int d) {
	if (d > n) {
		int no = 0;
		for (int j = 1; j <= n; j++) {
			if (s[j-1] == '0' || no >= c[p[j]]) no++;
		}
		if (n - no >= m) {
			ans = (ans + 1) % mod;
		}	
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			p[d] = i;
			dfs(d+1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int c1 = 0;
	for (char c : s) {
		if (c == '0') {
			check_a = 0;
		}
		else c1++;
	}
	if (c1 < m) {
		cout << 0;
		return 0;
	}
	if (m == 1) {
		int c0 = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) c0++;
		}
		int ans = n-c0;
		for (int i = 2; i <= n-1; i++) {
			ans = ans * i % mod;
		}
		ans = (ans + mod) % mod;
		cout << ans;
		return 0;
	}
	if (check_a) {
		ans = 1;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) c[i] = n + 1;
		}
		sort(c+1, c+n+1);
		for (int i = 1; c[i] <= n; i++) {
			ans = ans * (c[i] - i + 1) % mod;
		}
		ans = (ans + mod) % mod;
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
