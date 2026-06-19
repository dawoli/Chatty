#include <bits/stdc++.h>
#define N 10004
#define K 12
#define ll long long

using namespace std;

struct Edge {
	int v,w;
};

int n,m,k;
int c[K];
int a[K][N];
int s;
int w[N];
int plate;
ll ans= INT_MAX;


vector<Edge> g[N];

void init(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= m; ++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int i = 0; i < k; ++i){
		scanf("%d",&c[i]);
		if (c[i]==0){
			plate|=1<<i;
		}
		for (int j = 1; j <= n; ++j){
			scanf("%d",&a[i][j]);
		}
	}
}

int dis(int u,int v){
	int ret = INT_MAX;
	for (int i = 0; i < k; ++i){
		if(not ((s>>i)&1)) continue;
		ret = min(ret,a[i][u]+a[i][v]);
	}
	return ret;
}

ll cost(){
	ll ret = 0;
	for (int i = 0; i < k; ++i){
		if((s>>i)&1) ret+=c[i];
	}
	return ret;
}

void update(int v,int l){
	if (w[v]<=l) return;
	w[v]=l;
}

ll solve(){
	ll ret = cost();
	// printf("%lld\n",ret);
	memset(w,0x7f,sizeof w);
	w[1]=0;
	for (int cnt = 1; cnt <= n; ++cnt){
		int u = 0;
		for (int i = 1; i <= n; ++i){
			if (w[i] < w[u] and w[i]>= 0){
				u = i;
			}
		}

		// printf("%d %d\n",u,w[u]);

		ret+=w[u];
		w[u]=-1;

		for (auto e : g[u]) {
			w[e.v]=min(w[e.v],e.w);
		}
		for (int v = 1; v <= n; ++v){
			w[v]=min(w[v],dis(u,v));
		}
	}
	// printf("\n");

	return ret;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	init();
	for (s = 0; s < (1<<k); ++s){
		if ((s & plate) != plate)continue;
		// printf("f %d\n",plate);
		ans = min(ans,solve());
	}
	printf("%lld",ans);

}