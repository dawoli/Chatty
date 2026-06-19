#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005];
bool col[1000005];
long long ans=-1e18;
void dfs(long long dep)
{
	if(dep==n+1)
	{
		long long res=0;
		long long lst0=0,lst1=0;
		for(int i=1;i<=n;i++)
		{
			if(col[i]==0)
			{
				if(a[lst0]==a[i])
				{
					res+=a[i];
				}
				lst0=i;
			}
			else if(col[i]==1)
			{
				if(a[lst1]==a[i])
				{
					res+=a[i];
				}
				lst1=i;
			}
		}
		ans=max(ans,res);
		return;
	}
	col[dep]=1;
	dfs(dep+1);
	col[dep]=0;
	dfs(dep+1);
	col[dep]=0;
}
void solve()
{
	ans=-1e18;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		col[i]=0;
	}
	dfs(1);
	printf("%lld\n",ans);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n); 
		if(n<=15)
		{
			solve();
		}
	}
	return 0;
}
