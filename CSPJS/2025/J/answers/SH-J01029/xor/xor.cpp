#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500003],x;
long long sum,mx;
bool vis[500005];
long long xxor(long long x,long long y)
{
	bool z[10005];
	long long cnt=0,o=0;
	while(x>0||y>0)
	{
		cnt++;
		if(x%2!=y%2)
		{
			z[cnt]=1;
		}
		else
		{
			z[cnt]=0;
		}
		x=x/2;
		y=y/2;
	}
	for(int i=1;i<=cnt;i++)
	{
		o=o*2+z[cnt-i+1];
	}
	return o;
}
void solve(long long x,long long y)
{
	long long z=c[x];
	mx=max(mx,y);
	for(int i=x+1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			z=0;
			continue ;
		}
		else
		{
			z=xxor(z,c[i]);
			if(z==m)
			{
				solve(i+1,y+1);
				return ;
			}
		}
	}
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==m)
		{
			vis[i]=1;
			sum++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			continue;
		}
		solve(i,sum);
	}
	cout<<mx;
	return 0;
}
