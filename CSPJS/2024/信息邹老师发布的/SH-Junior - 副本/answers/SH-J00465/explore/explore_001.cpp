#include <bits/stdc++.h>
using namespace std;
char Map[1010][1010];
bool vis[1010][1010];

bool pd(int x,int y,int n,int m)
{
	if (x >= 1 && y >= 1 && x <= n && y <= m && Map[x][y] == '.') return true;
	else return false;
}
int main()
{
	freopen("explore.in ","r",stdin);
	freopen("explore.out ","w",stdout);
	int T;
	scanf("%d",&T);

	while (T--)
	{
		memset(vis,0,sizeof(vis));
		memset(Map,0,sizeof(Map));
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int x,y,d;

		scanf("%d %d %d",&x,&y,&d);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> Map[i]+1;
		}
		for (int i = 1; i <= k; i++)
		{
			if (!vis[x][y])cnt++;
			vis[x][y]++;
			int nx = x,ny = y;
			if (d == 0) ny++;
			if (d == 1) nx++;
			if (d == 2) ny--;
			if (d == 3) nx--;
			if (pd(nx,ny,n,m))
			{
				x = nx,y = ny;
				if (!vis[x][y])cnt++;
				vis[x][y]++;
			}
			else
				d = (d+1)%4;
		}
		cout << cnt << endl;
	}
	return 0;
}
