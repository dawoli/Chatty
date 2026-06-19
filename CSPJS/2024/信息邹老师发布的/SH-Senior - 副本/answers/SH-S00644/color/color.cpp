#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll T;
ll n,a[N];
ll dp[2005][2005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
		}
		if(n<=2005)
		{
			memset(dp,0,sizeof(dp));
			for(int t=1;t<=n;++t)
			{
				for(int i=0;i<t;++i)//上一位一定为蓝色或者红色，故枚举剩下的一个颜色即可 
				{
					ll ad=0; 
					if(a[t]==a[t-1]) ad=a[t];
					dp[t][i]=max(dp[t][i],dp[t-1][i]+ad);//t-1红t红
					dp[i][t]=max(dp[i][t],dp[i][t-1]+ad);//t-1蓝t蓝
					ad=0;
					if(a[t]==a[i]) ad=a[t];
					dp[t][t-1]=max(dp[t][t-1],dp[i][t-1]+ad); 
					dp[t-1][t]=max(dp[t-1][t],dp[t-1][i]+ad);
				}
			}
			ll ans=0;
			for(int i=0;i<=n;++i) ans=max(ans,max(dp[n][i],dp[i][n]));
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
n<=100时，可以考虑dp[n][last_red][last_blue]查找最大值
最终最大值一定为max({dp[n][i][n]},{dp[n][n][i]}) 
由覆盖性可以删除第一维，范围扩展到n<=2000，目标50pts 
*/
