#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
inline void add(int& a, int b) {
	a += b;
	if (a >= p) a -= p;
}
int n, m, val[20], ans;
bool ok[20];
int dp[262144][20];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 1; i <= n; i++) {
		ok[i] = (str[i-1] == '1');
	}
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	dp[0][0] = 1;
	for (int s = 0; s <= (1 << n) - 2; s++) {
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (s & (1 << (i - 1))) {
				c++;
			}
		}
		for (int x = 0; x <= c; x++) {
			for (int i = 1; i <= n; i++) {
				if (!(s & (1 << (i - 1)))) {
					int t = (s | (1 << (i - 1)));
					if (ok[c+1] && val[i] > c - x) {
						add(dp[t][x+1], dp[s][x]);
					} else {
						add(dp[t][x], dp[s][x]);
					}
				}
			}
		}
	}
	for (int i = m; i <= n; i++) {
		add(ans, dp[(1<<n)-1][i]);
	}
	cout << ans << endl;
	return 0;
}
/*
//freopen("employ.in", "r", stdin);
//freopen("employ.out", "w", stdout);
freopen("employ.out", "r", stdin);
freopen("employ.in", "w", stdout);
IAKIOI CCF y0 y1 mian 998224353
*/
