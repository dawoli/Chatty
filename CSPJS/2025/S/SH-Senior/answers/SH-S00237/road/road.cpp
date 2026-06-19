#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
typedef long long ll;
const int N=10005,M=1000005,K=15;
int n,m,k,fa[N+K],c[K];
ll ans,all;
vector<int>nw,cur;
int read()
{
	int ans=0;
	char c=getchar();
	while(c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+c-'0',c=getchar();
	return ans;
}
struct node
{
	int u,v,w;
}edge[M+N*K];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
bool cmp2(int x,int y)
{
	return edge[x].w<edge[y].w;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u,ll cost,int len,vector<int>nw)
{
	if(u==k+1) return;
	dfs(u+1,cost,len,nw);
	cur.clear();
	cur.shrink_to_fit();
	for(int i=m+(u-1)*n+1;i<=m+u*n;i++) nw.pb(i);
	sort(nw.begin(),nw.end(),cmp2);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int ww=len;
	ll res=cost+c[u];
	for(auto s:nw)
	{
		int u=find(edge[s].u),v=find(edge[s].v),w=edge[s].w;
		if(u!=v)
		{
			fa[u]=v;
			res+=w;
			ww--;
			cur.pb(s);
			if(ww==0) break;
		}
	}
	nw.clear();
	nw.shrink_to_fit();
	ans=min(ans,res);
	dfs(u+1,cost+c[u],len+1,cur);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v),w=edge[i].w;
		if(u!=v) all+=w,fa[u]=v,nw.pb(i);
	}
	ans=all;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>edge[m+(i-1)*n+j].w;
			edge[m+(i-1)*n+j].u=j,edge[m+(i-1)*n+j].v=n+i;
		}
	}
	dfs(1,0,n,nw);
	cout<<ans;
	return 0;
}
