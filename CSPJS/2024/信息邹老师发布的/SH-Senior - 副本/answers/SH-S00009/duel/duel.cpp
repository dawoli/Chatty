#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,sum,ans,a[N],b[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			j++;
		b[j]++;
	}
	sum=b[1];
	for(int i=2;i<=n;i++)
	{
		if(b[i]>sum)
		{
			ans+=sum;
			sum=b[i];
		}
		else if(b[i]<sum)
		{
			ans+=b[i];
		}
		else if(b[i]==sum)
		{
			ans+=sum;
			sum=b[i];
		}
	}
	printf("%lld",n-ans);
	return 0;
}
