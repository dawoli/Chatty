#include<bits/stdc++.h>
using namespace std;
struct rd
{
	int u,v,w;
}a[1000005];
long long p[50000005];
long long edge[10001][10001];
long long c[11];
long long q[11][10001];
long long t=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		edge[a[i].u][a[i].v]=edge[a[i].v][a[i].u]=a[i].w;
	}
	/* 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<edge[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	long long ans=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(edge[i][j])
			{
				t++;
				p[t]=edge[i][j];
			}
			//cout<<i<<" "<<j<<" "<<edge[i][j]<<endl;
		}
	}
	sort(p+1,p+t+1);
	for(int i=1;i<n;i++)
	{
		ans+=p[i];
	}
	//cout<<k<<endl;
	/*
	for(int i=1;i<=t;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	*/
	cout<<ans<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	return 0;
}
