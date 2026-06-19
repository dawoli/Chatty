#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m; 
int s[2005],a[2005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	int flagsi=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%1d",&s[i]);
		if(!s[i])
			flagsi=0;
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(flagsi)
	{
		long long ans=0;
		for(int i=1;i<=n;++i)
			ans=(ans*i)%MOD;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
