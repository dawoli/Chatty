#include<bits/stdc++.h>
# define int long long
# define rep(i, j, k) for (int i = j; i <= k; ++i)
# define N 10025
# define M 1200005
using namespace std;

struct edge
{
	int u, v, w;
	bool operator<(const edge &x)const{return w < x.w;}
} e[M], res[N], bst[1025][N], bk[15][N];
int n, m, k, st[M], a[15][N], cst[N], cnt, as;
int id[N], sz[N];
int root(int x){return id[x] == x ? x : id[x] = root(id[x]);}
int deal(int m)
{
	rep(i, 1, n + k) id[i] = i, sz[i] = 1;
	int ans = 0; cnt = 0;
	rep(i, 1, m)
	{
		int ru = root(e[i].u), rv = root(e[i].v); if (ru == rv) continue;
		if (sz[ru] < sz[rv]) swap(ru, rv);
		id[rv] = ru, sz[ru] += sz[rv];
		ans += e[i].w, res[++cnt] = e[i];
	}
	return ans;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1);
	rep(i, 1, k) {rep(j, 0, n) cin >> a[i][j], bk[i][j] = {n + i, j, a[i][j]}; sort(bk[i] + 1, bk[i] + n + 1);}
	as = deal(m); rep(i, 1, cnt) bst[0][i] = res[i];
	rep(p, 1, (1 << k) - 1) rep(i, 1, k) if (p & (1 << (i - 1)))
	{
		int lst = (p ^ (1 << (i - 1))), lp = 0, rp = 0;
		while (bst[lst][lp + 1].u || rp < n)
			if (rp == n || bst[lst][lp + 1].u && bst[lst][lp + 1] < bk[i][rp + 1]) ++lp, e[lp + rp] = bst[lst][lp]; else ++rp, e[lp + rp] = bk[i][rp];
		cst[p] = cst[lst] + a[i][0]; as = min(as, deal(lp + rp) + cst[p]);
		rep(t, 1, cnt) bst[p][t] = res[t];
		break;
	}
	cout << as << '\n';
	return 0;
}