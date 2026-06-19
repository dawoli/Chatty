#include <bits/stdc++.h>
using namespace std;

struct pos{
	int x,y,d;
};

const int N=1e3+7;
const int X[]={0,1,0,-1};
const int Y[]={1,0,-1,0};

int n,m,k,t,ans;
int vis[N][N];
char a[N][N];
pos p;

pos next(pos now)
{
	int u=now.x+X[now.d],v=now.y+Y[now.d];
	if (u<=n&&u>=1&&v<=m&&v>=1&&a[u][v]=='.')
	{
		pos ret={u,v,now.d};
		return ret;
	}
	now.d=(now.d+1)%4;
	return now;
}


void solve()
{
	memset(vis,0,sizeof vis);
	ans=n=m=k=0;
	
	cin >> n >> m >> k;
	cin >> p.x >> p.y >> p.d;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin >> a[i][j];
	
	vis[p.x][p.y]=1;
	while (k--)
	{
		p=next(p);
		vis[p.x][p.y]=1;
	}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans+=vis[i][j];

	cout << ans << endl;
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while (t--)
	{
		solve();
	}
}
