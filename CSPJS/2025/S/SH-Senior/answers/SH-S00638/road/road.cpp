#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5,M = 1e6 + 5;
ll n,m,k,c[3][N],f[N];
struct node {
	ll to,num;
};
struct node2 {
	ll a,b,nm;
} tmp[M];
vector <node> e[N];
void input() {
	cin>>n>>m>>k;
	for(ll i = 1;i <= m;i++) {
		ll u,v,w; cin>>u>>v>>w; e[u].push_back({v,w}); e[v].push_back({u,w});
		tmp[i] = {u,v,w};
	}
	for(ll i = 1;i <= k;i++) {
		cin>>c[i][0];
		for(ll j = 1;j <= n;j++) cin>>c[i][j];
	}
}
ll find(ll x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
bool cmp(node2 x,node2 y) {
	return x.nm < y.nm;
}
void solve1() {
	for(ll i = 1;i <= n;i++) f[i] = i;
	sort(tmp + 1,tmp + m + 1,cmp);
	ll ans = 0;
	for(ll i = 1;i <= m;i++) {
		ll fx = find(tmp[i].a),fy = find(tmp[i].b);
		if(fx == fy) continue;
		f[fx] = fy; ans += tmp[i].nm;
	}
	cout<<ans<<'\n';
}
void solve() {
	for(ll i = 1;i <= n;i++) f[i] = i;
	sort(tmp + 1,tmp + m + 1,cmp);
	ll ans = 0;
	for(ll i = 1;i <= m;i++) {
		ll fx = find(tmp[i].a),fy = find(tmp[i].b);
		if(fx == fy) continue;
		f[fx] = fy; ans += tmp[i].nm;
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	if(k == 0) solve1();
	else solve();
	return 0;
} 
