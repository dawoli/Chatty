#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int dir[4][2]={0,1,1,0,0,-1,-1,0};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		int x1,y1,d1;
		cin >> x1 >> y1 >> d1;
		int x=x1,y=y1-1,d=d1;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		for(int i=1;i<=k;i++)
		{
			vis[x][y+1]=1;
			int nx=x+dir[d][0];
			int ny=y+dir[d][1];
			if(nx>=1&&nx<=n&&ny>=0&&ny<m)
			{
				if(a[nx][ny]=='.')
				{
					x=nx;y=ny;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else{
				d=(d+1)%4;
			}
			vis[x][y+1]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
