#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5010],sum[5010],ans=0,vis[5010],pk;
void dfs(int sum,int maxx,int len)
{
	if(len>=3)
	{
		if(sum>2*maxx)
		{
			ans=(ans+1+mod)%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			sum+=a[i];
			pk=maxx;
			maxx=max(maxx,a[i]);
			vis[i]=1;
			len++;
			dfs(sum,maxx,len);
			len--;
			sum-=a[i];
			maxx=pk;
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=0;
	dfs(0,0,0);
	cout<<ans%mod;
}
