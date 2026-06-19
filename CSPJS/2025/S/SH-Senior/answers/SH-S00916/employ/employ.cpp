#include <bits/stdc++.h>
using namespace std;
int n, m, c[510], arr[510];
long long ans, M = 998244353;
char s[510];
long long dfs(int d, int f) {
	if(n - f < m) return 0;
	if(d == n + 1) {
		return n - f >= m;
	}
	long long a = 0, lasta = 0;
	int lastc = -1;
	for(int i = 1; i <= n; ++i) {
		bool flag = false;
		for(int j = 1; j < d; ++j) {
			if(i == arr[j]) {
				flag = true;
				break;
			}
		}
		if(flag) continue;
		if(c[i] == lastc) {
			a += lasta;
			if(a >= M) a %= M;
			continue;
		}
		int f_add = '1' - s[d - 1];
		if(c[i] <= f) f_add = 1;
		arr[d] = i;
		lasta = dfs(d + 1, f + f_add);
		a += lasta;
		if(a >= M) a %= M;
		lastc = c[i];
	}
	return a;
};
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	sort(c + 1, c + n + 1);
	ans = dfs(1, 0);
	cout << ans % M << '\n';
	return 0;
}
