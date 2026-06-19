#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;

typedef long long ll;
typedef pair<int,int> pii;


struct node
{
	int u,v,w;
}edge[N];

int n,m,k,buildval;
int id[N];
int cntedge,cntdian;
vector<pii> g[N];
ll weight;

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int find(int t)
{
	if (id[t]==t)	return t;
	return id[t]=find(id[t]);
}

void kruskal()
{
	sort(edge+1,edge+cntedge+1,cmp);
	for (int i=1;i<=cntedge;i++)
	{
		int p=find(edge[i].u),q=find(edge[i].v);
		if (p!=q)
		{
			id[p]=q;
			weight+=edge[i].w;
		}	
		
	}
	
	cout<<weight<<endl;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cntdian=n+k;
	for (int i=1;i<=cntdian;i++)	id[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		++cntedge; 
		cin>>edge[cntedge].u>>edge[cntedge].v>>edge[cntedge].w;
	}
	if (k>0)
		cin>>buildval;
	for (int i=1;i<=k;i++)
	{
		cin>>edge[++cntedge].w;
		edge[cntedge].u=n+i;edge[cntedge].v=i;
	}
		
	kruskal();
	
	return 0;
}
