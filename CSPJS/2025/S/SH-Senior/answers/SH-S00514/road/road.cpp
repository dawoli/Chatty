#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5,M = 1e6+5;
int n,m,k;
struct DSU{
	int fa[N<<1];
	void init(){
		for(int i = 1;i<=n+50;i++) fa[i] = i;
	}
	int find(int x){
		return fa[x] == x?x:fa[x] = find(fa[x]);
	}
	void merge(int x,int y){
		fa[find(x)] = find(y);
	}
}dsu;
struct edge{
	int u,v;ll w;
}a[M],b[M];
int cnt = 0;
ll c[20];
ll d[20][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;i++){
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		a[i] = {u,v,w};
	}
	for(int i = 1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j<=n;j++){
			scanf("%lld",&d[i][j]);
		}
	}
	sort(a+1,a+m+1,[](edge x,edge y){
		return x.w < y.w;
	});
	int num = 1;
	dsu.init();
	for(int i = 1;i<=m;i++){
		if(num >= n) break;
		if(dsu.find(a[i].u) == dsu.find(a[i].v)) continue;
		dsu.merge(a[i].u,a[i].v);
		num++;
		b[++cnt] = a[i];
	}
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n;j++){
			b[++cnt] = {n+i,j,d[i][j]};
		}
	}
	sort(b+1,b+cnt+1,[](edge x,edge y){
		return x.w < y.w;
	});
	ll ans = 1e18;
	for(int x = 0;x<(1<<k);x++){
		dsu.init();
		ll res = 0;num=1;
		for(int i = 1;i<=cnt;i++){
			if(num >= n+__builtin_popcount(x)) break;
			if(dsu.find(b[i].u) == dsu.find(b[i].v)) continue;
			else if(b[i].u > n && !(x & (1<<((b[i].u-n)-1)))) continue;
			dsu.merge(b[i].u,b[i].v);
			num++;
			res += b[i].w;
		}
		for(int i = 0;i<k;i++){
			if(x&(1<<i)) res += c[i+1];
		}
		ans = min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
