#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e3+10;
ll n,m,k,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
string a[N];
bool vis[N][N];
bool check(int x,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m&&a[x][y]=='.';
}
void f()
{
	memset(vis,0,sizeof vis);
	ll x,y,d;
	scanf("%lld%lld%lld",&n,&m,&k);
	scanf("%lld%lld%lld",&x,&y,&d);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=' '+a[i];
	}
	vis[x][y]=1;
	while(k--)
	{
		int nx=x+dx[d],ny=y+dy[d];
		if(check(nx,ny))
		{
			x=nx,y=ny;
			vis[x][y]=1;
		}
		else d++,d%=4;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]) ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) f();
	return 0;
}/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
