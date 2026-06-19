#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, ans = 1, x0, y0, d0;
char c[120][120];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[120][120], flag[120][120];
bool inarea(int x, int y)
{
	return x <= n && y <= m;
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x0, &y0, &d0);
		memset(flag, 0, sizeof(flag));
		for(int j = 1; j <= n; ++j)
		{
			for(int o = 1; o <= m; ++o)
			{
				
				cin >> c[j][o];
				if(c[j][o] == 'x') flag[j][o] = 1;
			}
		}
		int p = x0 + dx[d0];
		int q = y0 + dy[d0];
		if(flag[p][q] != 1 && inarea(p, q))
		{
			printf("2\n");
		}
		else 
		{
			printf("1\n");
		}
	}
	return 0;
}
