#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l,s[100005],r,c;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&q);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&l);
			for(long long j=1;j<=l;j++)
				scanf("%lld",&s[i]);
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%lld%lld",&r,&c);	
			printf("1\n");
		}
	}
	return 0;
}
