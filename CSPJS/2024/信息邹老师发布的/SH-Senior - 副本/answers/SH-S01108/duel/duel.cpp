#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005];
long long mp[1000005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	long long maxx=-1e18;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]); 
		maxx=max(maxx,a[i]);
		mp[a[i]]++;
	}
	long long num=0;
	for(int i=0;i<=maxx;i++)
	{
		long long val=mp[i];
		if(val!=0)
		{
			if(val>num)
			{
				num=val;
			}
		}
	}
	printf("%lld\n",num);
	return 0;	
}
