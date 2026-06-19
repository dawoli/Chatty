#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,us,cnt=0,ans=0;
struct rd
{
	long long j1;
	long long j2;
	bool operator<(const rd&rd2)
	const
	{
		return j2>rd2.j2;
	};
};
rd rdu;
vector<rd> l1[10005];
long long l2[10005];
priority_queue<rd> l3;
short flag[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		rdu.j1=v;
		rdu.j2=w;
		l1[u].push_back(rdu);
		rdu.j1=u;
		l1[v].push_back(rdu);
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>us;
		for(long long j=1;j<=n;j++)
		{
			cin>>l2[j];
		}
		for(long long j=1;j<=n;j++)
		{
			rdu.j1=j;
			for(long long k=1;k<=n;k++)
			{
				if(j==k)
				{
					continue;
				}
				rdu.j2=l2[k]+l2[j];
				l1[k].push_back(rdu);
			}
		}
	}
	rdu.j1=1;
	rdu.j2=0;
	l3.push(rdu);
	while(!l3.empty())
	{
		cout<<l3.size()<<" "<<l3.top().j1<<" "<<flag[l3.top().j1]<<" "<<l3.top().j2;
		cout<<1<<endl;
		if(cnt>=n)
		{
			break;
		}
		if(flag[l3.top().j1])
		{
			l3.pop();
			continue;
		}
		ans+=l3.top().j2;
		flag[l3.top().j1]=1;
		cnt++;
		for(long long j=0;j<l1[l3.top().j1].size();j++)
		{
			if(flag[l1[l3.top().j1][j].j1]==0)
			{
				rdu.j1=l1[l3.top().j1][j].j1;
				rdu.j2=l1[l3.top().j1][j].j2;
				l3.push(rdu);
			} 
		}
		l3.pop();
	}
	cout<<ans;
	return 0;
}
