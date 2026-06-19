#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10,K=1e4+10;
struct Edge{int u,v,w;} g[N];
int n,m,k,c[20],a[20][K],fa[N];
long long ans=0x3f3f3f3f3f3f3f3f;
vector<Edge> eg,egs;
bool cmp(const Edge &a,const Edge &b) {
	return a.w<b.w;
}
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int u,int v) {
	u=find(u),v=find(v);
	if (u==v) return false;
	fa[v]=u;
	return true;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=m; i++)
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	for (int i=1; i<=k; i++) {
		scanf("%d",c+i);
		for (int j=1; j<=n; j++)
			scanf("%d",a[i]+j);
	}
	for (int i=1; i<=n; i++) fa[i]=i;
	sort(g+1,g+m+1,cmp);
	for (int i=1,ct=0; i<=m; i++) {
		if (!merge(g[i].u,g[i].v)) continue;
		eg.push_back(g[i]),ct++;
		if (ct==n-1) break;
	}
	for (int ks=0; ks<(1<<k); ks++) {
		long long sec=0;egs=eg;
		for (int i=0; i<k; i++) {
			if ((ks>>i)&1^1) continue;
			sec+=c[i+1];
			for (int j=1; j<=n; j++)
				egs.push_back({n+i+1,j,a[i+1][j]});
		}
		for (int i=1; i<=n+k; i++) fa[i]=i;
		sort(egs.begin(),egs.end(),cmp);
		for (int i=0,ct=0; i<egs.size(); i++) {
			if (!merge(egs[i].u,egs[i].v)) continue;
			ct++,sec+=egs[i].w;
			if (ct==n+__builtin_popcount(ks)-1) break;
		}
		ans=min(ans,sec);
	}
	printf("%lld",ans);
	return 0;
}
