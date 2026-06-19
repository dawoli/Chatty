#include <bits/stdc++.h>
const long long mod = 998244353;
const int maxn = 2005;
long long fac[maxn], inv[maxn];
int c[maxn];
bool vis[maxn];
int n, m;
std::string s;
long long dfs(int pos, int flag, int reject) {
	if (flag >= m) {
//		printf("%d %d\n", pos, flag);
		return fac[n + 1 - pos] % mod;
	}
	if (pos == n + 1) 
		return 0;
	int cnt = 0, succeed;
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		succeed = 0;
		cnt = 0;
		if (vis[i])
			continue;
		vis[i] = 1;
		if (s[pos - 1] == '1' && c[i] > reject)
			cnt--;
		cnt++;
		if (s[pos - 1] == '1' && c[i] > reject)
			succeed++;
		res = (res + dfs(pos + 1, flag + succeed, reject + cnt)) % mod;
		vis[i] = 0;
	}
	return res;
}
long long ksm(long long x, int k) {
	long long res = 1;
	while (k) {
		if (k & 1)
			res = res * x % mod;
		x *= x;
		x %= mod;
		k >>= 1;
	}
	return res;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::cin >> n >> m;
	std::cin >> s;
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
		if (c[i] <= 0)
			cnt++;
	}
	fac[0] = 1;
	for (int i = 1; i <= n + m + 1; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[n + m + 1] = ksm(fac[n + m + 1], mod - 2);
	for (int i = n + m; i >= 1; i--) {
		inv[i] = inv[i + 1] * (i + 1);
	}
	inv[0] = 1;
	if (n <= 11) {
		printf("%lld", dfs(1, 0, 0));
		return 0;
	}
	if (n - cnt < m) {
		printf("0");
	}
	printf("%lld", fac[cnt] * fac[n - cnt] % mod * fac[n + m + 1] % mod * inv[m] % mod);
}
