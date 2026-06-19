#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int T, n, a[N][3];
vector<int> v[3], p;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		v[0].clear(), v[1].clear(), v[2].clear(), p.clear();
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
			int mx = max(a[i][0], max(a[i][1], a[i][2]));
			for (int j = 0; j < 3; j++) {
				if (a[i][j] == mx) {
					v[j].emplace_back(i);
					ans += mx;
					break;
				}
			}
		}
		int o = -1;
		for (int j = 0; j < 3; j++)
			if (v[j].size() > n >> 1)
				o = j;
		if (o == -1) {
			cout << ans << "\n";
			continue;
		}
		int x = (o + 1) % 3, y = (o + 2) % 3, k = v[o].size() - n / 2;
		for (int i : v[o])
			p.emplace_back(a[i][o] - max(a[i][x], a[i][y]));
		sort(p.begin(), p.end());
		for (int i = 0; i < k; i++)
			ans -= p[i];
		cout << ans << "\n";
	}
	return 0;
}

