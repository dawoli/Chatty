#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 501;
long long n, m, c[N], ps[N], f[N][N];
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 0; i < s.length(); i++)
		ps[i+1] = ps[i] + (s[i] == '0');
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	sort(c+1, c+n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i] == '1')
				(f[i][j] += f[i-1][j]) %= mod;
			else {
				(f[i][j] *= f[i-1][j-1]) %= mod;
				(f[i][j] += upper_bound(c+1, c+n+1, j) - c - 1) %= mod;
			}
			f[i][j] %= mod;
		}
	}
	int ans = 0;
	for (int j = m; j <= n; j++)
		ans = (ans + f[n][j]) % mod;
	printf("%d\n", ans);
	return 0;
}