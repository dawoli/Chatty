#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll T;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ll n,m,k,x,y,d,ans = 0;
		char a[1010][1010];
		bool vis[1010][1010];
		memset(vis,false,sizeof(vis));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				cin>>a[i][j];
		ans++;
		vis[x][y] = true;
		while(k--)
		{
			ll nx,ny;
			switch(d)
			{
				case 0:
					nx = x,ny = y + 1;
					break;
				case 1:
					nx = x + 1,ny = y;
					break;
				case 2:
					nx = x,ny = y - 1;
					break;
				case 3:
					nx = x - 1,ny = y;
					break;
			}
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
			{
				x = nx,y = ny;
				if(!vis[x][y])
				{
					ans++;
					vis[x][y] = true;
				}
			}
			else
				d = (d + 1) % 4;
		}
		cout<<ans<<endl;
	}
    return 0;
}
