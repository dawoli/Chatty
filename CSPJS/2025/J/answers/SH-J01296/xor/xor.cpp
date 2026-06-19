#include<bits/stdc++.h>
using namespace std;

long long n,k,r,ans;
long long a[500005],pfx[500005];
bool flag=true;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(k!=0 && k!=1)
		flag=false;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pfx[i]=pfx[i-1] ^ a[i];
		if(flag && a[i]!=0 && a[i]!=1)
			flag=false;
	}
	if(flag)
	{
		if(k==0)
		{
			long long lastt=0;
			for(long long i=1;i<=n;i++)
			{
				if(a[i]==0 || lastt==1)
					ans++,lastt=0;
				else
					lastt=1;
			}
		}
		if(k==1)
		{
			for(long long i=1;i<=n;i++)
				if(a[i]==1)
					ans++;
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++)
		for(long long j=i;j>r;j--)
			if( (pfx[i]^pfx[j-1]) == k )
				ans++,r=i;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
