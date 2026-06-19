#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,m;
int k;
int task[505];
int c[505],C;
int totc[505],pos,l,r,tottask;
long long ans;
bool fA=1;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=n;i>=1;i--)
	{
		task[i]=k%10;
		if(fA&&task[i]==0)fA=0;
		tottask+=task[i];
		k/=10;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>C;
		c[C]++;
	}
	for(int i=1;i<=n;i++)
	{
		totc[i]=totc[i-1]+c[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(task[i]==1)
			{
				pos=i;
				break;
			}
		}
		if(totc[n]-totc[pos-1]==0)ans=0;
		else
		{
			ans=totc[n]-totc[pos-1];
			l=totc[pos-1];
			r=n-l-1;
			
			for(int i=1;i<=n-1;i++)
			{
				ans*=i;
				ans%=mod;
			}
			
		}
	}
	else if(m==n)
	{
		if(fA)
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=mod;
			}
		}
		else ans=0;
	}
	else
	{
		if(fA)
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=mod;
			}
		}
		else if(tottask<m)
		{
			ans=0;
		}
		else
		{
			if(n==1)
			{
				if(tottask>=m)ans=1;
				else ans=0;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
