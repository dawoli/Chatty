#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 2e5 + 10, W = 1e6 + 10;
int T, n, a[N], lst[W];
long long mx[N];
map<int, long long> dp[N];

inline void push(int i, int j, long long val) {
	j = i > lst[j]? 0 : j;
	dp[i][j] = max(dp[i][j], val);
	mx[i] = max(mx[i], val);
}

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; ++i)
			a[i] = read(), lst[a[i]] = i, dp[i].clear(), mx[i] = 0;
		dp[1][0] = 0;
		for (int i = 1; i < n; ++i) {
			for (pair<int, long long> val : dp[i]) {
				if (val.first + val.second < mx[i]) continue;
				push(i + 1, val.first, val.second + (a[i] == a[i + 1]? a[i] : 0));
				push(i + 1, a[i], val.second + (a[i + 1] == val.first? a[i + 1] : 0));
			}
		}
		cout << mx[n] << endl;
	}
	return 0;
}
