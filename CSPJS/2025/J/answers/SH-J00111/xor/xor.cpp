#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+7;
int n,x,ans=0,maxx=0,pk;
int a[N],sum[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=n;i>=1;i/=2)
	{
		for(int k=0;k<=n;k+=i)
		{
			ans=0;
			if(sum[k]==x)
			{
				ans++;
			}
			else if(sum[n]^sum[k]==x)
			{
				ans++;
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx*2;
	return 0;
}
