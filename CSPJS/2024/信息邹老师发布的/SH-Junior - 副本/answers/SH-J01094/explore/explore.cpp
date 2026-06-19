#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,1,0,-1};

int dy[] = {1,0,-1,0};

int t,n,m,k,d,x,y;

int vst[1050][1050];

char a[1050][1050];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vst,0,sizeof(vst)); 
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin>>a[i][j];
			} 
		}
		int ans = 1;
		vst[x][y] = 1;
		for(int i = 1;i <= k;i++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x')
			{
				d = (d+1)%4;
				continue;
			}
			x = nx;
			y = ny;
			if(vst[x][y] == 0)
			{
				vst[x][y] = 1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
