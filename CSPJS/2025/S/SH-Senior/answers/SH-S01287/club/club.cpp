#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,long long> ,vector<pair<long long,long long> > ,
greater<pair<long long,long long> > > q[4];
pair<long long,long long> a[100011][4];
bool compare(pair<long long,long long> temp1,pair<long long,long long> temp2)
{
	return temp1>temp2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		for(int j=1;j<=3;j++)
		{
			while(q[j].size()!=0)q[j].pop();
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1].first,&a[i][2].first,&a[i][3].first);
			a[i][1].second=1,a[i][2].second=2,a[i][3].second=3;
			sort(a[i]+1,a[i]+3+1,compare);
			if(q[a[i][1].second].size()==(n/2))
			{
				pair<long long,long long> x=q[a[i][1].second].top();
				if(x.first>=a[i][1].first-a[i][2].first)
				{
					q[a[i][2].second].push({a[i][2].first-a[i][3].first,i});
					ans+=a[i][2].first;
				}
				else
				{
					ans-=x.first;
					q[a[i][1].second].pop();
					q[a[x.second][2].second].push({a[x.second][2].first-a[x.second][3].first,x.second});
					q[a[i][1].second].push({a[i][1].first-a[i][2].first,i});
					ans+=a[i][1].first;
				}
			}
			else q[a[i][1].second].push({a[i][1].first-a[i][2].first,i}),ans+=a[i][1].first;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
