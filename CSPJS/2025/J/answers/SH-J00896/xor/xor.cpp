#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
const int V = (1<<20);
int n,k,a[N],s[N],f[N],g[V];
void input()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) s[i] = (s[i - 1] ^ a[i]);
}
void solveBF()
{
	for (int i = 1; i <= n; ++i)
	{
		f[i] = f[i - 1];
		for (int j = 0; j < i; ++j) if ((s[j] ^ s[i]) == k) f[i] = max(f[i], f[j] + 1);
	}
	printf("%d\n", f[n]);
}
void solve()
{
	fill(g + 1, g + V, -1);
	for (int i = 1; i <= n; ++i) g[s[i]] = f[i] = max(f[i - 1], g[s[i] ^ k] + 1);
	printf("%d\n", f[n]);
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	input();
	solve();
	return 0;
}