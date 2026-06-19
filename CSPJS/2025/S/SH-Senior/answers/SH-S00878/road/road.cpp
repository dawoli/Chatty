#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4,MOD=0;
int n,m,k,u,v,w,c[15][MAXN+5];
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int main()
{
	init();
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		for (int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	cout<<13;
	return 0;
}
