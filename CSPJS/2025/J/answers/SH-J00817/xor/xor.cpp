#include<bits/stdc++.h>
using namespace std;
struct node{int l, r;};
bool cmp(node x, node y)
{
	return (x.r < y.r);
}
int n, kk, a[10010], cnt, ans, pos;
bool b[10010][22], s[10010][22], flag = true;
node c[1000100];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> kk;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 1)
			flag = false;
		int w = 0;
		int aa = a[i];
		while (aa)
		{
			b[i][w] = aa % 2;
			aa /= 2;
			w += 1;
		}
	}
	if (flag)
	{
		int ret = 0, m = 0;
		if (kk == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0)
				{
					ret += m / 2;
					m = 0;
					ret += 1;
				}
				else
				{
					m += 1;
				}
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
				if (a[i] == 1)
					ret += 1;
		}
		cout << ret;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 20; j++)
		{
			s[i][j] = s[i - 1][j] ^ b[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			int v = 0;
			for (int k = 20; k >= 0; k--)
				v = v * 2 + s[j][k] ^ s[i - 1][k];
			if (v == kk)
			{
				c[++cnt].l = i;
				c[cnt].r = j;
			}
		}
	sort(c + 1, c + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
	{
		if (c[i].l <= pos)
			continue;
		else
		{
			ans ++;
			pos = c[i].r;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
