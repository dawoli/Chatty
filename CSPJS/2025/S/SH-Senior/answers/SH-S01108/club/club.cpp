#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], sum[5], cha[100005];
long long ans;
vector <int> mem[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		memset(sum, 0, sizeof(sum));
		mem[1].clear(), mem[2].clear(), mem[3].clear();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) ++sum[1], mem[1].push_back(i), ans += a[i][1];
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) ++sum[2], mem[2].push_back(i), ans += a[i][2];
			else ++sum[3], mem[3].push_back(i), ans += a[i][3];
		}
		int len = max(mem[1].size(), max(mem[2].size(), mem[3].size()));
		if (sum[1] > n / 2) {
			for (int i = 0; i < len; ++i) {
				int j = mem[1][i];
				cha[i] = min(a[j][1] - a[j][2], a[j][1] - a[j][3]);
			}
		} else if (sum[2] > n / 2) {
			for (int i = 0; i < len; ++i) {
				int j = mem[2][i];
				cha[i] = min(a[j][2] - a[j][1], a[j][2] - a[j][3]);
			}
		} else if (sum[3] > n / 2) {
			for (int i = 0; i < len; ++i) {
				int j = mem[3][i];
				cha[i] = min(a[j][3] - a[j][1], a[j][3] - a[j][2]);
			}
		}
		sort(cha, cha + len);
		for (int i = 0; i < len - n / 2; ++i) ans -= cha[i];
		cout << ans << "\n";
	}
	return 0;
}

