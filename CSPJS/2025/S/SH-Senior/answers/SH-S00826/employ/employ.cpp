#include <iostream>
using namespace std;
int n, m, c[505];
string s;
bool flag[505], vst[505];
int p[505], ans;
bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		cnt += (!flag[i] || cnt >= c[p[i]]);
	return n - cnt >= m;
}
void dfs(int idx) {
	if (idx == n + 1) {
		ans += check();
		return;
	}
	for (p[idx] = 1; p[idx] <= n; ++p[idx]) {
		if (vst[p[idx]]) continue;
		vst[p[idx]] = true;
		dfs(idx + 1);
		vst[p[idx]] = false;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		flag[i] = (s[i - 1] == '1');
	dfs(1);
	cout << ans;
	return 0;
}
