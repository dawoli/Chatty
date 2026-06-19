#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,cnt=0,sum=0,maxn;
int a[5005];
ll dp[5005][5005];
void dfs(int i,bool f,int s,int m)
{
	if(i>n+1) return ;
	if(s>2*m && f)
	{
		cnt=(cnt+1)%mod;
	}
	dfs(i+1,true,s+a[i],a[i]);
	dfs(i+1,false,s,m);
}
int C(int a,int b)
{
	ll Fz=1,Fm=1;
	for(int i=a;i>=a-b+1;i--) Fz=Fz*i%mod;
	for(int i=b;i>=1;i--) Fm=Fm*i%mod;
	return (Fz/Fm);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true,Fadd=true;
	maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i]; 
		maxn=max(maxn,a[i]);
		if(a[i]!=1) flag=false;
		if(a[i]!=a[i-1]+1) Fadd=false;
	}
	sort(a+1,a+n+1);
	if(n==3 && sum>2*a[n]) 
	{
		cout<<1;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,false,0,0);
		cout<<cnt%mod;
		return 0;
	}
	if(flag)
	{
		cnt=0;
		for(int i=n;i>=3;i--)
		{
			cnt=(cnt+C(n,i))%mod;
		}
		cout<<cnt;
		return 0;
	}
	if(Fadd)
	{
		cout<<(2*n-1)%mod;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=maxn;j++) dp[i][j]=0;
	}
	dp[0][0]=1,dp[1][a[1]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=maxn;j++)
		{
			dp[i][j]=(dp[i][j-a[i]]+dp[i-1][j])%mod;
		}
	}
	ll ans;
	for(int i=1;i<=maxn;i++)
	{
		ans=max(dp[n][i],ans);
	}
	cout<<ans%mod;
	return 0;
} 
