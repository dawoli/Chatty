#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, mod = 998244353;

int n, a[N];

namespace BF {
	int res;

	void dfs(int pos, int sum, int maxx) {
		if(pos == n + 1) {
			if(sum > 2 * maxx) res = (res + 1) % mod;
			return;
		}

		dfs(pos + 1, sum, maxx);
		dfs(pos + 1, sum + a[pos], max(maxx, a[pos]));
	}

	int solve() {
		dfs(1, 0, 0);
		return res;
	}
}

namespace A1 {
	int p[N];
	
	bool check() { return (*max_element(a + 1, a + n + 1)) == 1; }

	int solve() {
		p[0] = 1;
		for(int i = 1; i <= n; ++i) p[i] = (p[i - 1] << 1) % mod;

		int res = 0;
		for(int m = 3; m <= n; ++m)
			res = (res + p[m - 1] - m + mod) % mod;

		return res;
	}
}

namespace LuanGao {
	int p[N], s[N], dp[25000005];

	int solve() {
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i)
			s[i] = s[i - 1] + a[i];

		int res = 0;
		dp[0] = 1;
		for(int m = 3; m <= n; ++m) {
			if(s[m - 1] <= a[m]) continue;

			int ret = 0;
			if(m == 3) {
				for(int i = 1; i < m; ++i)
					for(int j = s[i]; j >= a[i]; --j)
						dp[j] = (dp[j - a[i]] + dp[j]) % mod;
			} else
				for(int j = s[m - 1]; j >= a[m - 1]; --j)
					dp[j] = (dp[j - a[m - 1]] + dp[j]) % mod;

			for(int i = a[m] + 1; i <= s[m - 1]; ++i)
				ret = (ret + dp[i]) % mod;
			res = (res + ret) % mod;
		}

		return res;
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	if(n <= 20) cout << BF::solve() << "\n";
	else if(A1::check()) cout << A1::solve() << "\n";
	else cout << LuanGao::solve() << "\n";
	return 0;
}
