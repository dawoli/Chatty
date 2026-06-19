#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MX = 1e5 + 10;
struct v3 {
	ll x, y, z;
	ll &operator[](size_t id) {
		if (id == 0) return x;
		if (id == 1) return y;
		if (id == 2) return z;
		throw "Id Out of Range Exception!";
	}
} a[MX];
ll n, p3[20];

void n10() {
	if (!p3[0]) {
		p3[0] = 1;
		for (ll i = 1; i < 15; ++i) {
			p3[i] = p3[i - 1] * 3;
		}
	}
	ll ans = 0;
	for (ll p = 0; p < p3[n]; ++p) {
		ll sum = 0, cnt[3] = {0, 0, 0};
		for (ll i = 0; i < n; ++i) {
			ll c = p / p3[i] % 3;
			++cnt[c];
			sum += a[i][c];
		}
		if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
			ans = max(ans, sum);
		}
	}
	cout << ans << '\n';
}

bool isa1() {
	for (ll i = 0; i < n; ++i) {
		if (a[i][1] || a[i][2]) return false;
	}
	return true;
}
void a1() {
	sort(a, a + n, [](v3 x, v3 y) {
		return x[0] > y[0];
	});
	ll ans = 0;
	for (ll i = 0; i < n / 2; ++i) {
		ans += a[i][0];
	}
	cout << ans << '\n';
}

bool isa12() {
	for (ll i = 0; i < n; ++i) {
		if (a[i][2]) return false;
	}
	return true;
}
void a12() {
	sort(a, a + n, [](v3 x, v3 y) {
		ll dx = x[0] - x[1], dy = y[0] - y[1];
		if (dx != dy) return dx > dy;
		return x[0] > y[0];
	});
	ll ans = 0;
	for (ll i = 0; i < n / 2; ++i) {
		ans += a[i][0];
	}
	for (ll i = n / 2; i < n; ++i) {
		ans += a[i][1];
	}
	cout << ans << '\n';
}

ll dp[2][220][220][3];
void n200() {
	memset(dp, -1, sizeof dp);
	dp[0][1][0][0] = a[0][0];
	dp[0][0][1][1] = a[0][1];
	dp[0][0][0][2] = a[0][2];
	for (ll i = 1; i < n; ++i) {
		for (ll a0 = 0; a0 <= i; ++a0) {
			for (ll a1 = 0; a0 + a1 <= i; ++a1) {
				for (ll d = 0; d < 3; ++d) {
					for (ll dd = 0; dd < 3; ++dd) {
						dp[i & 1][a0 + (d == 0)][a1 + (d == 1)][d] = max(
							dp[i & 1 ^ 1][a0][a1][dd] + a[i][d],
							dp[i & 1][a0 + (d == 0)][a1 + (d == 1)][d]
						);
					}
				}
			}
		}
	}
	ll ans = 0;
	for (ll a0 = 0; a0 <= n / 2; ++a0) {
		for (ll a1 = 0; a1 <= n / 2; ++a1) {
			if (n - a0 - a1 <= n / 2) {
				ans = max(ans,
					  max(dp[(n - 1) & 1][a0][a1][0],
					  max(dp[(n - 1) & 1][a0][a1][1],
					      dp[(n - 1) & 1][a0][a1][2])));
			}
		}
	}
	cout << ans << '\n';
}

struct ord {
	ll i, d, v, dlt;
	bool operator< (const ord &o) const {
		return v < o.v;
	}
};
priority_queue<ord> q;
bool vis[MX];

void ne5() {
	memset(vis, 0, sizeof vis);
	while (q.size()) q.pop();
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < 3; ++j) {
			q.push({i, j, a[i][j],
					max(abs(a[i][0] - a[i][1]),
					max(abs(a[i][1] - a[i][2]),
						abs(a[i][2] - a[i][0])))
			});
		}
	}
	ll cnt[3] = {0, 0, 0}, ans = 0;
	while (q.size()) {
		ord p = q.top();
		q.pop();
		if (!vis[p.i] && cnt[p.d] < n / 2) {
			++cnt[p.d];
			ans += p.v;
			vis[p.i] = 1;
		}
	}
	cout << ans << '\n';
}

void solve() {
	n = 0;
	memset(a, 0, sizeof a);
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	
	if (n <= 10) {
		n10();
		return;
	}

	if (isa1()) {
		a1();
		return;
	}
	
	if (isa12()) {
		a12();
		return;
	}
	
	if (n <= 200) {
		n200();
		return;
	}
	
	ne5();
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	cout.flush();

	return 0;
}
