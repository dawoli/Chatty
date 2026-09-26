// Problem URL: https://www.luogu.com.cn/contest/311135
// Start Time: 2026/9/6 13:57:20

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXV = 800000;
const int		  MAXN = 250000;
const int		  MAXQ = 250000;

int				 n, x, q;
int				 o[MAXN], a[MAXN], b[MAXN], c[MAXN];
ll				 y[MAXQ];
bitset<MAXV + 1> cur;

void ord(int a, int b)
{
	int				 d = b - a;
	bitset<MAXV + 1> nxt;
	nxt.reset();
	for (int v = 0; v < a && v <= MAXV; ++v)
	{
		if (cur[v])
			nxt.set(v);
	}
	for (int v = a; v <= MAXV; ++v)
	{
		if (cur[v])
		{
			int nv = v + d;
			if (nv >= 0 && nv <= MAXV)
				nxt.set(nv);
		}
	}
	cur = nxt;
}

void spc(int a, int b, int c)
{
	bitset<MAXV + 1> nxt;
	nxt.reset();
	for (int v = 0; v <= MAXV; ++v)
	{
		if (!cur[v])
			continue;
		nxt.set(v);
		if (v >= a)
		{
			int v1 = v - a + b;
			if (v1 >= 0 && v1 <= MAXV)
				nxt.set(v1);
			int v2 = v - a + c;
			if (v2 >= 0 && v2 <= MAXV)
				nxt.set(v2);
		}
	}
	cur = nxt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> o[i];
		if (o[i] == 0)
		{
			cin >> a[i] >> b[i];
			c[i] = 0;
		}
		else
		{
			cin >> a[i] >> b[i] >> c[i];
		}
	}
	for (int i = 0; i < q; ++i)
		cin >> y[i];
	cur.set(x);
	for (int i = 0; i < n; ++i)
	{
		if (o[i] == 0)
			ord(a[i], b[i]);
		else
			spc(a[i], b[i], c[i]);
	}
	for (int i = 0; i < q; ++i)
	{
		if (y[i] > MAXV)
			cout << 0 << endl;
		else
			cout << (cur[y[i]] ? 1 : 0) << endl;
	}
	return 0;
}