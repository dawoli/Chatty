#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<bitset>
using namespace std;
const long long max_n=16;
long long a[max_n];
bool take[max_n];
long long mark=0;
long long find_pos(long long tar)
{
	bool flag=take[tar];
	for(long long i=tar-1;i>=1;i--)
		if(take[i]==flag)
			return i;
	return 0;
}
long long cala(long long n)
{
	long long t=mark;
	for(long long i=n;i>=1;i--)
	{
		take[i]=t&1;
		t>>=1;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
		if(find_pos(i)&&a[i]==a[find_pos(i)])
			ans+=a[i];
	return ans;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%d",&n);
		for(long long i=1;i<=n;i++)
			scanf("%d",&a[i]);
		long long ans=0;
		for(mark=0;mark<(1<<n+1);mark++)
			ans=max(ans,cala(n));
		printf("%d\n",ans );
	}
	return 0;
}
