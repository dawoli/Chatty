#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,w;
};
int n,m,k;
vector<node>to[10005];
bool us[10005];
int ans=0;
void cl()
{
	priority_queue<pair<int,int> >q;
	q.push({0,1});
	while(!q.empty())
	{
		pair<int,int> x=q.top();
		q.pop();
		int pl=x.second;
		if(us[pl])
		{
			continue;
		}
		us[pl]=1;
		ans+=-x.first;
		for(auto v:to[pl])
		{
			q.push({-v.w,v.v});
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		to[u].push_back({v,w});
		to[v].push_back({u,w});
	}
	if(k==0)
	{
		cl();
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
/*
5 7 0
1 3 10
3 5 10
2 4 10
5 4 5
1 2 8
1 4 11
1 5 1000000
*/
