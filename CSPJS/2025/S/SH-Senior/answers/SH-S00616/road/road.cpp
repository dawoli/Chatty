#include <bits/stdc++.h>
using namespace std;
const int maxn=1000008;
using ll=long long;
int n,m,k;
int a[maxn];
int a1[11][maxn];
int count[maxn];
int is[maxn];
struct Edge
{
	int v,w;
};
struct Edge1
{
	int u,v,w;
};
vector<Edge>e[maxn];
Edge1 ee[maxn];
bool vis[maxn];
bool cmp(Edge1 a,Edge1 b)
{
	return a.w<b.w;
}

struct node
{
	int to,dis;
	bool operator<(const node &other) const
	{
		return dis>other.dis;
	}
};
priority_queue<node>q;
int kruskal(int u1)
{
	ll ans=0;
	for(auto ed:e[u1])
	{
		int v=ed.v;
		int w=ed.w;
		q.push({v,w});
		//cout<<v<<" "<<w<<endl;
	}
	vis[u1]=true;
	int pp=0;
	while(!q.empty()&&pp<n-1)
	{
		node now=q.top();
		q.pop();
		int u=now.to;
		int l=now.dis;
		if(vis[u]) continue;
		vis[u]=true;
		ans+=l;
		pp++;
		for(auto ed:e[u])
	    {
		    int v=ed.v;
		    int w=ed.w;
		    //cout<<u<<" "<<v<<" "<<w<<endl;
		    for(auto ex:e[v])
		    {
		    	int vv=ex.v;
		    	q.push({v,vv});
			}
	    }
	}
	return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		ee[i].v=v;
		ee[i].u=u;
		ee[i].w=w;
	}
	if(k==0)
	{
		sort(ee+1,ee+m+1,cmp);
	    int mm=ee[1].u;
	    cout<<kruskal(mm)<<endl;
	    return 0;
	}
	int count1=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a1[i][j];
			if(a1[i][j]==0)
			{
				count1++;
				is[count1]=j;
			}
		}
	}
	for(int i=1;i<=count1;i++)
	{
		for(int q=1;q<=k;q++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				e[i].push_back({j,a1[q][j]});
		        e[j].push_back({i,a1[q][j]});
		        ee[q+n].v=j;
		        ee[q+n].u=i;
		        ee[q+n].w=a1[q][j];
			}
		}
	}
	sort(ee+k+1,ee+k+m+1,cmp);
	int mm=ee[1].u;
	cout<<kruskal(mm)<<endl;
	return 0;
}
