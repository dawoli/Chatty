#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge {
	int u,v;
	long long w;
	bool operator <(const Edge &temp)const {
		return w<temp.w;
	}
}a[20000100];
struct Town {
	int Cost;
	int w[10110];
}t[20];
int fa[10100];
int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int len;
void Kruskal() {
	sort(a+1,a+len+1);
	for(int i = 1;i <= n;i++) fa[i]=i;
	int ans = 0;
	for(int i = 1;i <= len;i++) {
		int fx = find(a[i].u);
		int fy = find(a[i].v);
		if(fx==fy) continue;
		ans += a[i].w;
		fa[fx]=fy;
	}
	printf("%lld",ans);
}
void make_Edge(int u,int v,long long w) {
	a[++len].u=u;
	a[len].v=v;
	a[len].w=w;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		make_Edge(u,v,w);
	}
	for(int i = 1;i <= k;i++) {
		scanf("%d",&t[i].Cost);
		for(int j = 1;j <= n;j++) scanf("%d",&t[i].w[j]);
	}
	for(int i = 1;i <= k;i++) {
		for(int j = 1;j <= n;j++) {
			for(int K = j+1;K <= n;K++) {
				make_Edge(j,K,t[i].w[j]+t[i].Cost+t[i].w[K]);
			}
		}
	}
	Kruskal();
	return 0;
}
