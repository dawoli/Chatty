#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l1,l2,l3,maxl;
	vector<int> maxn;
}a[100001];
bool cmp(node x,node y)
{
	return x.maxl>y.maxl;
}
int vis[4];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		int ans=0;
		memset(a,0,sizeof a);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			a[i].maxl=max(a[i].l1,max(a[i].l2,a[i].l3));
			if(a[i].l1==a[i].maxl)
			{
				a[i].maxn.push_back(1);
			}
			if(a[i].l2==a[i].maxl)
			{
				a[i].maxn.push_back(2);
			}
			if(a[i].l3==a[i].maxl)
			{
				a[i].maxn.push_back(3);
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int now=0,num=a[i].maxn.size();
			for(int j=0;j<num;j++)
			{
				if(vis[a[i].maxn[j]]<n/2)
				{
					if(now==0)
					{
						now=a[i].maxn[j];
					}
					else
					{
						if(vis[now]>vis[a[i].maxn[j]])
						{
							now=a[i].maxn[j];
						}
					}
				}
			}
			if(now==0)
			{
				if(min(vis[1],min(vis[2],vis[3]))==vis[1])
				{
					ans+=a[i].l1;
					vis[1]++;
				}
				else if(min(vis[1],min(vis[2],vis[3]))==vis[2])
				{
					ans+=a[i].l2;
					vis[2]++;
				}
				else if(min(vis[1],min(vis[2],vis[3]))==vis[3])
				{
					ans+=a[i].l3;
					vis[3]++;
				}
			}
			else
			{
				vis[now]++;
				ans+=a[i].maxl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
