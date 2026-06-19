#include<bits/stdc++.h>
#define N 1000
using namespace std;
int n,m,f[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j)f[i][j]=0;
			else f[i][j]=INT_MAX/2;
		}
	}
	for (int i=1;i<=m;i++)
	{
		int p,q,t;
		cin>>p>>q>>t;
		f[p][q]=t;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				if (f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<f[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}