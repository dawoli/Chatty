#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n,m,k,x,y,d,ans=1;
		char a[1005][1005];
		bool f[1005][1005];
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int b=1;b<=n;b++)
			for(int c=1;c<=m;c++)
				f[b][c]=0;
		f[x][y]=1;
		for(int b=1;b<=n;b++)
		{
			for(int c=1;c<=m;c++)
			{
				cin >> a[b][c];
			}
		}
			
		for(int j=1;j<=k;j++)
		{
			int dx=x,dy=y;
			if(d==0) dy++;
			else if(d==1) dx++;
			else if(d==2) dy--;
			else dx--;
			if(dx<1||dx>n||dy<1||dy>m)
			{
				d=(d+1)%4;
				continue;
			}
			if(a[dx][dy]=='x')
			{
				d=(d+1)%4;
				continue;
			}
			x=dx;
			y=dy;
			if(f[x][y]==0)
			{
				f[x][y]=1;
				ans++;
			}
		}
		cout << ans << endl;
	}
}
