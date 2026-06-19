#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;
int x, y, d;
bool mp[1010][1010];
bool flag[1010][1010];

int dtx[4] = {0, 1, 0, -1};
int dty[4] = {1, 0, -1, 0};

int robot()
{
	int ans = 1;
	flag[x][y] = 1;
	int nx = x, ny = y, nd = d;
	for(int i = 1; i <= k; i++)
	{
		int dx = nx + dtx[nd];
		int dy = ny + dty[nd];
		if(dx < 1 || dx > n || dy < 1 || dy > m
			|| mp[dx][dy])
			nd = (nd + 1) % 4;
		else
		{
			nx = dx;
			ny = dy;
			if(!flag[dx][dy])
			{
				flag[dx][dy] = 1;
				ans ++;
			}
		}
	}
	return ans;
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d", &t);
	while(t--)
	{
		memset(mp,0,sizeof(mp));
		memset(flag,0,sizeof(flag));
//		for(int i = 1; i <= n; i++)
//			for(int j = 1; j <= m; j++)
//				mp[i][j] = 0;
//		for(int i = 1; i <= n; i++)
//			for(int j = 1; j <= m; j++)
//				flag[i][j] = 0;
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x, &y, &d);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m;j ++)
			{
				char c;
				cin >> c;
				if(c == 'x')
					mp[i][j] = 1;
			}
		}
		printf("%d\n", robot());
	}
	return 0;
}
