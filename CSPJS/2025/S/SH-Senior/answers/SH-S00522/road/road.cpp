#include<bits/stdc++.h>
#define int long long
#define N 10005
using namespace std;
int n,m,k,c[15],a[15][N],f[N];
struct Edge
{
	int from,to,w;
	bool operator<(const Edge &o)const
	{
		return w>o.w;
	}
};
priority_queue<Edge> q;
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	if(x>y) swap(x,y);
	f[find(x)]=find(y);
}
bool check(int x,int y)
{
	return find(x)==find(y);
}
int cal_tree()
{
	int cnt=0,res=0;
	while(!q.empty())
	{
		Edge now=q.top();
		q.pop();
		if(check(now.from,now.to)) continue;
		merge(now.from,now.to);
		res+=now.w;
		cnt++;
		if(cnt==n-1) break;
	}
	return res;
}
void solve1()
{
	cout<<cal_tree()<<endl;
}
void solve2()
{
	for(int i=1;i<=k;i++)
	{
		int free=-1;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				free=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(j==free) continue;
			q.push({j,free,a[i][j]});
		}
	}
	cout<<cal_tree()<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		    cin>>a[i][j];
	}
	bool flag=true;
	for(int i=1;i<=k&&flag;i++)
	{
		if(c[i]) flag=false;
		bool flag2=false;
		for(int j=1;j<=n&&flag&&!flag2;j++)
		    if(a[i][j]==0) flag2=true;
		if(!flag2) flag=false;
	}
	if(flag)
	    solve2();
	else
	    solve1();
	return 0;
}
