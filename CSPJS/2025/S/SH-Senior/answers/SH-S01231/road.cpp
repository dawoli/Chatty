#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	ll u, v, w;
	ll bel;
} a[1000100], b[200100];

ll n, m, p, tot, ans;
ll f[100100];
ll c[100100];

bool cmp(node x, node y) {
	return x.w < y.w;
}

ll find(ll x) {
	if (f[x] == x) {
		return x;
	} else {
		return f[x] = find(f[x]);
	}
}

inline int read() {
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=read();
	m=read();
	p=read();
	for (ll i = 1; i <= m; i++) {
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		a[i].bel = 0;
	}
	sort(a + 1, a + m + 1, cmp);
	for (ll i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (ll i = 1; i <= m; i++) {
		ll u = find(a[i].u);
		ll v = find(a[i].v);
		if (u == v) {
			continue;
		}
		f[u] = v;
		b[++tot] = a[i];
		ans += a[i].w;
	}
	for (ll i = 1; i <= p; i++) {
		c[i]=read();
		for (ll j = 1; j <= n; j++) {
			tot++;
			b[tot].bel = i;
			b[tot].u = n + i;
			b[tot].v = j;
			b[tot].w=read();
		}
	}
	sort(b + 1, b + tot + 1, cmp);
	for (ll o = 1; o < (1 << p); o++) {
		ll sum = 0;
		for (ll i = 1; i <= n + p; i++) {
			f[i] = i;
		}
		for (ll j = 1; j <= tot; j++) {
			if (b[j].bel && !(o & (1 << (b[j].bel - 1)))) {
				continue;
			}
			ll u = find(b[j].u);
			ll v = find(b[j].v);
			if (u == v) {
				continue;
			}
			sum += b[j].w;
			f[u] = v;
		}
		for (ll i = 0; i < p; i++) {
			if (o & (1 << i)) {
				sum += c[i + 1];
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
} 
