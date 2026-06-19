#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000,MOD=998244353;
long long n,a[MAXN+5],sum,maxn,lst[MAXN+5];
long long ans;

long long c[MAXN+5];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k)
{
	for (int i=x;i<=a[n]+1;i+=lowbit(i))
	{
		c[i]=(c[i]+k)%MOD;
	}
}
int query(int x)
{
	long long ans=0;
	for (int i=x;i>=1;i-=lowbit(i))
	{
		ans=(ans+c[i])%MOD;
	}
	return ans;
}

void dfs(int pos,int sum)
{
	if (pos==n+1)
	{
		return;
	}
	if (sum>a[pos])
	{
		ans=(ans+1)%MOD;
	}
	dfs(pos+1,sum);
	dfs(pos+1,sum+a[pos]);
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
int main()
{
	init();
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		ans=(ans+(query(a[n]+1)+MOD-query(a[i]))%MOD)%MOD;
		long long t=(query(a[n]+1)+MOD-query(a[n]+1-a[i]))%MOD;
		sum=min(sum+a[i],a[n]+1);
		for (int j=sum;j>=a[i]+1;j--)
		{
			lst[j]=(lst[j]+lst[j-a[i]])%MOD;
			add(j,lst[j-a[i]]);
		}
		if (sum>a[n])
		{
			lst[a[n]+1]=(lst[a[n]+1]+t)%MOD;
			add(a[n]+1,t);
		}
		add(a[i],1);
		lst[a[i]]=(lst[a[i]]+1);
	}
//	dfs(1,0);
	cout<<ans;
	return 0;
}
