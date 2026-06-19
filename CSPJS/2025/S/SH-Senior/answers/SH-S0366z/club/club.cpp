#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+5;
int a[4][N];
int sum[N];
int sz[N];
int n,ans=-1;
int dp[N][4];
void dfs(int s)
{
	if(s>n)
	{
		ans=max(ans,sum[1]+sum[2]+sum[3]);
		return;
	}
	for(int i=1; i<=3; i++)
	{
		if(sz[i]==n/2) continue;
		sum[i]+=a[i][s];
		sz[i]++;
		dfs(s+1);
		sum[i]-=a[i][s];
		sz[i]--;
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
		cin>>n;
		ans=-1;
		bool f2=true,f3=true;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]) f2=false;
			if(a[3][i]) f3=false;
		}
		if(f2&&f3)
		{
			sort(a[1]+1,a[1]+n);
			ans=0;
			for(int i=n/2+1;i<=n;i++) ans+=a[1][i];
			cout<<ans<<endl;
		}
//		else if(f3)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				for(int j=n/2;j>=1;j--)
//				{
//					dp[j][1]=max(dp[j][1],dp[j-1][1]+a[1][i]);
//					dp[j][2]=max(dp[j][2],dp[j-1][2]+a[2][i]);
//				}
//			}
//		}
		else
		{
			 dfs(1);
			 cout<<ans<<endl;
		}
	}
	return 0;
}

