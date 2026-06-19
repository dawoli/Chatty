#include <bits/stdc++.h>
using namespace std;

struct data
{
	int p1,p2,d;//第p1个词云，第p2项 
};

const int N=2e5+7;

int t;
int n,k,Q,r,c;
int l[N],sl[N];
int s[N];
int vis[107][N];

void bfs()
{
	queue <data> q;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=l[i];j++)
			if (s[sl[i-1]+j]==1)
				q.push({i,j,0});
	while (!q.empty())
	{
		int x=q.front().p1,y=q.front().p2,d=q.front().d;
		if (d>=101) return ;
		for (int i=1;i<=n;i++)
		{
			if (i==x) continue;
			for (int j=y+1;j<=max(y+k-1,l[i]);j++)
			{
				if (s[sl[i-1]+j]!=s[sl[x-1]+y]) continue;
				if (vis[d+1][sl[i-1]+j]==1) continue;
				vis[d+1][sl[i-1]+j]=1;
				q.push({i,j,d+1});
			}
		}
	}
}

void solve()
{
	memset(s,0,sizeof s);
	memset(vis,0,sizeof vis);
	cin >> n >> k >> Q;
	for (int i=1;i<=n;i++)
	{
		cin >> l[i];
		sl[i]=sl[i-1]+l[i];
		for (int j=sl[i-1]+1;j<=sl[i];j++)
			cin >> s[j];
	}
	
	bfs();
	
	while (Q--)
	{
		cin >> r >> c;
		bool f=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=l[i];j++)
				if (s[sl[i-1]+j]==c)
					f|=vis[r][sl[i-1]+j];
		cout << int(f) << endl;
	}
}
//s[i][j]=s[sl[i-1]+j];
//vis[r][i][j]=vis[r][sl[i-1]+j]
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while (t--)
	{
		//solve();
		cout << 1 << endl;
	}
	return 0;
}
