#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int n,m,ap[N],c[N],a[N],t,x[4];
bitset<N> d[20];
set<int> s[20][N];
void print(set<int> s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) printf("%d ", *it);
	puts("");
}
int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &ap[i]);
	for (int j = 1; j <= m; ++j) scanf("%d", &c[j]);
	int k = 0;
	while ((1 << k) < n) ++k;
	for (int r = 1; r <= k; ++r)
		for (int g = 1; g <= (1 << (k - r)); ++g)
		{
			char tmp;
			scanf(" %c", &tmp);
			if (tmp == '1') d[r].set(g);
		}
	scanf("%d", &t);
	while (t--)
	{
		for (int _ = 0; _ < 4; ++_) scanf("%d", &x[_]);
		for (int i = 1; i <= n; ++i) a[i] = (ap[i] ^ x[i % 4]);
		long long ans = 0;
		for (int j = 1; j <= m; ++j)
		{
			int kp = 0;
			while ((1 << kp) < c[j]) ++kp;
			for (int i = 1; i <= (1 << kp); ++i) s[0][i].insert(i);
			for (int r = 1; r <= kp; ++r)
				for (int g = 1; g <= (1 << (kp - r)); ++g)
				{
					set<int> x = s[r - 1][2 * g - 1],y = s[r - 1][2 * g];
					if (d[r][g]) swap(x, y);
					bool okY = 0;
					for (set<int>::iterator it = x.begin(); it != x.end(); ++it)
					{
						int v = *it;
						if (v > c[j]) s[r][g].insert(v),okY = 1;
						else if (a[v] >= r) s[r][g].insert(v);
						else okY = 1;
					}
					if (okY) for (set<int>::iterator it = y.begin(); it != y.end(); ++it) s[r][g].insert(*it);
				}
			// for (int r = 0; r <= kp; ++r)
			// 	for (int g = 1; g <= (1 << (kp - r)); ++g)
			// 	{
			// 		printf("%d %d: ", r, g);
			// 		print(s[r][g]);
			// 	}
			long long res = 0;
			for (set<int>::iterator it = s[kp][1].begin(); it != s[kp][1].end(); ++it) res += *it;
			// printf("%d %lld\n", c[j], res);
			ans ^= res * j;
			for (int r = 0; r <= kp; ++r)
				for (int g = 1; g <= (1 << (kp - r)); ++g)
					s[r][g].clear();
		}
		printf("%lld\n", ans);
	}
	return 0;
}