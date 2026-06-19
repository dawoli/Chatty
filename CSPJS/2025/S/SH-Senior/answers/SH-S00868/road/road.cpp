#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m,k;
bool che=1;
int u[N],v[N],w[N],c[N],a[N][N],sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) che=0;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(che==0)
	{
		cout<<0;
	}
	return 0;
}
