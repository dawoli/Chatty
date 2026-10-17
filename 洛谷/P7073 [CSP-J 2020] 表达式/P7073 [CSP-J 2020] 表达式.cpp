// Problem URL: https://www.luogu.com.cn/problem/P7073 [CSP-J 2020] 表达式
// Start Time: 2026/10/6 13:23:46

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;

char s;
int	 n, q, sz = 0, x[MAXN], c[2 * MAXN];

struct node
{
	int v;
	int l, r;
} t[2 * MAXN];
stack<int> k;

int dfs(int u)
{
	if (c[u] != -1)
		return c[u];
	const auto &x = t[u];
	switch (x.v)
	{
	case 0:
		return c[u] = 0;
	case 1:
		return c[u] = 1;
	case 2:
		return c[u] = dfs(x.l) || dfs(x.r);
	case 3:
		return c[u] = dfs(x.l) || dfs(x.r);
	case 4:
		return c[u] = !dfs(x.l);
	}
}

int dfs_copy(int u, int c[])
{
	if (c[u] != -1)
		return c[u];
	const auto &x = t[u];
	switch (x.v)
	{
	case 0:
		return c[u] = 0;
	case 1:
		return c[u] = 1;
	case 2:
		return c[u] = dfs_copy(x.l, c) || dfs_copy(x.r, c);
	case 3:
		return c[u] = dfs_copy(x.l, c) || dfs_copy(x.r, c);
	case 4:
		return c[u] = !dfs_copy(x.l, c);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> s)
	{
		switch (s)
		{
		case 'x':
		{
			int u = 0;
			while(true)
			{
				cin >> s;
				if (s == ' ')
					break;
				u *= 10;
				u += s - '0';
			}
			t[++sz] = {-1, -1, -1};
			k.push(sz);
			x[u] = sz;
			break;
		}
		case '!':
		{
			int l = k.top();
			k.pop();
			t[++sz] = {4, l, -1};
			k.push(sz);
			break;
		}
		case '&':
		{
			int r = k.top();
			k.pop();
			int l = k.top();
			k.pop();
			t[++sz] = {3, l, r};
			k.push(sz);
			break;
		}
		case '|':
		{
			int r = k.top();
			k.pop();
			int l = k.top();
			k.pop();
			t[++sz] = {2, l, r};
			k.push(sz);
			break;
		}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int u;
		cin >> u;
		t[x[i]].v = u;
	}
	memset(c, -1, sizeof(c));
	dfs(sz);
	while (q--)
	{
		int u;
		cin >> u;
		t[x[u]].v = !t[x[u]].v;
		cout << dfs_copy(sz, c) << endl;
		t[x[u]].v = !t[x[u]].v;
	}
	return 0;
}