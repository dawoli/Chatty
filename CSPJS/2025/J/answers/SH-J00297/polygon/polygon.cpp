#include<bits/stdc++.h>
using namespace std;
int n,a[5005],k;
long long ans,b[5005];
void dfs(int step,int big,int sum,int cnt)
{
	if(step>n)
	{
		if(cnt<=2 or sum<=big*2)return;
		else ans=(ans+1)%998244353;
	}
	else
	{
		dfs(step+1,big,sum,cnt);
		dfs(step+1,a[step],sum+a[step],cnt+1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)k++;
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	if(k==n) 
	{
		b[3]=n*(n-1)*(n-2)/6%998244353;
		for(int i=4;i<=n;i++)
		{
			b[i]=b[i-1]*(n+1-i)/i%998244353;
		}
		for(int i=3;i<=n;i++)
		{
			ans=(ans+b[i])%998244353;
		}
		cout<<ans;
		return 0;
	}
}
