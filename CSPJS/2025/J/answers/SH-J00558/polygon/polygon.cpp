#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int N=5010;
int n;
int a[N]={0};
int ans=0;
void dfs(int num,int sum,int maxn)
{
	if(num>n)
	{
		if((maxn<<1)<sum)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(num+1,sum,maxn);
	dfs(num+1,sum+a[num],max(maxn,a[num]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	dfs(1,0,0);
	printf("%d",ans);
	
	return 0;
}
