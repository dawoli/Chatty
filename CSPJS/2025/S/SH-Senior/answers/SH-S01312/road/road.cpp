#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n, m, k, x, y, p, q, ss;
struct E
{
	int a, b, w;
} G[1000005];
int A[15][10005], F[10005], cc;
bool T(E l, E r)
{
	return l.w > r.w;
}
int Q(int q)
{
	if (F[q] == q) return q;
	return F[q] = Q(F[q]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &G[i].a, &G[i].b, &G[i].w);
	for (int i = 1; i <= n; i++)
		F[i] = i;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			scanf("%d", &A[i][j]);
	sort(G + 1, G + 1 + m, T);
	for (int i = 1; i <= n; i++)
	{
		x = G[i].a;
		y = G[i].b;
		p = Q(x);
		q = Q(y);
		if (p != q)
		{
			F[p] = q;
			ss += G[i].w;
			cc++;
		}
		if (cc == n - 1) break;
	}
	cout << ss << endl;
	return 0;
}

