#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int n,m,tt,s,e,f[301][301];
pair<int,int> p[40001];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P2888_5.in","r",stdin);
	freopen("P2888_5.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>tt;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j)f[i][j]=0;
			else f[i][j]=INF;
		}
	}
	for (int i=1;i<=m;i++)
		cin>>s>>e>>f[s][e];
	for (int i=1;i<=tt;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
				/*
				 *if(max(f[i][k],f[k][j])>f[i][j])
				 *{
				 *	f[i][j]=max(f[i][k],f[k][j]);
				 *}
				 *这样会WA
				 */
			}
	for (int i=1;i<=tt;i++)
	{
		s=p[i].first;
		e=p[i].second;
		if (f[s][e]==INF)cout<<-1<<'\n';
		else cout<<f[s][e]<<'\n';
	}
	return 0;
}