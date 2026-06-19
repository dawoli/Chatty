#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int a[500005], b[500005], f[500005], g[1<<20];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = b[i-1] ^ a[i];
	memset(g, -0x3f, sizeof(g));
	g[k] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = max(f[i-1], g[b[i]] + 1);
		g[k^b[i]] = max(g[k^b[i]], f[i]);
	}
	printf("%d\n", f[n]);
	
	return 0;
}
