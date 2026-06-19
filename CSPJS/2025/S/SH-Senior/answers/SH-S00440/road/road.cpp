#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<pair<int,int>> mp[10050];
int a[15][10050];
int ans=0;
int s=0;
int flag[10050]={0};
struct node{
	int where;
	int length;
	friend bool operator < (node x,node y)
	{
		return x.length>y.length;
	}
};
priority_queue<node> q;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		mp[y].push_back({x,z});
		mp[x].push_back({y,z});
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		ans+=x;
		int where;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				where=j;
			}
		} 
		for(int j=1;j<=n;j++)
		{
			if(j==where) continue;
			else
			{
				mp[where].push_back({j,a[i][j]});
				mp[j].push_back({where,a[i][j]});
			}
		}
	} 
	q.push({1,0});
	while(!q.empty())
	{
		int now=q.top().where;
		int len=q.top().length;
		q.pop();
		if(flag[now]==1) continue;
		else
		{
			ans+=len;
			flag[now]=1;
			for(auto i : mp[now])
			{
				if(flag[i.first]==1) continue;
				q.push({i.first,i.second});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
