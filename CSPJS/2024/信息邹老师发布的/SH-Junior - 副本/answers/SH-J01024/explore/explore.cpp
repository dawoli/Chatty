#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int b[1010][1010];
int n,m,k,f[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x,int y,int step,int d)
{
	if(step >= k)
	{
		return;
	}
	int step2 = 0;
	for(int i = 0;i <= 3;i++)
	{
		int dx = x + f[(d + i) % 4][0],dy = y + f[(d + i) % 4][1];
		if(dx < 1 || dx > n || dy < 1 || dy > m || a[dx][dy] == 'x' || b[dx][dy] == 1)
		{
			step2++;
			continue;
		}
		if(step + step2 <= k)
		{
			b[dx][dy] = 1;
		}
		dfs(dx,dy,step + step2 + 1,(d + i) % 4);
		step2 = 0;
	}
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for(int c = 1;c <= t;c++)
	{
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> a[i][j];
			}
		}
		b[x][y] = 1;
		dfs(x,y,0,d);
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				if(b[i][j] == 1)
				{
					cnt++;
					b[i][j] = 0;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
