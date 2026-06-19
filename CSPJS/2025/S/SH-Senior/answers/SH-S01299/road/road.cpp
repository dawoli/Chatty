#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10009,M=1000009;
int fa[N],n,m,k,ans=0x3f3f3f3f,choose[15],c[15],a[15][N];
struct Edge{
	int u,v,w;
	bool operator < (const Edge&x) const {
		return w<x.w;
	}
}e[M+10*N],e1[M+10*N];
inline int find(int u) {
	if(fa[u] != u) {
		return fa[u]=find(fa[u]);
	}return u;
}
void kruskal(int ans1) {
	for(int i=1;i<=n;i++) {
		fa[i]=i;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++) {
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv) {
			fa[fu]=fv;
			ans1+=e[i].w;
		}
	}
	ans=min(ans,ans1);
}
void dfs(int x) {
	if(x==k+1) {
		int nn=n,mm=m,ans1=0;
		for(int i=1;i<=k;i++){
			if(choose[i]) {
				n++;
				for(int j=1;j<=nn;j++) {
					e[++m].u=n;
					e[m].v=j;
					e[m].w=a[i][j];
				}
				ans1+=c[i];
			}
		}
		kruskal(ans1);
		m=mm;
		n=nn;
		for(int i=1;i<=m;i++) {
			e[i].u=e1[i].u;
			e[i].v=e1[i].v;
			e[i].w=e1[i].w;
		}
		return ;
	}
	choose[x]=1;
	dfs(x+1);
	choose[x]=0;
	dfs(x+1);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
		e1[i].u=e[i].u;
		e1[i].v=e[i].v;
		e1[i].w=e[i].w;
	}
	if(k==0) {
		kruskal(0);
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
