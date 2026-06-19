#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],f[5005],s[5005],ans,mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1,s[0]=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+s[a[i]+1])%mod;
		f[5001]=(f[5001]+s[5001-a[i]])%mod;
		for(int j=5000;j>=a[i];j--) f[j]=(f[j-a[i]]+f[j])%mod;
		for(int j=5001;j>=0;j--) s[j]=(s[j+1]+f[j])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
