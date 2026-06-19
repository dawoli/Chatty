#include<bits/stdc++.h>
using namespace std;
#define M 1000006
long long n,m,k,a[M],b[M],c[M],e[M],d[20][M],f[M],an[M];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		an[i]=10000000009;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>e[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
			if(d[i][j]==0)
			{
				f[j]=1;
				an[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(f[a[i]]==0)
		{
			an[a[i]]=min(an[a[i]],c[i]);
			if(f[b[i]]==0)
			{
				an[b[i]]=min(an[b[i]],c[i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			for(int j=1;j<=k;j++)
			{
				an[i]=min(an[i],d[j][i]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=an[i];
	}
	cout<<ans<<endl;
	return 0;
} 
