#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int n, a[5005], mx;
long long f[5005], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
	sort(a+1, a+n+1);
	mx++;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]+1; j <= mx; j++) ans = (ans + f[j]) % mod;
		for (int j = mx; j >= 0; j--) {
			f[min(j+a[i], mx)] = (f[min(j+a[i], mx)] + f[j]) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}