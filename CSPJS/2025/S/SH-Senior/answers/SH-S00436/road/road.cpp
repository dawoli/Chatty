#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
const int M = 2e6+9;
int n,m,k,tot,ans;
struct Edge{
	int u,v,w;
	bool operator<(const Edge&x)const{
		return w < x.w;
	}
}e[M];
int a[19][N],c[19],cz[19];
int fa[N];
inline void add(int u,int v,int w){
	e[++tot].u = u;
	e[tot].v = v;
	e[tot].w = w;
}
inline int find(int u){
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
void solve(){
	sort(e+1,e+1+tot);
	int cnt = 0;
	for (int i = 1;i <= n;i++) fa[i] = i;
	for (int i = 1;i <= m;i++){
		if (find(e[i].u) != find(e[i].v)){
			cnt++;
			ans += e[i].w;
			fa[find(e[i].u)] = e[i].v;
		}
		if (cnt >= n-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for (int i = 1;i <= k;i++){
		scanf("%d",&c[i]);
		for (int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
			if (c[i] == 0 && a[i][j] == 0) cz[i] = j;
		}
	}
	for (int i = 1;i <= k;i++){
		if (c[i] == 0){
			for (int j = 1;j <= n;j++){
				if (a[i][j] != 0) add(j,cz[i],a[i][j]);
			}
		}
	}
	solve();
	printf("%d\n",ans);
	return 0;
}
