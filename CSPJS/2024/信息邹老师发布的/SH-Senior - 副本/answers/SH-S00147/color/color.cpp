#include <bits/stdc++.h>
#define rep(x, y, z) for (ll x=(y); x<=(z); x++)
#define debug(x) cout << (#x) << "=" << (x) << endl;
#define line cout << endl;

using namespace std;

#define ll long long

const ll N = 2e5+5;

ll n, a[N], cl[N], ans = 0;

void dfs(int cur) {
	if (cur == n) {
		ll sum = 0;
		rep(i, 0, n-1) {
			for (int j=i-1; j>=0; j--) {
				if (cl[i] == cl[j]) {
					if (a[i] == a[j]) sum += a[i];
					break;
				}
			}
		}
		ans = max(ans, sum);
		return;
	}

	cl[cur] = 1;
	dfs(cur+1);

	cl[cur] = 2;
	dfs(cur+1);
}

void solve() {
	memset(cl, 0, sizeof(cl));
	cin >> n;
	rep(i, 0, n-1) cin >> a[i];

	ans = 0;
	dfs(0);
	cout << ans << endl;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll T; cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
