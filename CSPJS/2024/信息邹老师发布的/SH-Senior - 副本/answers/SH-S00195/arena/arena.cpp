# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
struct node {ll c, id;} q[N];
ll T, n, m;
ll a_[N], a[N];
ll ned[32];
ll ans[N];

bool operator < (node x, node y) {return x.c < y.c;}

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a_[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &q[i].c), q[i].id = i;
	ned[0] = 1;
	for (int i = 1; i <= 31; i++) ned[i] = ned[i - 1] * 2;
	sort(q + 1, q + m + 1);
	scanf("%lld", &T);
	while (T--)
	{
		ll xx[4];
		scanf("%lld%lld%lld%lld", &xx[0], &xx[1], &xx[2], &xx[3]);
		for (int i = 1; i <= n; i++) a[i] = a_[i] ^ xx[i % 4];
		for (int i = 1; i <= m; i++)
		{
			ll k2, k;
			k2 = lower_bound(ned, ned + 31 + 1, q[i].c) - ned;
			if (ned[k2] == 1) ans[q[i].id] ^= ((ll)i * a[1]);
			else
			{
			}
		}
	}
	return 0;
}
