#include<bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
struct edge{
	int u;
	int v;
	int w;
};
edge adj1[2000005];
edge adj[2000005];
bool cmp(edge first,edge next)
{
	if(first.w<next.w)
	{
		return true;
	}
	return false;
}
int n,m,k,u,v,w,c[15],a[15][10015],fa[10015],numm,nummmm;
long long ans=100000000000000,ansn;
int find(int a)
{
	if(fa[a]==a)
	{
		return a; 
	}
	else
	{
		fa[a]=find(fa[a]);
		return fa[a];
	}
}
void se(int num,int sum)
{
	if(sum>=nummmm)
	{
		return;
	}
	if(find(adj1[num].u)==find(adj1[num].v))
	{
		se(num+1,sum);
	}
	else
	{
		ansn+=adj1[num].w; 
		fa[find(adj1[num].u)]=adj1[num].v;
		se(num+1,sum+1);
	}
}
int main()
{
	fin>>n>>m>>k;
//	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		fin>>u>>v>>w; 
//		cin>>u>>v>>w; 
		adj[i].u=u;
		adj[i].v=v;
		adj[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		fin>>c[i];
//		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			fin>>a[i][j];
//			cin>>a[i][j];
		}
	}
	int x=0;
	int maxx=1;
	for(int i=1;i<=k;i++)
	{
		maxx*=2;
	}
	while(x!=maxx)
	{
		numm=m;
		nummmm=n-1;
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
    	for(int i=1;i<=m;i++)
    	{
    		adj1[i].u=adj[i].u;
    		adj1[i].v=adj[i].v;
    		adj1[i].w=adj[i].w;
    	}
		ansn=0;
		int xx=x;
		for(int i=1;i<=k;i++)
		{
			if(xx%2==1)
			{
				nummmm++;
				ansn+=c[i];
				for(int j=1;j<=n;j++)
				{
					numm++;
					adj1[numm].u=i+n;
					adj1[numm].v=j;
					adj1[numm].w=a[i][j];
				}
			}
			xx/=2;
		}
		sort(adj1+1,adj1+numm+1,cmp);
		se(1,0);
		ans=min(ans,ansn);
		x++;
	}
	fout<<ans;
	cout<<ans;
} 
