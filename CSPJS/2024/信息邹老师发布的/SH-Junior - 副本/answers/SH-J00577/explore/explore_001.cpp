#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt=1;
char a[1020][1020];
bool vis[1020][1020]={};
void f(int x,int y,int d,int tim)
{
	if(tim==k) return;
	vis[x][y]=1;
	int nx=x,ny=y,nd=d;
	if(d==0) ny++;
	if(d==1) nx++;
	if(d==2) ny--;
	if(d==3) nx--;
	if(nx<=n&&ny<=m&&nx>=1&&ny>=1&&a[nx][ny]=='.')
	{
		if(vis[nx][ny]==0) cnt++;
		f(nx,ny,nd,tim+1); 
	}
	else f(x,y,(d+1)%4,tim+1);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for(int s=1;s<=t;s++)
	{
		int x0,y0,d0;
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> a[i][j];
			}
		}
		f(x0,y0,d0,0);
		cout << cnt;
		cnt=1;
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++) vis[i][j]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
