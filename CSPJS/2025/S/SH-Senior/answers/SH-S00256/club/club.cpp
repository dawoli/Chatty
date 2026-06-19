#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int d[3];
	int ma,mn;//最大值第几个
	bool operator<(const Node& x)const
	{
		return mn>x.mn;
	}
}a[100005];
int t,n;
priority_queue<Node>pq[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d[0]>>a[i].d[1]>>a[i].d[2];
			a[i].ma=(a[i].d[0]>=a[i].d[1]?0:1);
			a[i].ma=(a[i].d[a[i].ma]>=a[i].d[2]?a[i].ma:2);
			a[i].mn=2e9;
			for(int j=0;j<3;j++)
			{
				if(j==a[i].ma)continue;
				a[i].mn=min(a[i].mn,a[i].d[a[i].ma]-a[i].d[j]);
			}
			pq[a[i].ma].push(a[i]);
		}
		for(int i=0;i<3;i++)
		{
			while(pq[i].size()>n/2)
			{
				Node k=pq[i].top();
				pq[i].pop();
				int maxl=-1,maxn=-1;
				for(int j=0;j<3;j++)
				{
					if(j==i)continue;
					if(k.d[j]>maxl)
					{
						maxl=k.d[j];
						maxn=j;
					}
				}
				k.ma=maxn;
				pq[maxn].push(k);
			}
		}
		long long ans=0;
		for(int i=0;i<3;i++)
		{
			while(!pq[i].empty())
			{
				Node k=pq[i].top();
				pq[i].pop();
				ans+=k.d[k.ma];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
