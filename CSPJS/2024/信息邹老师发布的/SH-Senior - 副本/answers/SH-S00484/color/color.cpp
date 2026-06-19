#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll T,n,a[N],c[N],ans;
bool clr[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(ll i=0;i<=(1ll<<n)-1;i++)
		{
			ll sum=0;
			for(ll j=1;j<=n;j++) c[j]=0;
			ll temp=i,now=1;
			while(temp)
			{
				if(temp%2) clr[now]=1;
				else clr[now]=0;
				temp/=2;
				now++;
			}
			for(ll i=1;i<=n;i++)
				for(ll j=i-1;j>=1;j--)
					if(clr[i]==clr[j])
					{
						if(a[i]==a[j]) c[i]=a[i];
						break;
					}
			for(ll i=1;i<=n;i++) sum+=c[i];
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
