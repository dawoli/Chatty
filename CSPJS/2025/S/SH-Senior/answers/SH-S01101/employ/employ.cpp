#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 998244353;
int n, m;
int a[505], c[505];
long long f[1<<18][20];
int bit[1<<18], lg[1<<18];
int lowbit(int x) { return x&-x; }
vector<int> S[20];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	if (n <= 18) {
		for (int i = 1; i < 1<<n; i++) {
			bit[i] = bit[i-lowbit(i)]+1;
			S[bit[i]].push_back(i);
		}
		for (int i = 0; i < 18; i++) lg[1<<i] = i;
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int s : S[i]) {
				int t = s;
				while (t) {
					int p = lowbit(t); t-=p;
					for (int j = 0; j < i; j++) {
						if (a[i] == 0 || j >= c[lg[p]+1])
							f[s][j+1] = (f[s][j+1] + f[s-p][j]) % mod;
						else f[s][j] = (f[s][j] + f[s-p][j]) % mod;
					}
				}
			}
		}
		long long ans = 0;
		for (int j = 0; j <= (n-m); j++)
			ans += f[(1<<n)-1][j];
		printf("%lld\n", ans);
	}

	return 0;
}