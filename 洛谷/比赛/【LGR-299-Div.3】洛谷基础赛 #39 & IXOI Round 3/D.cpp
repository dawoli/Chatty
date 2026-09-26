// Problem URL: https://www.luogu.com.cn/contest/311135
// Start Time: 2026/9/6 13:57:20

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXB = 30;
const int		  MAXN = 100005;

int n, k;
int a[MAXN], v[MAXN];
int pre[MAXN][MAXB];
struct Node
{
	int ch[2];
	int l, r;
};
vector<Node> t;

int sz(int u)
{
	return t[u].r - t[u].l + 1;
}

void insert(int val, int idx)
{
	int u = 0;
	if (t[u].l > idx)
		t[u].l = idx;
	if (t[u].r < idx)
		t[u].r = idx;
	for (int b = MAXB - 1; b >= 0; --b)
	{
		int bit = (val >> b) & 1;
		int nxt = t[u].ch[bit];
		if (nxt == -1)
		{
			nxt = (int)t.size();
			Node nd;
			nd.ch[0] = nd.ch[1] = -1;
			nd.l = nd.r = idx;
			t.push_back(nd);
			t[u].ch[bit] = nxt;
		}
		u = nxt;
		if (t[u].l > idx)
			t[u].l = idx;
		if (t[u].r < idx)
			t[u].r = idx;
	}
}

int xor_sum(int u, int M)
{
	int l	= t[u].l;
	int r	= t[u].r;
	int tot = r - l + 1;
	int sum = 0;
	for (int b = 0; b < MAXB; ++b)
	{
		int cnt1 = pre[r + 1][b] - pre[l][b];
		int one;
		if ((M >> b) & 1)
			one = tot - cnt1;
		else
			one = cnt1;
		sum += (int)one << b;
	}
	return sum;
}

int query(int M, int nd)
{
	if (nd <= 0)
		return 0;
	int u	= 0;
	int ans = 0;
	int val = 0;
	for (int b = MAXB - 1; b >= 0; --b)
	{
		int mb = (M >> b) & 1;
		int gb = mb ^ 1;
		int bb = mb;
		int gd = t[u].ch[gb];
		int bd = t[u].ch[bb];
		if (gd != -1 && sz(gd) >= nd)
		{
			u	= gd;
			val = (val << 1) | gb;
		}
		else
		{
			if (gd != -1)
			{
				ans += xor_sum(gd, M);
				nd -= sz(gd);
				if (nd <= 0)
					return ans;
			}
			if (bd == -1)
				break;
			u	= bd;
			val = (val << 1) | bb;
		}
	}
	if (nd > 0)
	{
		ans += (int)nd * (val ^ M);
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		v[i] = a[i];
	}
	if (k == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(v, v + n);
	for (int i = 1; i <= n; ++i)
	{
		for (int b = 0; b < MAXB; ++b)
		{
			pre[i][b] = pre[i - 1][b] + ((v[i - 1] >> b) & 1);
		}
	}
	t.reserve(3000005);
	Node rt;
	rt.ch[0] = rt.ch[1] = -1;
	rt.l				= 0;
	rt.r				= -1;
	t.push_back(rt);
	int ans = 0;
	int i	= 0;
	while (i < n)
	{
		int M = v[i];
		while (i < n && v[i] == M)
		{
			insert(v[i], i);
			++i;
		}
		int cnt = i;
		if (cnt >= k)
		{
			int cur = query(M, k - 1);
			if (cur > ans)
				ans = cur;
		}
	}
	cout << ans << endl;
	return 0;
}