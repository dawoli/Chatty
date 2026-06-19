#include <iostream>
#include <cstdio>
using namespace std;

int r, c, n, k, q;
bool f = false;

struct Man
{
	int l, s[200005] = {0};
	void read()
	{
		cin >> l;
		for (int i = 1; i <= l; ++i)
		{
			cin >> s[i];
		}
	}
	void set()
	{
		for (int i = 1; i <= l; ++i)
		{
			s[i] = 0;
		}
		l = 0;
	}
};
Man m[1005];

void dfs(int step, int last, int lastM)
{
	if (f)
	{
		return;
	}
	if (step > r)
	{
		if (last == c) f = true;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i != lastM)
		{
			for (int j = 1; j <= m[i].l; ++j)
			{
				if (m[i].s[j] == last)
				{
					for (int e = j + 1; e <= min(m[i].l, j + k - 1); ++e)
					{
						dfs(step + 1, m[i].s[e], i);
					}
				}
			}
		}
	}
}

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= n; ++i)
		{
			m[i].set();
		}
		cin >> n >> k >> q;
		for (int i = 1; i <= n; ++i)
		{
			m[i].read();
		}
		for (int i = 1; i <= q; ++i)
		{
			f = false;
			cin >> r >> c;
			dfs(1, 1, 0);
			cout << f << endl;
		}
	}
	return 0;
}
