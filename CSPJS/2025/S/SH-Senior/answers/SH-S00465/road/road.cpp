#include<bits/stdc++.h>
using namespace std;
#define N 10015
int fa[N],siz[N],c[N];
bool bt[15];
int n,m,k;
struct Edge
{
	int u,v,w;
	bool operator<(Edge b)
	{
		return w<b.w;
	}
	void show()
	{
		cout<<u<<' '<<v<<' '<<w<<'\n';
	}
};
vector<Edge> edge;
void init()
{
	for(int i=1;i<=n+k;++i)
		fa[i]=i,siz[i]=1;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(siz[x]<siz[y]) swap(x,y);
	siz[x]+=siz[y];
	fa[y]=x;
}
int pct(int x)
{
	int res=0;
	for(int i=1;i<=k;++i)
	{
		res+=x&1;
		bt[i]=x&1;
		x>>=1;
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		edge.push_back(Edge{u,v,w});
	}
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			cin>>w;
			edge.push_back(Edge{n+i,j,w});
		}
	}
	sort(edge.begin(),edge.end());
//	for(Edge e:edge) e.show();
	long long mn=1e18;
	for(int i=0;i<(1<<k);++i)
	{
		init();
		int flg=-pct(i)+1;
		long long ans=0;
		for(int j=1;j<=k;++j) if(bt[j]) ans+=c[j];
		for(Edge e:edge)
		{
			int u=e.u,v=e.v;
//			cout<<u<<' '<<v<<' ';
			if(u>n&&bt[u-n]==0) continue;
			if(v>n&&bt[v-n]==0) continue;
			if(find(u)==find(v)) continue;
			merge(u,v);
			ans+=e.w;
//			cout<<'\n';
			if(++flg>=n) break;
		}
//		cout<<ans<<' ';
		mn=min(mn,ans);
	}
	cout<<mn;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

