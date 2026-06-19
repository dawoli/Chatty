#include<bits/stdc++.h>
#define INF (INT_MAX/2)
using namespace std;
int n,m,fr[2001][2001],fw[2001][2001],cnt=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (i==j) fr[i][j]=fw[i][j]=0;
			else fr[i][j]=fw[i][j]=INF;
		}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		fr[u][v]=fw[u][v]=w;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				fr[i][j]=min(fr[i][j],fr[i][k]+fr[k][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				fw[i][j]=min(fw[i][j],fw[i][k]+fw[k][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (fr[i][j]!=fw[i][j]) cnt++;
	cout<<cnt<<endl;
	return 0;}