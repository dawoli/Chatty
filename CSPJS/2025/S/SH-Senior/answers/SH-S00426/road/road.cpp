#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using i64=long long;
const int N=1e4+5;
int n,m,k;
struct Edge
{
	int u,v,w;
};
vector<Edge> edge;
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int c[15],a[15][N];
int fa[5*N];
int find(int x)
{
	if (fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
	int rootx=find(x),rooty=find(y);
	if (rootx!=rooty)
	{
		fa[rootx]=rooty;
	}
}
i64 Kruskal() //最小生成树 
{
	sort(edge.begin(),edge.end(),cmp);
	i64 sum=0;
	for (auto cur:edge)
	{
		int u=cur.u,v=cur.v,w=cur.w;
		if (find(u)!=find(v))
		{
			unite(u,v);
			sum+=w;
		}
	}
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back({u,v,w});
		edge.push_back({v,u,w});
	}
	bool flag=1;
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		if (c[i])	flag=0;
	}
	for (int i=1;i<=n*2;i++)	fa[i]=i;
	if (k==0) //最小生成树 
	{
		cout<<Kruskal()<<"\n";
	}else if (flag)
	{
		for (int i=n+1;i<=n+k;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (a[i-n][j]==0)
				{
					edge.push_back({i,j,0});
					edge.push_back({j,i,0});
				}
			}
		}
		cout<<Kruskal()<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

