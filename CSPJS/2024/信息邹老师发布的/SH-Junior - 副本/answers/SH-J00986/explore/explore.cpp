#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
ll n,m,k,x0,y0,d0,x,y,d,ans;
bool vst[N][N];
char ch[N][N];
bool check(ll x,ll y,ll d)
{
	ll nx=x,ny=y;
	switch(d)
	{
		case 0:ny++;break;
		case 1:nx++;break;
		case 2:ny--;break;
		case 3:nx--;break;
	}
	if(nx<1||nx>n||ny<1||ny>m||ch[nx][ny]=='x')return 0;
	return 1;
}
void solve()
{
		memset(vst,0,sizeof(vst));
		vst[x][y]=1;
		ans=0;
		for(ll step=1;step<=k;step++)
		{
			if(check(x,y,d))
			{
				switch(d)
				{
					case 0:y++;break;
					case 1:x++;break;
					case 2:y--;break;
					case 3:x--;break;
				}
				vst[x][y]=1;
			}
			else
			{
				d=(d+1)%4;
			}
//			cout<<x<<" "<<y<<" "<<d<<endl;
		}
		for(ll i=1;i<=n;i++)
		  for(ll j=1;j<=m;j++)
			ans+=vst[i][j];
		cout<<ans<<endl;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(ll i=1;i<=n;i++) 
		  for(ll j=1;j<=m;j++)
			cin>>ch[i][j];
		x=x0;
		y=y0;
		d=d0;
		if(k==1)
		{
			if(check(x,y,d))
			  cout<<2<<endl;
			else
			  cout<<1<<endl;
			continue;
		}
		else solve();
	}
	return 0;
}

