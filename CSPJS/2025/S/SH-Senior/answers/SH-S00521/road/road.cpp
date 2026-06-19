#include<bits/stdc++.h>
using namespace std;
int zx[10009]; //zuxian
int Val[11],lst[11][10009];
int n,m,k;
struct edge
{
	int a,b;
	int v;
};
bool cmp(edge a,edge b)
{
	return a.v<b.v;
}
int sr(int n) //finding root
{
	if(zx[n] == n) //root
	{
		return n;
	}
	else //father's root
	{
		int s = sr(zx[n]);
		zx[n]=s;
		return s;
	}
}
edge E[100009];//10000 edges
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) zx[i]=i;
	for(int i=1;i<=m;i++)
	{
		edge e;
		cin>>e.a>>e.b>>e.v;
		E[i]=e;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>Val[i];
		if(Val[i]!=0) return 0; //can't be solved
	    for(int j=1;j<=n;j++) cin>>lst[i][j];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			E[m+(i-1)*k+j].a = j;
			E[m+(i-1)*k+j].b = n+i;
			E[m+(i-1)*k+j].v = lst[i][j];
		}
	}
	m+=n*k; //xunibian
	sort(E+1,E+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	{
//		cout<<E[i].a<<" "<<E[i].b<<" "<<E[i].v<<endl;
//	}
	int cur=1;
	int cost=0;
	for(int i=1;i<n+k;i++)
	{
		//Dij
		edge e=E[cur];
		int x=sr(e.a),y=sr(e.b);
		while(x==y)
		{
			cur++;
			e=E[cur];
			x=sr(e.a),y=sr(e.b);
		}
		zx[y] = x;
		cost+=e.v;
		cur++;
	}
	cout<<cost;
	return 0;
}
