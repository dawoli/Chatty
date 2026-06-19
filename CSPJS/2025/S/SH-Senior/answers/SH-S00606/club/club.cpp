#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 210
ll b0,c0;
ll n,a[N],b[N],c[N],dp[N][N/2][N/2][N/2],t,ans,d[N][N/2][N/2];
bool cmp(ll a,ll b)
{
	return a > b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		b0 = c0 = 1;
		ans = 0;
		scanf("%lld",&n);
		for(ll i = 1 ; i <= n ; i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(b[i] != 0) b0 = 0;
			if(c[i] != 0) c0 = 0;
		}
		if(b0 == 1 && c0 == 1)
		{
			sort(a+1,a+1+n,cmp);
			for(int i = 1 ; i <= n/2 ; i++) ans += a[i];
		}
		else if(c0 == 1)
		{
			for(ll i = 1 ; i <= n ; i++)
			{
				for(ll j = 0 ; j <= n/2&&j <= i ; j++)
				{
					ll k = i-j;
					if(k > n/2) continue;
					d[i][j][k] = 0;
					if(j > 0) d[i][j][k] = max(d[i][j][k],d[i-1][j-1][k]+a[i]);
					if(k > 0) d[i][j][k] = max(d[i][j][k],d[i-1][j][k-1]+b[i]);
					if(d[i][j][k] > ans) ans = d[i][j][k];
				}
			}
		}
		else
		{
			for(ll i = 1 ; i <= n ; i++)
			{
				for(ll j = 0 ; j <= n/2&&j <= i ; j++)
				{
					for(ll k = 0 ; k <= n/2&&j + k <= i ; k++)
					{
						ll l = i - j - k;
						if(l > n/2) continue;
						dp[i][j][k][l] = 0;
						if(j > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i]);
						if(k > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i-1][j][k-1][l]+b[i]);
						if(l > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i-1][j][k][l-1]+c[i]);
						if(dp[i][j][k][l] > ans) ans = dp[i][j][k][l];
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
