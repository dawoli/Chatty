#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[25],ans,nowans,c[25],tt;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ll num=(1<<n)-1;
		ans=0;
		for(int j=0;j<=num;j++)
		{
			tt=j;
			for(int k=n;k>=1;k--)
			{
				c[k]=tt%2;
				tt/=2;
			}
			nowans=0;
			for(int k=1;k<=n;k++)
				for(int o=k-1;o>0;o--)
				{
					if(c[o]==c[k])
					{
						if(a[k]==a[o]) nowans+=a[o];
						break;
					}
				}
			ans=max(ans,nowans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
