#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1e4+5;
const int M=5e6+5;
int n,m,k;
struct Edge {
	int u,v;
	ll w;
	bool operator<(const Edge &e) const {return w<e.w;}
} e[M];
int Ecnt;
int f[N];
int find(int x) {
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
ll ans;
ll Kruskal() {
	for(int u=1;u<=n;u++) f[u]=u;
	sort(e+1,e+Ecnt+1);
	ll res=0,cnt=0;
	for(int i=1,fu,fv;i<=Ecnt;i++) {
		fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv) {
			f[fu]=fv;
			res+=e[i].w;
			if(++cnt==n-1) return res;
		}
	}
}
ll w[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++) {
		cin>>u>>v>>w;
		e[++Ecnt]={u,v,w};
	}
	for(int i=1,c;i<=k;i++) {
		cin>>c;
		for(int u=1;u<=n;u++) {
			cin>>w[u];
			for(int v=1;v<u;v++) e[++Ecnt]={u,v,w[u]+w[v]+c};
		}
	}
	ans=Kruskal();
	cout<<ans;
	return 0;
}
