#include<bits/stdc++.h>
using namespace std;
map<long long,long long> m;
long long a[500011];
long long sum[500011];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]^a[i];
	long long pre=0;
	long long ans=0;
	for(int i=0;i<=n;i++)
	{
		long long temp=sum[i]^k;
		if(m.count(temp)&&m[temp]>=pre)ans++,pre=i;
		m[sum[i]]=i;
	}
	printf("%lld\n",ans);
	return 0;
}
