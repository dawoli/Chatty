#include <bits/stdc++.h>
using namespace std;

int a[500010], d[500010];
bool vis[500010];
bool fa = 1, fb = 1, fc = 1;
int n, k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		d[i] = a[i] ^ d[i-1];
		if (a[i] != 1)
		{
			fa = 0;
			if (a[i] != 0) fb = 0;
		}
		if (a[i] > 255) fc = 0;
	}
	if (fa)
	{
		printf("%d", n/2);
	}
	if (!fa && fb)
	{
		if (k == 1)
		{
			int cnt = 0;
			for (int i = 1; i <= n; i++) if (a[i] == 1) cnt++;
			printf("%d", cnt);
		}
		if (k == 0)
		{
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0)
				{
					vis[i] = 1;
					cnt++;
				}
				if (a[i] == 1 && a[i-1] == 1 && !vis[i-1])
				{
					vis[i-1] = 1;
					vis[i] = 1;
					cnt++;
				}
			}
			printf("%d", cnt);
		}
	}
	if (!fa && !fb && fc)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; i+j-1 <= n; j++)
			{
				if (d[j-1] ^ d[i+j-1] == k)
				{
					bool f = 0;
					for (int x = j; x < i+j; x++)
					{
						if (vis[x])
						{
							f = 1;
							break;
						}
						vis[x] = 1;
					}
					if (!f) cnt++;
				}
			}
		}
		printf("%d", cnt);
	}
	return 0;
}
