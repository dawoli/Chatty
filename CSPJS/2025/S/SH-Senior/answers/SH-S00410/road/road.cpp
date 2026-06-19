#include <bits/stdc++.h>
using namespace std;
const int m_max = 1e6+5,k_max = 10+5,n_max = 1e4+5;
//#define int long long
struct node {
	int v;
	long long w;
	bool operator<(const node & n) const {
		return w<n.w;
	}
};
struct node2 {
	int u,v;
	long long w;
	bool operator<(const node2 & n) const {
		return w<n.w;
	}
};
vector <node> g[m_max];
int n,m,k,fa[n_max];
long long c[k_max],edge[k_max][n_max],maxedge[m_max];
node2 e[m_max];
int pos;
priority_queue <node> q;
bool is_repaired[k_max];
int find(int i) {
	if(i==fa[i]) return i;
	return fa[i]=find(fa[i]);
}
void unionn(int i,int j) {
	fa[j] = i;
}
int dec = 0;
// void dfs(int i,vector <int> v) {
//     if(i == n+1) {
//         if(v.size() <= 1) return;
//         long long sum1,sum2=c[i];

//     }
// }
long long ans = 0;
void prim(int d,int m0){
	sort(e+1,e+m0+1);
	int sum = 0;
	ans = 0;
	for(int i=1; i<=n+k; ++i) fa[i] = i;
	for(int i=1; i<=m0&&sum<d-1; ++i) {
		int u = e[i].u, v = e[i].v;
		long long w = e[i].w;
//		 printf("edge {%d,%d}(%lld)\n",u,v,w);
		if(find(u) != find(v)) {
			unionn(u,v);
			++sum;
//			maxedge[u] = max(maxedge[u],w);
//			maxedge[v] = max(maxedge[v],w);
			ans += w;
//			 printf("added edge {%d,%d}(%lld)\n",u,v,w);
//			 printf("find(%d)%d ,find(%d)%d\n",u,find(u),v,find(v));
		} else {
//			 printf("skipped edge {%d,%d}(%lld)\n",u,v,w);
		}
	}
//	printf("prim()->ans:%d\n",ans);
}
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=m; ++i) {
		int u,v;
		long long w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		e[++pos] = {u,v,w};
	}
	for(int i=1; i<=k; ++i) {
		cin >> c[i];
		for(int j=1; j<=n; ++j) cin >> edge[i][j];
	}
	// printf("input done.n is %d m is %d k is %d\n",n,m,k);
	//use prim first:(?)
	prim(n,m);
	//ans is: no new city.
	//all [new]
	if(k == 0) {
		cout << ans << endl;
		return 0;
	}
	long long finalans = ans;
	//11101:1yes2no3yes4yes5yes
	for(int i=1;i<pow(2,k);++i) {
		int cost = 0,num = 0;
		for(int j = 1;j <= k;++j) {
			if(i & (int)(pow(2,j-1))) {
				for(int p=1;p<=n;++p) {
					e[++pos] = {p,n+j,edge[j][p]};
				}
				cost += c[j];
				++num;
			}
		}
		prim(n+num,m+num*n);
//		printf("%d:%d %d %d\n",i,finalans,ans,cost);
		finalans = min(finalans,ans+cost);
		pos = m;
	}
	// printf("process done.\n");
	cout << finalans << endl;
	// printf("output done.\n");
}
