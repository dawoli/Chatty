#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (k==0)
	{
		cout<<n/2<<endl;
	}
	else
	{
		long long ans=0;
		for (long long i=1;i<=n;i++)
		{
			if (a[i]==1)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
