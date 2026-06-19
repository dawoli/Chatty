#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,b[1005][1005];
char a[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			{
				b[j][k]=0;
				cin >> a[j][k];
			}
		}
		b[x][y]=1;
		for (int j=1;j<=k;j++)
		{
			if (d==0 && y+1<=m && a[x][y+1]=='.')
			{
				y++;
			}
			else if (d==1 && x+1<=n && a[x+1][y]=='.')
			{
				x++;
			}
			else if (d==2 && y-1>=1 && a[x][y-1]=='.')
			{
				y--;
			}
			else if (d==3 && x-1>=1 && a[x-1][y]=='.')
			{
				x--;
			}
			else
			{
				d=(d+1)%4;
			}
			b[x][y]=1;
		}
		int ans=0;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			{
				ans+=b[j][k];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
