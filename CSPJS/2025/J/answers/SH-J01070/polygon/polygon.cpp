#include <bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[5005];
long long n;
long long mo=998244353;
void dfs(long long step,long long sum,long long maxn,long long cnt)
{
	if (step>n)
	{
		if (sum>2*maxn && cnt>=3)	ans++;
		ans%=mo;
		return ;
	}
	dfs(step+1,sum,maxn,cnt);
	dfs(step+1,sum+a[step],max(maxn,a[step]),cnt+1);
	return ;
}
long long qpow(long long p,long long q,long long mod)
{
	long long mul=1;
	if (q==1)	return p;
	if (q==0)	return 1;
	long long temp=qpow(p,q/2,mod);
	mul*=temp;
	mul%=mod;
	mul*=temp;
	mul%=mod;
	if (q%2==1)	mul*=p;
	mul%=mod;
	return mul;
}
long long rev(long long p,long long mod)
{
	return qpow(p,mod-2,mod);
}
long long C(long long N,long long m)
{
	if (N-m<m)	m=N-m;
	long long mul=1;
	long long temp=1;
	for (long long i=N;i>=N-m+1;i--)
	{
		mul*=i;
		mul%=mo;
		mul*=rev(temp,mo);
		mul%=mo;
		temp++;
	}
	return mul;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1)	flag=false;
	}
	if (flag)
	{
		ans=0;
		for (int i=3;i<=n;i++)
		{
			ans+=C(n,i);
			ans%=mo;
		}
		cout<<ans<<endl;
	}
	else
	{
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

