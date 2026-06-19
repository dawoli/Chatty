#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 1, M = 1e6 + 1, K = 11;
ll n, m, k, fa[N], ans;
struct node{
	ll u, v, w;
}side[M];
struct node2{
	ll c, dis[N], to_0;
}vill[K];
bool cmp(node aa, node bb){
	return aa.w < bb.w;
}
ll find_fa(ll x){
	if (fa[x] == x){
		return x;
	}
	return fa[x] = find_fa(fa[x]);
}
bool pda(){
	for (ll i = 1;i <= k;i++){
		if (vill[i].c){
			return 0;
		}
		for (ll j = 1;j <= n;j++){
			if (!vill[i].dis[j]){
				vill[i].to_0 = j;
				break;
			}
		}
		
	}
	return 1;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1;i <= m;i++){
		cin >> side[i].u >> side[i].v >> side[i].w;
	}
	sort(side + 1, side + m + 1, cmp);
	for (ll i = 1;i <= k;i++){
		cin >> vill[i].c;
		for (ll j = 1;j <= n;j++){
			cin >> vill[i].dis[j];
		}
	}
	if (!k){
		for (ll i = 1;i <= n;i++){
			fa[i] = i;
		}
		for (ll i = 1;i <= m;i++){
			ll uu = side[i].u, vv = side[i].v, fu = find_fa(uu), fv = find_fa(vv);
			if (fu == fv){
				continue;
			}
			ans += side[i].w;
			fa[fu] = fv;
		}
		cout << ans;
	}else if (pda()){
		for (ll i = 1;i <= k;i++){
			ll t0 = vill[i].to_0;
			for (ll j = 1;j <= n;j++){
				side[m + (i - 1) * n + j] = {t0, j, vill[i].dis[j]};
			}
		}
		m += k * n;
		sort(side + 1, side + m + 1, cmp);
		for (ll i = 1;i <= n;i++){
			fa[i] = i;
		}
		for (ll i = 1;i <= m;i++){
			ll uu = side[i].u, vv = side[i].v, fu = find_fa(uu), fv = find_fa(vv);
			if (fu == fv){
				continue;
			}
			ans += side[i].w;
			fa[fu] = fv;
		}
		cout << ans;
	}
	return 0;
}
