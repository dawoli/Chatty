#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m,ans; 
int a[5005];
long long fac[20005],inv[20005];
void dfs(int layer,int pre,int sum,int maxn)
{
	if(layer>m)
	{
		if(sum>2*maxn)
			ans++;
		return;
	}
	for(int i=pre+1;i<=n;++i)
		dfs(layer+1,i,sum+a[i],max(maxn,a[i]));
}
void init()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	for(int i=2;i<=20000;++i)
		inv[i]=(-MOD/i*inv[MOD%i]+MOD)%MOD;
	for(int i=2;i<=20000;++i)
	{
		inv[i]=inv[i-1]*inv[i]%MOD;
		fac[i]=fac[i-1]*i%MOD;	
	}	
} 
long long C(int x,int y)
{
	return (fac[x]*inv[y]%MOD*inv[x-y]%MOD+MOD)%MOD;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n<=20)
	{
		for(int i=3;i<=n;++i)
		{
			m=i;
			dfs(1,0,0,0);
		}
		printf("%d\n",ans);
	}
	else
	{
		init();
		long long s=0;
		for(int i=3;i<=n;++i)
			s=(s+C(n,i))%MOD;
		printf("%lld\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
