#include<bits/stdc++.h>
# define i128 __int128
# define rep(i, j, k) for (int i = j; i <= k; ++i)
# define son(u, x) tr[u].son[x]
# define fail(u, x) tr[u].fail[x]
# define ic(u) tr[u].ic
# define dp(u) tr[u].dp
# define p(u) tr[u].p
# define N 1005
# define M 500005
# define B 9971
# define mod 100000000000000003LL
using namespace std;

struct dui
{
	int st, plc;
	i128 hashe;
	bool operator<(const dui &x)const{return hashe < x.hashe;}
} d[2 * N];
struct node
{
	int son[27], fail[27], ic, p, dp;
} tr[M];
int nd, stk[M], l, r;
char c = '{';
int n, q, le[2 * N], re[2 * N], ans[N];
string s[2][N], t[2][N];
i128 deal(int x, string &p, string &q)
{
	if (p.size() != q.size() || p == q) return -1;
	le[x] = 0, re[x] = q.size() - 1;
	while (p[le[x]] == q[le[x]]) ++le[x]; while (p[re[x]] == q[re[x]]) --re[x];
	i128 hx = 0, hy = 0;
	rep(i, le[x], re[x]) hx = (hx * B + p[i]) % mod, hy = (hy * B + q[i]) % mod;
//	cout << "fdsfdsfdsfdsfds" << (long long) hx << ' ' << (long long) hy << endl;
	return hx * mod + hy;
}
void ins(string s)
{
//	cout << s << endl;
	int n = s.size(), u = 1;
	rep(i, 0, n - 1)
	{
		if (!son(u, s[i] - 'a')) son(u, s[i] - 'a') = ++nd, p(nd) = u, ic(nd) = s[i] - 'a';
		u = son(u, s[i] - 'a');
	}
	++dp(u);
}
void calcfail()
{
	stk[l = r = 1] = 1;
	while (l <= r)
	{
		int u = stk[l++];
	//	cout << u << endl;
	//	rep(i, 0, 26) cout << son(u, i) << ' '; cout << endl;
		if (u == 1) {rep(i, 0, 26) {if (son(u, i)) stk[++r] = son(u, i); fail(u, i) = 1;} continue;}
		int lst = fail(p(u), ic(u)); dp(u) += dp(lst);
		rep(i, 0, 26) if (son(lst, i)) fail(u, i) = son(lst, i); else if (lst) fail(u, i) = fail(lst, i); else fail(u, i) = 1;
		rep(i, 0, 26) if (son(u, i)) stk[++r] = son(u, i);
	}
}
int query(string s)
{
//	cout << "QQQQQ" << s << endl;
	int n = s.size(), u = 1, ans = 0;
	rep(i, 0, n - 1)
	{
		if (!son(u, s[i] - 'a')) u = fail(u, s[i] - 'a'); else u = son(u, s[i] - 'a');
		ans += dp(u);
	}
	return ans;
}
void calc(int l, int r)
{
	if (l == r) return;
//	cout << l << endl << r << endl;
//	rep(i, l, r) cout << d[i].st << ' ' << d[i].plc << endl;
	rep(i, 1, nd) memset(tr[i].son, 0, sizeof(tr[i].son)), memset(tr[i].fail, 0, sizeof(tr[i].fail)), ic(i) = p(i) = dp(i) = 0;
	nd = 1;
	rep(p, l, r) if (d[p].st == 1)
	{
		int u = d[p].plc;
		ins(s[1][u].substr(0, le[u]) + '{' + s[1][u].substr(re[u] + 1));
	}
	calcfail();
	rep(p, l, r) if (d[p].st == 2)
	{
		int u = d[p].plc;
		ans[u] = query(t[1][u].substr(0, le[n + u]) + '{' + t[1][u].substr(re[u] + 1));
	}
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 1, n) cin >> s[0][i] >> s[1][i], d[i] = {1, i, deal(i, s[0][i], s[1][i])};
	rep(i, 1, q) cin >> t[0][i] >> t[1][i], d[n + i] = {2, i, deal(n + i, t[0][i], t[1][i])};
//	rep(i, 1, n + q) cout << "fdsfds" << i << ' ' << le[i] << ' ' << re[i] << endl;
	sort(d + 1, d + n + q + 1);
	int pos = 1;
	while (pos <= n + q)
	{
		int ed = pos; while (ed < n + q && d[ed + 1].hashe == d[pos].hashe) ++ed;
		if (d[pos].hashe == -1) {pos = ed + 1; continue;}
		calc(pos, ed); pos = ed + 1;
	}
	rep(i, 1, q) cout << ans[i] << endl;
	return 0;
}
