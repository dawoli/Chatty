#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
string a[N], b[N], c[N], d[N], e[N], f[N], g[N], h[N];
int ans[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for(int i = 1; i <= q; i++) cin >> c[i] >> d[i];
	for(int i = 1; i <= n; i++)
	{
		e[i] = a[i];
		f[i] = b[i];
		int cur = e[i].size(), cr = f[i].size();
		while(e[i][0] == f[i][0])
		{
			cur = e[i].size(), cr = f[i].size();
			e[i] = e[i].substr(1, cur - 1);
			f[i] = f[i].substr(1, cur - 1);
		}
		cur = e[i].size(), cr = f[i].size();
		while(e[i][cur - 1] == f[i][cr - 1])
		{
			cur = e[i].size(), cr = f[i].size();
			e[i] = e[i].substr(0, cur - 1);
			f[i] = f[i].substr(0, cur - 1);
		}
	}
	for(int i = 1; i <= q; i++)
	{
		g[i] = c[i];
		h[i] = d[i];
		int cur = g[i].size(), cr = h[i].size();
		while(g[i][0] == h[i][0])
		{
			cur = g[i].size(), cr = h[i].size();
			g[i] = g[i].substr(1, cur - 1);
			h[i] = h[i].substr(1, cur - 1);
		}
		cur = g[i].size(), cr = h[i].size();
		while(g[i][cur - 1] == h[i][cr - 1])
		{
			cur = g[i].size(), cr = h[i].size();
			g[i] = g[i].substr(0, cur - 1);
			h[i] = h[i].substr(0, cur - 1);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= q; j++)
		{
			if(e[i] != g[j] || f[i] != h[j]) continue;
			int s1 = a[i].size(), s2 = c[i].size(), flag = 0;
			for(int k = 0; k <= s2 - s1; k++)
			{
				int tk = k, l = 0;
				while(c[j][tk] == a[i][l])
				{
					tk++;
					l++;
					if(l == s1) flag = 1;
					if(flag) break;
				}
				if(flag) break;
			}
			ans[j] += flag;
		}
	}
	for(int i = 1; i <= q; i++) printf("%d ", ans[i]);
}
