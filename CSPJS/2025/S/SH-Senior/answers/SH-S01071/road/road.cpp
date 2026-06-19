#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int g[10000][10000];

//djis?


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//read
	int n,m,k;
	cin>>n>>m>>k;
	//int g[n+1][n+k+1];
	
	for(int i=1;i<=m;i++)
	{
		int a,b,val;
		cin>>a>>b>>val;
		g[b][a]=g[a][b]=val;
	}
	
	
	if(k!=0)
	{
		for(int i=n+1;i<=n+k;i++)
		{
			int ival;
			cin>>ival;
			int v[n+1];
			for(int j=1;j<=n;j++)
			{
				cin>>v[j];
				g[i][j]=v[j]+ival;
			}
		}
	}
	
	
	//calc
	for(int i=1;i<n;i++)
	{
		for(int j=2;j<=n and j>i;j++)
		{
			if(j>i)
			{
				int cur=g[i][j];
				for(int k=1;k<=n+k and k!=i and k!=j;k++)
				{
					if(g[k][i]!=0 and g[k][j]!=0)
					{
						cur=min(cur,g[k][i]+g[k][j]);
					}
				}
				g[i][j]=cur;
			}
		}
	}
	
	
	
	
	
	
	
	//answer
	int ans=0;
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(j>i)
			{
				cout<<g[i][j]<<endl;
				ans+=g[i][j];
			}
		}
	}
	
	cout<<ans;
	fclose(stdin);
	return 0;
}
