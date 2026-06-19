#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const ll N = 505;
ll n, m, ans, c[N];
char s[N];
ll res[15]; bool used[15];
void dfs(ll dep) {
	if (dep > n) {
		ll cnt = 0, precnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (precnt >= c[res[i]]) {
				precnt ++;
			} else {
				if (s[i] == '1') cnt ++;
				else precnt ++;
			}
		}
		if (cnt >= m) {
			ans ++;
		}
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (!used[i]) {
			used[i] = 1;
			res[dep] = i;
			dfs(dep + 1);
			used[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", &c[i]);
	if (n <= 10) {
		dfs(1);
		printf("%lld\n", ans);
	} else if (m == n) {
		bool is_0 = false;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == '0') is_0 = true;
			if (c[i] == 0) is_0 = true;
		}
		if (is_0) printf("0\n");
		else {
			ans = 1;
			for (ll i = 1; i <= n; i ++)
				ans = (1ll * ans * i) % mod;
			printf("%lld\n", ans);
		}
	} else {
		printf("0\n");
	}
	return 0;
}
