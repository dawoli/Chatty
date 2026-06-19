#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,a[500005],c[500005],DP[500005],ANS;
int main()
{
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]^a[i];
		DP[i]=0;
	}
	DP[0]=0;
	if(n<=1000)
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			DP[i]=max(DP[i],DP[j]+((c[i]^c[j])==k));
		}
	}
	else
	for(int i=1;i<=n;i++)
	{
		for(int j=max(i-k,0ll);j<=i;j++)
		{
			DP[i]=max(DP[i],DP[j]+((c[i]^c[j])==k));
		}
	}
	cout<<DP[n];
	return 0; 
}
