#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
#define N 5005
using namespace std;
ll n,a[N],ans;
int c(int x)
{
	int sum=0;
	x%=mod;
	while(x)
	{
		sum+=x;
		x-=1;
		sum%=mod;
	}
	return sum;
}
int check(int x)
{
	int sum=0;
	if(a[x]<(a[x-1]+a[x-2]))
	{
		sum+=x-2;
		sum%=mod;
	}
	for(int i=1;i<x;i++)
	{
		for(int j=x-1;j>i+1;j--)
		{
			if((a[i]+a[j])>a[x]) sum+=c(i);
			sum%=mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=a[i];
		for(int j=i;j<=(n-i);j++)
		{
			cnt+=a[j];
			cnt%=mod;
			if(cnt>a[x]) sum++;
			sum%=mod;
		}
	}
	return sum%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		ans+=check(i);
		ans%=mod; 
	}
	ans/=2;
	cout<<ans;
	return 0; 
}
