#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,fx,fy,fd;
char mp[1005][1005];
bool vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>fx>>fy>>fd;
		for(ll i = 1;i <= n;i++)
		{
			for(ll j = 1;j <= m;j++)
			{
				cin>>mp[i][j];
				vis[i][j] = 0;
			}
		}
		ll x = fx,y = fy,d = fd;
		while(k--)
		{
			vis[x][y] = 1;
			ll nx = x,ny = y;
			if(d == 0) ny += 1;
			else if(d == 1) nx += 1;
			else if(d == 2) ny -= 1;
			else if(d == 3) nx -= 1;
//			cout<<nx<<" "<<ny<<" "<<mp[nx][ny]<<endl;
			if(nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x')
			{
				d = (d + 1) % 4;
			}
			else
			{
				x = nx;
				y = ny;
			}
		}
//		cout<<x<<" "<<y<<endl;
		vis[x][y] = 1;
		ll ans = 0;
		for(ll i = 1;i <= n;i++)
		{
			for(ll j = 1;j <= m;j++)
			{
				if(vis[i][j])
				{
					ans += 1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
