#include<bits/stdc++.h>
#define int long long
using namespace std;
const int lim=5e3,N=5e3,p=998244353ll;
int dp[lim+10];
int n,ans=0;
int q_m(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1) ret*=x,ret%=p;
		x*=x,x%=p;
		y>>=1;
	}
	return ret;
}
int a[N+10];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=a[i];j++) 
		{
			(ans+=dp[j])%=p;
		}
		for(int j=lim;j>=a[i];j--)
		{
			(dp[j]+=dp[j-a[i]])%=p;
		}
	} 
	cout<<(((-ans+q_m(2,n)-1)%p)+p)%p;
	return 0;
}
