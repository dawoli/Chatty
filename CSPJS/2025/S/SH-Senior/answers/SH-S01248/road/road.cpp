#include <bits/stdc++.h>

using namespace std;

int n,m,k;
long long a[10001][10001];
long long b[11][10001];
long long c[11];
long long develop[10001][10001];
bool dp[11];
bool ifin[10001];
long long ai,aj;
long long cost;

int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(dp,0,sizeof(dp));
	memset(develop,0,sizeof(develop));
	memset(ifin,0,sizeof(ifin));
	a[0][0] = 99999999999;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ai=0,aj=0;
	cost=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y] = z;
		a[y][x] = z;	
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=k;l++)
			if(i!=j)
			{
				if(a[i][j]==0)
				{
					a[i][j] = b[l][i]+b[l][j]+c[l];
					develop[i][j] = l;
					develop[j][i] = l;
				}
				if(a[i][j]>=b[l][i]+b[l][j]+c[l])
				{
					develop[i][j] = l;
					develop[j][i] = l;
				}
				a[i][j] = min(a[i][j],b[l][i]+b[l][j]+c[l]);
				a[j][i] = min(a[j][i],b[l][i]+b[l][j]+c[l]);
				
			}
		}
	}
	
	
	for(int i=1;i<=n-1;i++)
	{
		ai=0,aj=0;
		for(int j=1;j<=n;j++)
		{
			if(ifin[j]) continue;
			for(int l=1;l<=n;l++)
			{
				if(j!=l&&a[j][l]<=a[ai][aj])
				{
					ai = j;
					aj = l;
				}
			}
		}
		ifin[ai] = 1;
		ifin[aj] = 1;
		cost += a[ai][aj];

		if(develop[ai][aj]!=0&&!dp)
		{
			dp[develop[ai][aj]] = 1;
			for(int z=1;z<=n;z++)
			{
				for(int x=1;x<=n;x++)
				{
					if(z!=x)
					{
						if(ifin[z])
						{
							a[z][x] = min(a[z][x],b[develop[ai][aj]][x]);
							a[x][z] = min(a[x][z],b[develop[ai][aj]][x]);
						}
						else if(ifin[x])
						{
							a[z][x] = min(a[z][x],b[develop[ai][aj]][z]);
							a[x][z] = min(a[x][z],b[develop[ai][aj]][z]);
						}
						else
						{
							a[z][x] = min(a[z][x],b[develop[ai][aj]][z]+b[develop[ai][aj]][x]);
							a[x][z] = min(a[x][z],b[develop[ai][aj]][z]+b[develop[ai][aj]][x]);
						} 

					}
				}
			}
		}
	}
	
	cout<<cost;

	return 0;
}
