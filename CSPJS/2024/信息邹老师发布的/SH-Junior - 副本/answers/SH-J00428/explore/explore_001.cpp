#include<cstdio>
#include<iostream>
#include<cstring> 
using namespace std;
const long long Inf=1e9+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

bool vis[1009][1009];
char mp[1009][1009];
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll n,m,k,x,y,d,ans=0;

inline void solve()
{
	ans=0;
	memset(vis,false,sizeof(vis));
	scanf("%lld %lld %lld %lld %lld %lld",&n,&m,&k,&x,&y,&d);
	vis[x][y]=true; ans++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	while(k--)
	{
		ll nx,ny;
		nx=x+dx[d];
		ny=y+dy[d];
		if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.')
		{
			x=nx; y=ny;
			if(vis[x][y]==false)
				ans++;
			vis[x][y]=true; 
		}
		else
		{
			d++; d%=4;
		}
	}
	printf("%lld\n",ans);
	return;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}

