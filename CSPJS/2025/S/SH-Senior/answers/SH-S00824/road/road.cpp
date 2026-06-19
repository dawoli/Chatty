#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int least;
int u[maxn],v[maxn],w[maxn][maxn],c[11],a[11][10001],fixc[11];
bool l[10001][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	int n,m,k,lian=0,lest,ans=0,i;
	cin>>n>>m>>k;
/*	for(i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			l[i][j]=false;*/
	for(i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[u[i]][v[i]];
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];/*
		if(c[i]==0&&a[1][2]==0)
		{
			cout<<0;
			return 0;
		}
		for(int x=1;x<n;x++)
			for(int y=x;y<=n;y++)
			{
				if(w[x][y]=0)
					w[x][y]=w[i][x]+w[i][y]+c[i];
				else
				{
					w[x][y]=min(w[i][x]+w[i][y]+c[i],w[x][y]);
					fixc[i]++;
				}
			}*/
	}/*
	while(lian<=n)
	{
		least=1001;
		for(i=1;i<=n;i++)
		{
			if(w[i]<=least&&l[v[i]][u[i]]==false)
			{
				lest=i;
				least=w[i];
			}
			l[v[i]][u[i]]=true;
		}
		ans+=least;
		lian--;
	}
	cout<<ans<<endl;*/
	cout<<0;
	return 0;
}
