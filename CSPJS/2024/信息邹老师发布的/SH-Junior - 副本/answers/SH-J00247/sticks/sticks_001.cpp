#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long dfs(long long rest,long long f,long long ans,long long now,long long n)
{
	if(rest==0&&now==n)
	{
		return ans;
	}
	if(rest==0&&now!=n)
	{
		return 1e18;
	}
	if(rest==f)
	{
		long long mina=1e18;
		for(int i=1;i<=9;i++)
		{
			mina=min(mina,dfs(rest-1,f,ans+i*pow(10,rest-1),now+a[i],n));
		}
		return mina;
	}
	long long minb=1e18;
	for(int i=0;i<=9;i++)
	{
		minb=min(minb,dfs(rest-1,f,ans+i*pow(10,rest-1),now+a[i],n));
	}
	return minb;
}
int t;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++)
	{
		int n;
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
			continue;
		}
		if((n-1)%7==0)
		{
			cout<<-1<<endl;
			continue;
		}
		int f=n/7+1;
		cout<<dfs(f,f,0,0,n)<<endl;
	}
	return 0;
}
