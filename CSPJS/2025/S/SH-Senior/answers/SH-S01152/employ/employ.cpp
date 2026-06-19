#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd() {
	int res = 0, c = getchar();
	while (c < 48 || c > 57) c = getchar();
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
	return res;
}
void wr(int x) {
	if (x > 9) wr(x / 10);
	putchar(x % 10 + 48);
}
const int maxn = 505;
const int mod = 998244353;
int n, m;
bool s[maxn];
int a[maxn]; 
void Read() {
	n = rd(), m = rd();
	char c = getchar();
	while (c != 48 && c != 49) c = getchar();
	for (int i = 1; i <= n; i ++) s[i] = c ^ 48, c = getchar();
	for (int i = 1; i <= n; i ++) a[i] = rd();
}
namespace nle18 {
	bool fe() {return n <= 18;}
	const int maxn = 20;
	const int maxn_2 = 1 << maxn;
	int dp[maxn][maxn_2];
	void Solve() {
		dp[0][0] = 1;
		for (int st = 0, p; st < (1 << n) - 1; st ++) {
			p = __builtin_popcount(st);
			for (int d = 0; d <= p; d ++) {
				for (int i = 0; i < n; i ++) if (!(st >> i & 1)) {
					if (s[p + 1] && a[i + 1] + d > p) dp[d + 1][st | 1 << i] = (dp[d + 1][st | 1 << i] + dp[d][st]) % mod;
					else dp[d][st | 1 << i] = (dp[d][st | 1 << i] + dp[d][st]) % mod;
				}
			}
		}
		int ans = 0;
		for (int i = m; i <= n; i ++) ans = (ans + dp[i][(1 << n) - 1]) % mod;
		wr(ans);
	}
}
namespace men {
	bool fe() {return n == m;}
	void Solve() {
		for (int i = 1; i <= n; i ++) if (!s[i] || !a[i]) {
			putchar('0');
			return;
		}
		int ans = 1;
		for (int i = 1; i <= n; i ++) ans = ans * i % mod;
		wr(ans);
	}
}
namespace me1 {
	bool fe() {return m == 1;}
	int b[maxn];
	vector<int> h;
	void Solve() {
		for (int i = 1; i <= n; i ++) b[a[i]] ++;
		for (int i = 1; i <= n; i ++) b[i] += b[i - 1];
		for (int i = 1; i <= n; i ++) if (s[i]) h.push_back(i);
		int cnt = 0, ans = 1;
		for (auto it: h) {
			ans = ans * (b[it - 1] - cnt) % mod;
			cnt ++;
		}
		for (int i = 1; i <= n - h.size(); i ++) ans = ans * i % mod;
		int sum = 1;
		for (int i = 1; i <= n; i ++) sum = sum * i % mod;
		ans = (mod + sum - ans) % mod;
		wr(ans);
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	Read();
	if (nle18::fe()) nle18::Solve();
	else if (men::fe()) men::Solve();
	else if (me1::fe()) me1::Solve();
	else puts("0");
}
