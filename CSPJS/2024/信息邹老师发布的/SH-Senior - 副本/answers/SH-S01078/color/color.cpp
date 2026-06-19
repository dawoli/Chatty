#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int ans,t,n,a[maxn]={0},t1=0,t2=maxn,last=0;
int f[maxn][11][11]={0};
int g[105][105][105]={0};
int main()
{
	freopen("color.in","r",stdin); 
	freopen("color.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=100)
		{
			for(int i=1;i<=n;i++)
				for(int j=0;j<=101;j++)
					for(int k=0;k<=101;k++)
						g[i][j][k]=-1e9;
			for(int i=1;i<=n;i++) cin>>a[i];
			g[1][a[1]][0]=0;
			g[1][0][a[1]]=0;
			for(int i=2;i<=n;i++)
			{
				for(int k=0;k<=100;k++)
				{
					g[i][a[i]][k]=max(g[i-1][a[i]][k]+a[i],g[i][a[i]][k]);
					for(int j=0;j<=100;j++)
					{
						g[i][a[i]][k]=max(g[i-1][j][k],g[i][a[i]][k]);
					}
				}
				for(int k=0;k<=100;k++)
				{
					g[i][k][a[i]]=max(g[i-1][k][a[i]]+a[i],g[i][k][a[i]]);
					for(int j=0;j<=100;j++)
					{
						g[i][k][a[i]]=max(g[i-1][k][j],g[i][k][a[i]]);
					}
				}
			}
			ans=0;
			for(int i=0;i<=100;i++)
			{
				for(int j=0;j<=100;j++)
				{
					ans=max(ans,g[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=0;j<=10;j++)
					for(int k=0;k<=10;k++)
						f[i][j][k]=-1e9;
			for(int i=1;i<=n;i++) cin>>a[i];
			f[1][a[1]][0]=0;
			f[1][0][a[1]]=0;
			for(int i=2;i<=n;i++)
			{
				for(int k=0;k<=10;k++)
				{
					f[i][a[i]][k]=max(f[i-1][a[i]][k]+a[i],f[i][a[i]][k]);
					for(int j=0;j<=10;j++)
					{
						f[i][a[i]][k]=max(f[i-1][j][k],f[i][a[i]][k]);
					}
				}
				for(int k=0;k<=10;k++)
				{
					f[i][k][a[i]]=max(f[i-1][k][a[i]]+a[i],f[i][k][a[i]]);
					for(int j=0;j<=10;j++)
					{
						f[i][k][a[i]]=max(f[i-1][k][j],f[i][k][a[i]]);
					}
				}
			}
			ans=0;
			for(int i=0;i<=10;i++)
			{
				for(int j=0;j<=10;j++)
				{
					ans=max(ans,f[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
	}
} 

