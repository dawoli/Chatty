#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
namespace IANYEYZ {
	int c[510], p[510], n, m;
	string s;
	void solve() {
		cin >> n >> m;
		cin >> s;
		rep (i, 1, n) {
			cin >> c[i];
			p[i] = i;
		}
		int ans = 0;
		do {
			int cnt = 0, res = 0;
			rep (i, 1, n) {
				if (s[i - 1] == '0' || (c[p[i]] <= cnt)) cnt++;
				else if (!(c[p[i]] <= cnt)) {
					res++;
				}
			}
			ans += (res >= m);
		} while (next_permutation(p + 1, p + n + 1));
		cout << ans << "\n";
	}
}
int main() {
	cin.tie(0) -> ios :: sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	IANYEYZ :: solve();
}
