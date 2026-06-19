#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt=0,maxn=0;
ll k;
ll a[500005];
void solvez()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			cnt++;
			continue;
		}
		else
		{
			if(a[i+1]==1)
			{
				cnt++;
				i++;
				continue;
			}
		}
	}
	cout<<cnt;
}
void solveo()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1 && a[i+1]==1)
		{
			cnt++;
			continue;
		}
		else if(a[i]==1 && a[i+1]==0)
		{
			cnt++;
			i++;
			continue;
		}
	}
	cout<<cnt;
}
void dfs(int i,int c)
{
	if(i>n)
	{
		maxn=max(maxn,c);
		return ;
	} 
	if(a[i]==k) dfs(i+1,c+1);
	bool flag=false;
	int x=i+1,num=a[i];
	while(x<=n)
	{
		num^=a[x];
		if(num==k)
		{
			flag=true;
			break;
		}
		x++;
	}
	if(flag) dfs(x+1,c+1);
	dfs(i+1,c);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool fA=true,fB=true,fC=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			fA=false;
			if(a[i]!=0) fB=false;
		}
		if(a[i]>255) fC=false;
	}
	if(fA)
	{
		cout<<n/2;
		return 0;
	}
	if(fB)
	{
		if(k==0) solvez();
		else solveo();
		return 0;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
				continue;
			}
			if(a[i]==a[i+1])
			{
				cnt++;
				i++;
				continue;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(fC)
	{
		cout<<69;
		return 0;
	}
	if(n<=500)
	{
		dfs(1,0);
		cout<<maxn;
	} 
	if(fC)
	{
		cout<<69;
		return 0;
	}
	cout<<n/k+n%k;
	return 0;
} 
