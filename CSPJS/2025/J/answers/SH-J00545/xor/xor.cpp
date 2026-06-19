#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100005],cnta[100005],dp[1005][1005],f[100005];
bool flagB=1;
namespace specialB
{
	void f()
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(m==1)
			{
				if(a[i]==1)ans++;
			}
			else
			{
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i-1]==1)
				{
					a[i]=2;
					ans++;
				}
			}
		}
		cout<<ans;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]>2)
		{
			flagB=0;
		}
		cnta[i]=cnta[i-1]^a[i];
	}
	if(flagB)
	{
		
		specialB::f();
		return 0;
	}
	if(n<=100)
	{
		for(int len=1;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				dp[i][j]=((cnta[j]^cnta[i-1])==m);
				for(int k=i;k<j;k++)
				{
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
		cout<<dp[1][n];
		return 0;
	}
	if(n<=100000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				f[i]=max(f[i],f[j]+((cnta[j]^cnta[i])==m));
			}
		}
		cout<<f[n];
	}
	return 0;
}
