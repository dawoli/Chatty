#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,ans,qz[5005];
long long mod=998244353;
bool f=1;
void dfs(long long pos,long long cnt,long long maxb,long long sum)
{
	if(pos==n+1)
	{
		if(cnt>=3&&sum>2*maxb) ans++;
		ans%=mod;
		return;
	}
	dfs(pos+1,cnt,maxb,sum);
	dfs(pos+1,cnt+1,max(maxb,a[pos]),sum+a[pos]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f==1)
	{
		qz[0]=1;
		for(int i=1;i<=n;i++)
		{
			qz[i]=qz[i-1]*i%mod;
		}
		for(int i=3;i<=n;i++)
		{
			long long t=0;
			t=(qz[n]/qz[n-i])/(qz[i]);
			ans=(ans+t)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
