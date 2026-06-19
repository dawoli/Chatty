#include<bits/stdc++.h>
# define int long long
# define rep(i, j, k) for (int i = j; i <= k; ++i)
# define N 505
# define mod 998244353
using namespace std;

int power(int a, int p)
{
	int ans = 1;
	for (; p; p >>= 1) {if (p & 1) (ans *= a) %= mod; (a *= a) %= mod;}
	return ans;
}
int n, m, cnt[N], pre[N], suf[N], C[N][N], inv[N][N], dp[2][N][N], tmp[N][N], ans;
string s;
void solve(int i, int j, int k, int val)
{
	for (int t = min(cnt[j], k); t >= 0; --t)
		(dp[i][j][k - t] += val * C[cnt[j]][t] % mod * C[suf[j + 1]][k - t] % mod * inv[suf[j]][k]) %= mod;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	rep(i, 0, 500) {C[i][0] = inv[i][0] = 1; rep(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod, inv[i][j] = power(C[i][j], mod - 2);}
	cin >> n >> m >> s;
	rep(i, 1, n) {int c; cin >> c; ++cnt[c];}
	pre[0] = cnt[0]; rep(i, 1, n) pre[i] = pre[i - 1] + cnt[i];
	for (int i = n; i >= 0; --i) suf[i] = suf[i + 1] + cnt[i];
	dp[0][0][0] = 1;
	rep(p, 1, n)
	{
		int i = (p & 1), d = !i;
		memset(dp[i], 0, sizeof(dp[i])), memset(tmp, 0, sizeof(tmp));
		rep(j, 0, p) rep(k, 0, n) if (dp[d][j][k])
		{
			if (s[p - 1] == '0')
			{
				if (suf[j + 1] > k) solve(i, j + 1, k + 1, dp[d][j][k] * (suf[j + 1] - k) % mod);
				if (pre[j] > p - 1 - k) solve(i, j + 1, k, dp[d][j][k] * (pre[j] - p + 1 + k) % mod);
			}
			else
			{
				(dp[i][j][k + 1] += dp[d][j][k] * (suf[j + 1] - k)) %= mod;
				if (pre[j] > p - 1 - k) solve(i, j + 1, k, dp[d][j][k] * (pre[j] - p + 1 + k) % mod);
			}
		}
//		cout << p << endl;
//		rep(j, 0, n) {rep(k, 0, n) cout << dp[i][j][k] << ' '; cout << endl;}
	}
	rep(j, 0, n - m) rep(k, 0, n) (ans += dp[n & 1][j][k]) %= mod;
	cout << ans << '\n';
	return 0;
}