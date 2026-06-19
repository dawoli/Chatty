#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7, MOD = 998244353;
int n, a[N], f[N << 1];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++a[x];
	}
	int ans = 0;
	f[0] = 1;
	for (int i = 1; i <= 5000; ++i) {
		while (a[i]--) {
			(f[10001] += f[10001]) %= MOD;
			for (int j = 10001 - i; j <= 10000; ++j)
				(f[10001] += f[j]) %= MOD;
			for (int j = 10000; j >= i; --j)
				(f[j] += f[j - i]) %= MOD;
		}
		(ans += f[2 * i + 1]) %= MOD;
		(ans += f[2 * i + 2]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}
