#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10011]={0},d[11]={0},ma,inf=2047*1024*1024,way[11][10011]={0};
struct road
{
	int u;
	int v;
	int cost;
}road[1000011];
int init(int x)
{
	for(int i=1;i<=x;i++)
		fa[i]=i;
}
int fi(int x)
{
	if(fa[x]==x)
		return x;
	else
		return fi(fa[fa[x]]);
}
int un(int x,int y)
{
	fa[fi(x)]=fi(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n);
	for(int i=0;i<=1000010;i++)
		road[i].cost=inf;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		road[i].u=a;
		road[i].v=b;
		road[i].cost=c;
	}
	for(int j=1;j<=k;j++)
	{
		cin>>d[j];
		for(int l=1;l<=n;l++)
			cin>>way[j][l];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			ma=inf;
			int fl=0;
			for(int l=1;l<=k;l++)
			{
				if(way[l][i]+way[l][j+i]<=ma)
				{
					fl=l;
					ma=way[l][i]+way[l][j+i];
				}
			}
			road[m+i*j-1].cost=ma;
			road[m+i*j-1].u=i;
			road[m+i*j-1].v=j+i;
		}
	}
	for(int i=0;i<m-1+n*n*(k/(k-1));i++)
		for(int j=i+1;j<m+n*n*(k/(k-1));j++)
		{
			if(road[i].cost>road[j].cost)
			{
				swap(road[i].cost,road[j].cost);
				swap(road[i].u,road[j].u);
				swap(road[i].v,road[j].v);
			}
		}
	int t=0,ans=0;
	for(int i=0;i<n-1;i++)
	{
		while(fi(road[t].u)==fi(road[t].v))
		{
			if(t>=m-1 || fi(road[t].u)!=fi(road[t].v))
				break;
			t++;
		}
		un(road[t].u,road[t].v);
		ans+=road[t].cost;
		t++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
