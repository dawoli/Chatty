#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int T, n, a[N][5], id[N];
priority_queue<int, vector<int>, greater<int> > q[4];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int cx[] = {a[i][1], a[i][2], a[i][3]};
			sort(cx, cx + 3);
			a[i][4] = cx[2] - cx[1];
			if (cx[2] == a[i][1]) id[i] = 1;
			else if (cx[2] == a[i][2]) id[i] = 2;
			else id[i] = 3;
//			cout << i << ": " << id[i] << ' ' << a[i][4] << endl;
		}
		while (q[1].size()) q[1].pop();
		while (q[2].size()) q[2].pop();
		while (q[3].size()) q[3].pop();
//		cout << "I am Here\n";
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			q[id[i]].push(a[i][4]);
			ans += a[i][id[i]];
			if (q[id[i]].size() > n / 2) {
				ans -= q[id[i]].top();
				q[id[i]].pop();
			}
		}
		cout << ans << endl;
	}
}
