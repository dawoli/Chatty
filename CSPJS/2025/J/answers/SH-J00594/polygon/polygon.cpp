#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int arr[5005],sum[5005];
long long f[2][1000005][2];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k,i,j,id;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	for(i=1;i<=n;++i)
		sum[i]=sum[i-1]+arr[i];
	if(sum[n]<=10000000)
	{
		f[0][0][0]=1;
		id=1;
		for(i=1;i<=n;++i,id^=1)
		{
			for(j=0;j<=sum[i];++j)
			{
				f[id][j][0]=(f[id^1][j][0]+f[id^1][j][1])%MOD;
				if(j>=arr[i])
				{
					f[id][j][1]=(f[id^1][j-arr[i]][0]+f[id^1][j-arr[i]][1])%MOD;
					if(j>2*arr[i])
						ans=(ans+f[id][j][1])%MOD;
				}
				else
					f[id][j][1]=0;
			}
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
