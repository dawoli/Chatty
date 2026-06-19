#include<bits/stdc++.h>
using namespace std;
struct node
{
	int st,en;
}dl[2000005];
int dp[1005];
bool cmp(node x,node y)
{
	return x.en<y.en||x.en==y.en&&x.st>y.st;
}
int c=0;
int n,k;
int a[500005];
int cl[1005][1005];
int ans=0;
map<int,bool>mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=100)
	{
		for(int i=1;i<=n;i++)
		{
			int now=a[i];
			if(now==k)
			{
				c++;
				dl[c].st=i;
				dl[c].en=i;
			}
			for(int j=i+1;j<=n;j++)
			{
				now^=a[j];
				if(now==k)
				{
					c++;
					dl[c].st=i;
					dl[c].en=j;
				}
			}
		}
		sort(dl+1,dl+c+1,cmp);
		memset(dp,0,sizeof(dp));
//		cout<<c<<endl;
		for(int i=1;i<=c;i++)
		{
//			cout<<dl[i].st<<" "<<dl[i].en<<endl;
			for(int j=dl[i-1].en+1;j<=dl[i].en;j++)
			{
				dp[j]=dp[dl[i-1].en];
			}
			dp[dl[i].en]=max(dp[dl[i].en],dp[dl[i].st-1]+1);
		}
		cout<<dp[n]<<endl;
	}
	else
	{
		int now=0;
		for(int i=1;i<=n;i++)
		{
			now^=a[i];
			if(now==k||mp[now^k]>0)
			{
				ans++;
				now=0;
				mp.clear();
			}
			else
			{
				mp[now]=1;
			}
//			cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
