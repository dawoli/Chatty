#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353, N = 25;

namespace {
int n, m, c[N], a[N];
int fac[N], ifac[N];
bool b[N], vis[N];
int cnt1, cnt[N];
int sum[(1 << 20) + 5];
string str;

int C(int x, int y) {
	return (1LL*fac[x]*ifac[y] % MOD)*ifac[x - y] % MOD;
}

int qpow(int x, int y) {
	int ret = 1;
	for(; y; y >>= 1) {
		if(y & 1) ret = 1LL*ret*x % MOD;
		x = 1LL*x*x % MOD;
	}
	return ret;
}

void MAIN() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> str;
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = 1LL*fac[i - 1]*i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	for(int i = n; i >= 1; --i) ifac[i - 1] = 1LL*ifac[i]*i % MOD;
	for(int i = 1; i <= n; ++i) cin >> c[i], b[i] = (str[i - 1] == '1'), cnt1 += b[i];
	sort(c + 1, c + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i) ++a[c[i]];
	for(int i = n - 1; i >= 0; --i) a[i] += a[i + 1];
	int ans = 0;
	for(int i = 0; i < (1 << n); ++i) {
		int lst = 0, popc = 0, tot = 0;
		for(int j = 1; j <= n; ++j) cnt[j] = 0;
		for(int j = 1; j <= n; ++j) if((i >> (j - 1)) & 1) {
			if(!b[j]) {
				popc = -1;
				break;
			}
			cnt[j - lst - 1]++;
			++popc;
			lst = j;
		}
		sum[i] = 1;
		for(int j = 0; j < n; ++j) {
			sum[i] = 1LL*sum[i]*(1LL*fac[a[j] - tot]*ifac[a[j] - tot - cnt[j]] % MOD) % MOD;
			tot += cnt[j];
		}
		sum[i] = 1LL*sum[i]*fac[n - popc] % MOD;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < (1 << n); ++j) if(!((j >> i) & 1)) sum[j] = (sum[j] - sum[j ^ (1 << i)] + MOD) % MOD;
	}
	for(int i = 0; i < (1 << n); ++i) ans = (ans + sum[i]) % MOD;
	cout << ans;
}
}

int main() {
	MAIN();
	return 0;
}
