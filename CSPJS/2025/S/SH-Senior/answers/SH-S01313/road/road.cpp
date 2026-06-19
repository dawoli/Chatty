#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace FastIO {
	ll read() {
		ll x = 0, f = 1; char c = getchar();
		for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -1;
		for ( ; isdigit(c); c = getchar()) x = x*10 + c-'0';
		return x*f;
	}
	void print(ll x) {
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) print(x/10);
		putchar(x%10+'0');
	}
}

using namespace FastIO;
const int N = 1e4+1;
const int M = 1e6+1;
const int K = 6e7+1;
ll n,m,k;
ll fa[N];
ll c[11];
ll a[11][N];

ll find(ll x) {return fa[x] ? fa[x]=find(fa[x]) : x;}

struct edge {
	ll u,v,w;
	edge(ll U = 0, ll V = 0, ll W = 0) {u = U; v = V; w = W;}
	bool operator<(const edge& b) const {return w < b.w;}
}E[K];

void Solve1() {
	sort(E+1,E+m+1);
	ll ans = 0;
	for (ll i = 1; i <= m; i++) {
		ll u = E[i].u, v = E[i].v, w = E[i].w;
		ll x = find(u), y = find(v);
		if (x == y) continue;
		fa[x] = y;
		ans += w;
	}
	print(ans); putchar('\n');
}

void Solve2() {
	for (ll i = 1; i <= k; i++) {
		c[i] = read();
		for (ll j = 1; j <= n; j++) a[i][j] = read();
	}
	ll cnt = m;
	for (ll u = 1; u <= n; u++) for (ll v = u+1; v <= n; v++) {
		ll w = 9e18;
		for (ll i = 1; i <= k; i++) w = min(w,c[i]+a[i][u]+a[i][v]);
		E[++cnt] = edge(u,v,w);
	}

	sort(E+1,E+cnt+1);
	ll ans = 0;
	for (ll i = 1; i <= cnt; i++) {
		ll u = E[i].u, v = E[i].v, w = E[i].w;
		ll x = find(u), y = find(v);
		if (x == y) continue;
		fa[x] = y;
		ans += w;
	}
	print(ans), putchar('\n');
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n = read(); m = read(); k = read();
	for (ll i = 1; i <= m; i++) {
		ll u = read(), v = read(), w = read();
		E[i] = edge(u,v,w);
	}

	if (!k) {Solve1(); return 0;}
	Solve2();
	return 0;
}
