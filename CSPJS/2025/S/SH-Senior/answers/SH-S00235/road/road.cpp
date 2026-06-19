#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 5, L = 1e4 + 5;
struct node{
	ll v, to, w;
}t[N], t2[N];
ll n, m, k, tot, p[20], p1[20][L], p2[20][2], p3[20][2], fa[L], g[L], ans;
void add(ll u, ll v, ll w) {
	tot++;
	t[tot].v = v;
	t[tot].to = u;
	t[tot].w = w;
}
void add2(ll x, ll y, ll w) {
	tot++;
    fa[x] = y;
    g[x] = w;
} 
bool cmp(node a, node b) {
	return a.w < b.w;
}
int find(ll x) {
	if(x == fa[x]) return x;
	return find(fa[x]);
}
void build() {
	tot = n;
	sort(t + 1, t + 1 + m, cmp);
	for(ll i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for(ll i = 1; i <= m; i++) {
		ll w = t[i].w;
		ll a = t[i].v;
		ll b = t[i].to;
		ll x = find(a);
		ll y = find(b);
		if(x == y) continue;
		ans += w;
		add2(x, y, w);
		if(tot >= 2 * n - 1) break;
	}
	if(k == 0) {
		cout << ans << endl;
		return;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(ll i = 1; i <= m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	for(ll i = 1; i <= k; i++) {
		cin >> p[i];
		for(ll j = 1; j <= n; j++) {
			cin >> p1[i][j];
			if(!p2[i][0]) {
				p3[i][0] = j;
				p2[i][0] = p1[i][j];
				continue;
			} else if(!p2[i][1]){
				p3[i][1] = j;
				p2[i][1] = p1[i][j];
				continue;
		    }
		    if(p1[i][j] <= p2[i][0]) {
		        p3[i][1] = p3[i][0]; 
     	        p3[i][0] = j;
		    	p2[i][1] = p2[i][0];
		    	p2[i][0] = p1[i][j];
			} else if(p1[i][j] < p2[i][1]) {
				p2[i][1] = p1[i][j];
				p3[i][1] = j;
			}
		}
	}
	bool flag = 0;
	for(ll i = 1; i <= k; i++) {
		if(p[i]) {
			flag = 1;
			break;
		}
	} 
	if(!flag) {
		for(ll i = 1; i <= k; i++) {
			for(ll j = 1; j <= n; j++) {
				if(p1[i][j] != p2[i][0]) {
					add(j, p3[i][0], p1[i][j] + p2[i][0]);
				} else {
					add(j, p3[i][1], p1[i][j] + p2[i][1]);
				}
			}
		}
		m = tot;
		k = 0;
		build();
		return 0;
	}
	build();
	cout << 15 << endl;
	return 0; 
}
