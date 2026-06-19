#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int t, n, m, l, vm, d[N], v[N], a[N], p[N], f1, f2;
void Azero() {
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(d[i] <= p[m]) cnt += (v[i] > vm);
	cout << cnt << " " << ((cnt > 0) ? (m - 1) : m) << endl;
}
void Apos() {
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(d[i] <= p[m]) cnt += (v[i] * v[i] + 2 * (p[m] - d[i]) * a[i] > vm * vm);
	cout << cnt << " " << ((cnt > 0) ? (m - 1) : 0) << endl;
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--) {
		int f1 = 1, f2 = 1;
		cin >> n >> m >> l >> vm;
		for(int i = 1; i <= n; i++) {
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] != 0) f1 = 0;
			if(a[i] <= 0) f2 = 0;
		}
		for(int i = 1; i <= m; i++) cin >> p[i];
		if(f1 == 1) Azero();
		else if(f2 == 1) Apos();
	}
	return 0;
}
