#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 100005
#define INF 0x3f3f3f3f3f3f3f3f 

int n;
int a[N][4];
int sel[N];
int cnt[4];
int cost[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int j = 1; j <= 3; j++) {
			cnt[j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			sel[i] = 0;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] >= a[i][sel[i]]) {
					sel[i] = j;
				}
			}
			cost[i] = INF;
			for (int j = 1; j <= 3; j++) {
				if (j != sel[i]) {
					cost[i] = min(cost[i], a[i][sel[i]] - a[i][j]);
				}
			}
			cnt[sel[i]]++;
			ans += a[i][sel[i]];
		}
		for (int j = 1; j <= 3; j++) {
			if (cnt[j] > (n >> 1)) {
				vector<int> q;
				for (int i = 1; i <= n; i++) {
					if (sel[i] == j) {
						q.push_back(cost[i]);
					}
				}
				sort(q.begin(), q.end());
				for (int i = 0; i < cnt[j] - (n >> 1); i++) {
					ans -= q[i];
				}
				break;
			}
		}
		cout << ans << endl;
	}
}
