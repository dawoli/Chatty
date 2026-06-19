#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int p=998244353;
int n,a[5005],cnt,sum,maxa,ans;
bool T_15_20=1;
bool c[25];
void dfs(int x)
{
	if (x==n+1)
	{
		if (cnt>=3&&sum>maxa*2) ans++;
		return ;
	}
	c[x]=1,cnt++,sum+=a[x];
	int maxa_pre=maxa;
	maxa=a[x];
	dfs(x+1);
	c[x]=0,cnt--,sum-=a[x],maxa=maxa_pre;
	dfs(x+1);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>1) T_15_20=0;
	}
	sort(a+1,a+n+1);
	if (T_15_20)
	{
		ans=1;
		for (int i=1;i<=n;i++) ans=ans*2%p;
		ans=(ans+p-(n*n+n+2)/2)%p;
		printf("%d",ans);
	}
	else dfs(1);
	printf("%d",ans);
	return 0;
}
