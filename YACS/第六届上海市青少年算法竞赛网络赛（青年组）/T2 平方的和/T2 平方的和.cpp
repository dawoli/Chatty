#include<bits/stdc++.h>
using namespace std;
#define long long int
int n,a[1000001],sum=0;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum+=(a[i]+a[j])*(a[i]+a[j])%1000000007;
			sum%=1000000007;
		}
	}
	cout<<sum%1000000007;
	return 0;
}
