#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int f[505][505],s[505],c[505],cnt[505],sum[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,fst=0,cnt1=0,i;
	long long ans=1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%1d",&s[i]);
		if(s[i]&&!fst)
			fst=i; 
		cnt1+=s[i];
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		++cnt[c[i]];
	}
	for(i=1;i<=n;++i)
		sum[i]=sum[i-1]+cnt[i];
	if(m>cnt1)
	{
		printf("0");
		return 0;
	}
	if(m==1)
	{
		ans=n-fst+1;
		for(i=2;i<=cnt1;++i)
			ans=ans*i%MOD;
	}
	else if(m==n)
	{
		for(i=1;i<=n;++i)
			ans=ans*i%MOD;
	}
	else if(cnt1==n)
	{
		for(i=1;i<=n;++i)
			ans=ans*(c[i]>=1?(c[i]-i+1):1)%MOD;
	}
	else
	{
		
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
