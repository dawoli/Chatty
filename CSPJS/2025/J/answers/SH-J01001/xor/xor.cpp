#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,f[500005],s[500005],a[500005],ans;
ll lst[2200005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]^a[i]);
	for(int i=1;i<=n;i++) lst[i]=-1;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(lst[(s[i]^k)]!=-1) f[i]=max(f[i-1],f[lst[(s[i]^k)]]+1);
		lst[s[i]]=i;
		ans=max(ans,f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
