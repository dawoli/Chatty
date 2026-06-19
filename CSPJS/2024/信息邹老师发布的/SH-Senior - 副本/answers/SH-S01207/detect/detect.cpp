#include <bits/stdc++.h>
using namespace std;
int t, n, m, l, V;
int p[100010], a[100010], d[100010], v[100010], ANS, ans2;
void dfs(int x, int y) {
	if (x > m) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int s = p[j] - d[i];
				if (s < 0) continue;
				if (v[i] * v[i] + 2 * a[i] * s >= 0 && sqrt(v[i] * v[i] + 2 * a[i] * s) > V) {
					ans++;
					break;
				}
			}
		}
		if (ANS == ans) ans2 = max(ans2, y);
		return;
	}
	if (m - x + 1 + y <= ans2) return;
	int t = p[x];
	p[x] = -1;
	dfs(x + 1, y + 1);
	p[x] = t;
	dfs(x + 1, y); 
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout); 
	cin >> t;
	while (t--) {
		ans2 = 0;
		cin >> n >> m >> l >> V;
		bool flag = 1; 
		for (int i = 1; i <= n; i++) {
			cin >> d[i] >> v[i] >> a[i];
			if (a[i] != 0) flag = 0;
		} 
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
		}
		if (!flag) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					int s = p[j] - d[i];
					if (s < 0) continue;
					if (v[i] * v[i] + 2 * a[i] * s >= 0 && sqrt(v[i] * v[i] + 2 * a[i] * s) > V) {
						ans++;
						break;
					}
				}
			}
			ANS = ans;
			cout << ans << " ";
			if (ans != 0) {
				dfs(1, 0);
				cout << ans2 << endl;				
			}
			else cout << m << endl;
		}
		else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (p[m] >= d[i]) ans += (v[i] > V);
			}
			cout << ans << " " << m - (ans != 0) << endl;
		}
	}
	return 0;
}



