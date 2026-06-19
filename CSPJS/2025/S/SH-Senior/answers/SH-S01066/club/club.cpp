#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int n, p[N][4];

namespace N3 {
	int dp[105][105][105];

	int solve() {
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			for(int a = 0; a <= n / 2; ++a)
				for(int b = 0; b <= n / 2 && a + b <= i; ++b) {
					int c = i - a - b;
					if(c > n / 2) continue;
					if(a > 0) dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b][c] + p[i][1]);
					if(b > 0) dp[a][b][c] = max(dp[a][b][c], dp[a][b - 1][c] + p[i][2]);
					if(c > 0) dp[a][b][c] = max(dp[a][b][c], dp[a][b][c - 1] + p[i][3]);
				}
		}

		int res = 0;
		for(int a = 0; a <= n / 2; ++a)
			for(int b = 0; b <= n / 2 && a + b <= n; ++b) {
				if(n - a - b > n / 2) continue;
				res = max(res, dp[a][b][n - a - b]);
			}
		return res;
	}
}

namespace A {
	bool check() {
		for(int i = 1; i <= n; ++i)
			if(p[i][2] != 0 || p[i][3] != 0)
				return false;
		return true;
	}

	int solve() {
		vector<int> v;
		for(int i = 1; i <= n; ++i) v.push_back(p[i][1]);
		sort(v.begin(), v.end(), greater<int>());
		int res = 0;
		for(int i = 0; i < n / 2; ++i) res += v[i];
		return res;
	}
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> p[i][1] >> p[i][2] >> p[i][3];

	if(n <= 200) cout << N3::solve() << "\n";
	else if(A::check()) cout << A::solve() << "\n";
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
