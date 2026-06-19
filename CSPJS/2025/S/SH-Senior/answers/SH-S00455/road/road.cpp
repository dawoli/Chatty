#include <bits/stdc++.h>
#define il inline
#define N 2000010
using namespace std;
typedef long long ll;

il ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch != '-' && !(ch >= '0' && ch <= '9')) ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
	return x * f;
}
ll n, m, K, f[N], v[N];
struct EDGE {
	ll u, v, w, lim;
	bool operator < (const EDGE &p) const {
		return w < p.w;
	}
} E[N];
il ll find(ll x) {
	if (x == f[x]) return f[x];
	return f[x] = find(f[x]);
}
il ll _Kruskal() {
	ll Ans = 0;
	for (int i = 1; i <= n + K; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i) {
		ll u = E[i].u, v = E[i].v;
//		cout << u << " " << v << "\n";
		ll p =find(u), q = find(v);
		if (p == q) continue;
//		cout << "1\n";
		f[find(u)] = find(v);
		Ans += E[i].w;
	}
	return Ans;
}
il void solveK0() {
	for (int i = 1; i <= m; ++i) {
		E[i].u = read(); E[i].v = read();
		E[i].w = read();
	}
	sort(E + 1, E + m + 1);
	cout << _Kruskal();
}
il ll Kruskal(ll LIM, ll nowAns) {
	ll Ans = 0;
//	cout << LIM << "\n";
	for (int i = 1; i <= n + K; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i) {
		ll u = E[i].u, v = E[i].v;
		if (E[i].lim >= 0 && !((1 << E[i].lim) & LIM)) continue;
//		cout << u << " " << v << " " << E[i].lim << "\n";
		ll p =find(u), q = find(v);
		if (p == q) continue;
//		cout << "1\n";
		f[find(u)] = find(v);
		Ans += E[i].w;
		if(Ans > nowAns) break;
	}
//	cout << Ans << "\n";
	return Ans;
} 
il void solve() {
	for (int i = 1; i <= m; ++i) {
		E[i].u = read(); E[i].v = read();
		E[i].w = read(); E[i].lim = -1;
	}
	for (int i = 1; i <= K; ++i) {
		v[i] = read();
		for (int j = 1; j <= n; ++j) {
			ll w = read();
			E[++m] = (EDGE){n + i, j, w, i - 1};
		}
	}
	sort(E + 1, E + m + 1);
	ll Ans = (1ll << 55);
	for (int ptn = 0; ptn < (1 << K); ++ptn) {
		ll tmp = 0;
		for (int i = 0; i < K; ++i)
			if ((1 << i) & ptn) tmp += v[i + 1];
		Ans = min(Ans, tmp + Kruskal(ptn, Ans - tmp));
	}
	cout << Ans;
}
int main() {
//	double ST = clock();
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	n = read(); m = read(); K = read();
	if (K == 0) solveK0();
	else solve();
//	cerr << clock() - ST;
	return 0;
}

