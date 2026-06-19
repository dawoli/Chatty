#include <bits/stdc++.h>
using namespace std;
long long a[100005][5], b[100005], c[5], s[5], d[100005];
int func(int i, int m) {
	if (m == 1) return a[i][1] - max(a[i][0], a[i][2]);
	if (m == 2) return a[i][2] - max(a[i][0], a[i][1]);
	if (m == 3) return a[i][3] - max(a[i][1], a[i][2]);
}
void solve() {
	int n; cin >> n;
	memset(c, 0, sizeof(c));
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int temp = max(a[i][1], max(a[i][2], a[i][3]));
		if (a[i][1] == temp) c[1]++, s[1] += a[i][1], d[i] = 1;
		else if (a[i][2] == temp) c[2]++, s[2] += a[i][2], d[i] = 2;
		else c[3]++, s[3] += a[i][3], d[i] = 3;
	}
	if (c[1] <= n / 2 && c[2] <= n / 2 && c[3] <= n / 2) {
		cout << s[1] + s[2] + s[3] << endl;
		return;
	}
	int m;
	if (c[1] > n / 2) m = 1;
	else if (c[2] > n / 2) m = 2;
	else m = 3;
	int tt = 0;
	for (int i = 1; i <= n; i++) if (d[i] == m) b[++tt] = func(i, m);
	sort(b + 1, b + tt + 1);
	for (int i = 1; i <= c[m] - n / 2; i++) s[m] -= b[i];
	cout << s[1] + s[2] + s[3] << endl;
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
} 
