#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, mod = 998244353;

int n, m, c[N];
char s[N];

namespace BF {
	int p[N];

	int solve() {
		for(int i = 1; i <= n; ++i) p[i] = i;

		int ans = 0;
		do {
			int cnt = 0, res = 0;
			for(int i = 1; i <= n; ++i) {
				if(cnt >= c[p[i]]) cnt++;
				else if(s[i] == '0') cnt++;
				else res++;
			}
			ans += (res >= m);
		} while(next_permutation(p + 1, p + n + 1));

		return ans;
	}
}

namespace A {
	int p[N];

	bool check() {
		for(int i = 1; i <= n; ++i)
			if(s[i] == '0')
				return false;
		return true;
	}

	int solve() {
		p[0] = 1;
		for(int i = 1; i <= n; ++i) p[i] = (p[i - 1] * i) % mod;
		return p[n];
	}
}

signed main() {
	freopen("employ3.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	for(int i = 1; i <= n; ++i) cin >> c[i];

	if(n <= 10) cout << BF::solve() << "\n";
	return 0;
}
