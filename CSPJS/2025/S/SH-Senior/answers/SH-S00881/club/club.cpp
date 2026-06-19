#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int a[100005],b[100005],c[100005];
long long dp[2][205][205];
int s1[100005],s2[100005];
int cur1=0,cur2=0,cur3=0;
bool cmp1(int x,int y)
{
	return a[x]-b[x]<a[y]-b[y];
}
bool cmp2(int x,int y)
{
	return b[x]-a[x]<b[y]-a[y];
}
void solve()
{
	cin>>n;
	int f1=1,f2=1;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]==1)f1=0;
		if(c[i]==1)f2=0;
	}
	if(n<=200)
	{
		memset(dp,0,sizeof(dp));
		long long ans=0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= n/2&&j<=i;j++)
			{
				for(int k = 0;k <= n/2&&k+j<=i;k++)
				{
					int l=i-j-k;
					dp[i%2][j][k]=0;
					if(j>0)dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j-1][k]+a[i]);
					if(k>0)dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j][k-1]+b[i]);
					if(l>0)dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j][k]+c[i]);
					ans=max(ans,dp[i%2][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		sort(a+1,a+n/2+1);
		long long ans=0;
		for(int i = n/2+1;i <= n;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
		/*int cur1=0,cur2=0;
		long long ans=0;
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for(int i = 1;i <= n;i++)
		{
			if(a[i]>=b[i])s1[++cur1]=i,ans+=a[i];
			else s2[++cur2]=i,ans+=b[i];
		}
		if(cur1>n/2)
		{
			sort(s1+1,s1+cur1+1,cmp1);
			for(int i = 1;i <= cur1-n/2;i++)
			{
				ans-=a[i]-b[i];
			}
			cout<<ans<<endl;
		}
		else if(cur2>n/2)
		{
			sort(s2+1,s2+cur2+1,cmp2);
			for(int i = 1;i <= cur2-n/2;i++)
			{
				ans-=b[i]-a[i];
			}
			cout<<ans<<endl;
		}*/
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
