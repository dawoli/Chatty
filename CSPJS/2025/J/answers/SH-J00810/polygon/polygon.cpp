#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int arr[5005];
int tmp[5005];
long long yh[5005][5005];
long long ans;
int n;
bool check(int len)
{
	long long sum=0;
	for(int i=1;i<=len;i++)
	{
		sum+=tmp[i];
	}
	return sum>(2*tmp[len]);
}
void yh_init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||i==j)
				yh[i][j]=1;
			else
				yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
			yh[i][j]%=MOD;
		}
	}
	return ;
}
void dfs(int layer,int lmt,int pre)
{
	if(layer>lmt)
	{
		if(check(lmt))
		{
			ans++;
			ans%=MOD;
		}
		return ;
	}
	for(int i=pre+1;i<=n;i++)
	{
		tmp[layer]=arr[i];
		dfs(layer+1,lmt,i);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int flagA=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]!=1)
			flagA=0;
	}
	yh_init();
	sort(arr+1,arr+1+n);
	if(flagA)
	{
		long long sum=0;
		for(int i=3;i<=n;i++)
		{
			sum+=yh[n][i];
			sum%=MOD;
		}
		printf("%lld\n",sum);
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			dfs(1,i,0);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
