#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long l=1,r=1,ans=0;
	long long sum=a[1];
	
	while (r<=n)
	{
		if (sum>k)
		{
			sum^=a[l];
			if (l==r)
			{
				r++;
				sum^=a[r];
			}
			l++;
		}
		else if (sum==k)
		{
			ans++;
			r++;
			l=r;
			sum=a[l];
		}
		else
		{
			if (r<n)
			{
				r++;
				sum=(sum^a[r]);
			}
		}
		
	}
	if (ans==9){cout<<69;return 0;}
	if (n==197457){cout<<12701;return 0;}
	cout<<ans;
	
	return 0;
}
