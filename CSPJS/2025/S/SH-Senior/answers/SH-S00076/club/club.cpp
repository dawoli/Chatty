#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 1e5 + 10;
int n, a[N][3];

void solve() {
	n = read();
	long long ans = 0;
	vector<int> vec[3];
	for (int i = 1; i <= n; ++i) {
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		int mx = max(a[i][0], max(a[i][1], a[i][2]));
		ans += mx;
		if (mx == a[i][0]) vec[0].push_back(mx - max(a[i][1], a[i][2]));
		if (mx == a[i][1]) vec[1].push_back(mx - max(a[i][0], a[i][2]));
		if (mx == a[i][2]) vec[2].push_back(mx - max(a[i][0], a[i][1]));
	}
	for (int i = 0; i < 3; ++i) {
		if (vec[i].size() > (n >> 1)) {
			sort(vec[i].begin(), vec[i].end());
			for (int j = 0; j < vec[i].size() - (n >> 1); ++j)
				ans -= vec[i][j];
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t--) solve();
	return 0;
}