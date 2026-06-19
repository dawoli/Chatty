#include<bits/stdc++.h>
#define to first
#define vl second
using namespace std;
int n,m,k;
bool is0=true;
vector<pair<int,int>> e;
int c[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	e.resize((k+1)*(n+k+1),vector<pair<int,int>>(0));
	memset(c,-1,sizeof(c));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		for(int j=0;j<=k;j++)
		{
			e[u+j*k].push_back({v,w});
			e[v+j*k].push_back({u,w});
		}
	}
	for(int i=1;i<=k;i++)
	{
		int a;
		cin>>c[i];
		for(int i=1;i<=n;i++)
		{
			int w;
			cin>>w;
			
		}
	}
}//unfinished,I can finish it after the contest
//at SH SFLS 7D
//edited by Vim
