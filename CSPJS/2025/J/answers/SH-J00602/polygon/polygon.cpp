#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
int arr[5005];
const int mod=998244353;
int goal,ans;
void dfs(int layer,int cnt)
{
	if(cnt>=goal)
	{
		int maxv=0;
		int sum=0;
		for(int i=1;i<=goal;i++)
		{
			maxv=max(maxv,a[arr[i]]);
			sum+=a[arr[i]];
		}
		if(sum>maxv*2) ans=(ans+1)%mod;
		return;
	}
	if(layer>n)
		return;
	arr[cnt+1]=layer;
	dfs(layer+1,cnt+1);
	dfs(layer+1,cnt);
}
vector<long long> yh[5005]; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int maxv=0;
	for(int i=1;i<=n;i++)
		maxv=max(maxv,a[i]);
	if(maxv==1)
	{
		yh[0].push_back(1);
		for(int i=1;i<=n;i++)
		{
			yh[i].resize(i+1);
			yh[i][0]=yh[i][i]=1;
			for(int j=1;j<i;j++)
				yh[i][j]=(yh[i-1][j]+yh[i-1][j-1])%mod;
		}
		for(int i=3;i<=n;i++)
			ans=(ans+yh[n][i])%mod;
		cout<<ans;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			goal=i;
			dfs(1,0);
		}
		cout<<ans;
	}
	return 0;
}
