#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1000000],sum[1000000],ans2;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(ll i=0;i<n;i++)
	{
		ll ans=a[i];
		for(ll j=i+1;j<n;j++)
		{
			ans=ans^a[j];
		}
		if(ans==k)
		{
			ans2++;
		}
	} 
	cout<<ans2;
	return 0;
}

