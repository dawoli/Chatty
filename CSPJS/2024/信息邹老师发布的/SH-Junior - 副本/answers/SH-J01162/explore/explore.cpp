#include <bits/stdc++.h>
using namespace std;
int frq;
int n,m,k,x,y,d;
const int N = 1010;
char a[N][N];
bool vis[N][N] = {};
int main()
{
	freopen("explore.in","r",stdin); 
	freopen("explore.out","w",stdout);
	scanf("%d",&frq);
	while(frq--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int t = 1;t <= n;t++)
		{
			for(int i = 1;i <= m;i++)
			{
				cin >> a[t][i];
				vis[t][i] = 0;
			}
		}
		vis[x][y] = 1;
		long long cnt = 1;
		while(k--)
		{
			int fx,fy;
			if(d == 0)
			{
				fx = x;
				fy = y + 1;
			}
			else if(d == 1)
			{
				fx = x + 1;
				fy = y;
			}
			else if(d == 2)
			{
				fx = x;
				fy = y - 1;
			}
			else
			{
				fx = x - 1;
				fy = y;
			}
			if(fx >= 1 && fx <= n && fy >= 1 && fy <= m && a[fx][fy] == '.')
			{
				x = fx;
				y = fy;
				if(!vis[x][y]) cnt++;
				vis[x][y] = 1;
			}
			else
			{
				d = (d + 1) % 4;
			}
		} 
		printf("%lld\n",cnt);
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
