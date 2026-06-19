#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e4+9;
const ll M = 1e6+9+20*N;

ll n, m, k;
ll c[19], a[19][N];

struct edge{
	ll u, v, w;
}e[M];
bool cmp(const edge&a, const edge&b){
	return a.w<b.w;
}

bool c_0(){
	for(ll i=1; i<=k; i++)
		if(c[i]>0) return 0;
	return 1;
}
ll ans=0, id[N];
ll root(ll u){
	if(id[u]==u) return u;
	return id[u] = root(id[u]);
}
void solve1(){
	sort(e+1, e+m+1, cmp);
	for(ll i=1; i<=n; i++) id[i]=i;
	for(ll i=1; i<=m; i++){
		ll u=e[i].u, v=e[i].v, w=e[i].w;
	//	cout<<u<<' '<<v<<' '<<root(u)<<' '<<root(v)<<endl;
		if(root(u)==root(v)) continue;
		ans+=w;
		id[root(u)] = root(v);
	}
	cout<<ans;
}

void solve2(){
	for(ll i=1; i<=k; i++){
		ll j;
		for(j=1; j<=n; j++) if(a[i][j]==0) break;
		for(ll ww=1; ww<=n; ww++)
			e[++m] = (edge){j, ww, a[i][ww]};
	}
	solve1();
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin>>n>>m>>k;
	for(ll i=1; i<=m; i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(ll i=1; i<=k; i++){
		cin>>c[i];
		for(ll j=1; j<=n; j++)
			cin>>a[i][j];
	}
	
	if(k==0){
		solve1();
		return 0;
	}
	if(c_0()){
		solve2();
		return 0;
	}
	
	return 0;
}
