#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int arr[5005],sum[5005],vis[5005];
long long ans;
void dfs(int layer,int bs,int t,int p,int pre)
{
	int i;
	if(layer>=bs)
	{
		if(p>arr[t])
		{
			ans=(ans+1)%MOD;
			//printf("%d %d %d %d\n",layer,bs,t,p);
		}
		return;
	}
	for(i=pre;i<=t-1;++i)
	{
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(layer+1,bs,t,p+arr[i],i);
		vis[i]=0;
	}
}
long long jc(int n)
{
	int i;
	long long r=1;
	for(i=1;i<=n;++i)
		r=(r*i)%MOD;
	return r;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j;
	long long k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	if(arr[n]<=1)
	{
		for(i=3;i<=n;++i)
			ans=(ans+jc(n)%MOD/(jc(i)%MOD*jc(n-i)%MOD)%MOD)%MOD;
		printf("%d",ans);
	}
	else
	{
		sum[1]=arr[1];
		for(i=2;i<=n;++i)
			sum[i]=sum[i-1]+arr[i];
		for(i=3;i<=n;++i)
		{
			if(sum[i-1]>arr[i])
				for(j=2;j<=n-1;++j)
					dfs(0,j,i,0,1);
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
