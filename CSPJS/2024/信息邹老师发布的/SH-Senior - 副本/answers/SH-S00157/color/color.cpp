#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
int a[2010], ch[2010], t, n, ans;
int calc() {
	int lst[2] = {};
	int res = 0;
	rep (i, 1, n) {
		if (lst[ch[i]] != 0) {
			if (lst[ch[i]] == a[i]) {
				res += a[i];
			}
		}
		lst[ch[i]] = a[i];
	}
	return res;
}
void dfs(int step) {
	if (step == n + 1) {
		ans = max(ans, calc());
	} else {
		ch[step] = 0;
		dfs(step + 1);
		ch[step] = 1;
		dfs(step + 1);
	}
}
void solve() {
	ans = 0;
	cin >> n;
	rep (i, 1, n) {
		cin >> a[i];
	}
	dfs(1);
	cout << ans << "\n";
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);
	cin >> t;
	while (t--) {
		solve();
	}
}
