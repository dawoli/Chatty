#include<bits/stdc++.h>
using namespace std;
int n,q,f[301],a[301],m,d[301];
int deh(int u)
{
	if(u==0)return 1;
	else return deh(f[u])+1;
}
bool equal()
{
	for(int i=1;i<m;i++)
	{
		if(a[i]!=a[i+1])return false;
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>f[i];
	for(int i=0;i<n;i++)
		d[i]=deh(i);
	cin>>q;
	while(q--)
	{
		cin>>m;
		int md=INT_MAX;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
			md=min(md,d[a[i]]);
		}
		for(int j=1;j<=m;j++)
		{
			while(d[a[j]]!=md)
			{
				a[j]=f[a[j]];
			}
		}
		while(!equal())
		{
			for(int i=1;i<=m;i++)
			{
				a[i]=f[a[i]];
			}
		}
		int ans=a[1];
		while(a[1]!=0)
		{
			a[1]=f[a[1]];
			ans=max(ans,a[1]);
		}
		cout<<ans<<endl;
	}
}