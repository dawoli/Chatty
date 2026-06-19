#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+9;
const ll INF = 1e15;
ll n,a[N],as[N],nUnq;
vector<ll> f[N];
void input()
{
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]),as[i] = a[i];
	sort(as + 1, as + n + 1);
	nUnq = unique(as + 1, as + n + 1) - as - 1;
	for (ll i = 1; i <= n; ++i) a[i] = lower_bound(as + 1, as + nUnq + 1, a[i]) - as;
}
void solveBF()
{
	for (ll i = 0; i <= n; ++i) f[i].resize(nUnq + 1, -INF);
	f[1][0] = 0;
	for (ll i = 2; i <= n; ++i)
	{
		for (ll j = 0; j <= nUnq; ++j) f[i][j] = max(f[i][j], f[i - 1][j] + (a[i] == a[i - 1]) * as[a[i]]);
		for (ll j = 0; j <= nUnq; ++j) f[i][a[i - 1]] = max(f[i][a[i - 1]], f[i - 1][j] + (a[i] == j) * as[a[i]]);
	}
	// for (ll i = 1; i <= n; ++i)
	// {
	// 	printf("%lld\t%lld\t%lld\t", i, a[i], as[a[i]]);
	// 	for (ll j = 0; j <= nUnq; ++j)
	// 		if (f[i][j] < 0) printf("-\t");
	// 		else printf("%lld\t", f[i][j]);
	// 	puts("");
	// }
	printf("%lld\n", *max_element(f[n].begin(), f[n].end()));
}
void mian()
{
	for (ll i = 0; i <= n; ++i) f[i].clear();
	input();
	solveBF();
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) mian();
	return 0;
}