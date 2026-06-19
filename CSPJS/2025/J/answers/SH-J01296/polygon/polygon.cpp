#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;
long long n,a[5005],ans;
bool flag=true;

long long func(long long a,long long m)
{
	long long anss=1;
	for(long long i=1;i<=m;i++)
		anss=(anss*a)%MOD;
	return anss;
}

void dfs(long long step,long long sum,long long maxx,long long cnt)
{
	if(step>n)
	{
		if(cnt>=3 && sum>2*maxx)
			ans=(ans+1)%MOD;
		return;
	}
	dfs(step+1, sum, maxx, cnt);
	dfs(step+1, sum+a[step], max(maxx,a[step]), cnt+1);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(flag && a[i]!=1)
			flag=false;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(flag)
	{
		ans=func(2,n);
		ans=( ans+MOD-1-n-n*(n-1)/2 )%MOD;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
