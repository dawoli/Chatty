#include<bits/stdc++.h>
#define N 200000

using namespace std;

long long n,tmp=0,tot=0,sum=0,loc=0,ava=0;
long long a[N];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	tmp=a[n-1];
	loc=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]==tmp)
		{
			sum++;
		}
		else
		{
			if(sum>ava)
			{
				tot+=sum-ava;
				ava=sum;
			}
			sum=1;
			tmp=a[i];
			loc=i;
		}
	}
	if(sum>ava)
	{
		tot+=sum-ava;
	}
	printf("%lld",tot);
	return 0;
}

