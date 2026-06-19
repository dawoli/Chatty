#include<bits/stdc++.h>
using namespace std;

const int MAX=10000;
int ans=0,n,m,k,c[15],u[MAX+5],v[MAX+5],w[MAX+5],a[15][MAX+5],b[MAX+5][MAX+5];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	cin>>n>>m>>k;
	for(i=1; i<=m; i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		b[u[i]][v[i]]=w[i];
		b[v[i]][u[i]]=w[i];
	}
	for(i=1; i<=k; i++)
	{
		cin>>c[i];
		for(j=1; j<=n; j++)
		{
			cin>>a[i][j];
			if(b[i][j]==0)
			{
				b[i][j]=a[i][j];
				b[j][i]=a[i][j];
			}
			else
			{
				b[i][j]=min(a[i][j],b[i][j]);
				b[j][i]=min(a[i][j],b[j][i]);
			}
		}
	}
	for(i=1; i<=n-1; i++)
		for(j=i+1; j<=n; j++)
		{
			if(i!=j)
				ans+=b[i][j];
		}
	cout<<ans<<endl;
		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
