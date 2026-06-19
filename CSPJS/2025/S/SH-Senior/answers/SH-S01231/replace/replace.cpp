#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct nod {
	ll idx1;
	ll idx2;
} O;

struct Node {
	ll idx;
	ll dfn1;
	ll dfn2;
} o;

struct op {
	ll pos;
	ll L;
	ll R;
	ll x;
} d[1000100];

ll n, q, s1, s2, len1, len2, tr1_tot, num_tot, tr2_tot, dfn_tot, mx, op_tot;
ll ans[200100];
int tr1[5000100][28];
int tr2[6000100][28];
int cnt[6000100];
int dfn[6000100];
int st[6000100];
int ed[6000100];
int num[5000100];
int rt1[200100];
int rt2[200100];
char c1[5000100];
char c2[5000100];
vector<nod> V[200100];
vector<Node> g[200100];

inline void add(ll x, ll y) {
	for (ll i = x; i <= mx; i += (i & -i)) {
		cnt[i] += y;
	}
	return;
}

inline ll qry(ll x) {
	ll ss = 0;
	for (ll i = x; i; i -= (i & -i)) {
		ss += cnt[i];
	}
	return ss;
}

inline void ins(ll bel) {
	ll rt = rt1[bel];
	for (ll i = s1; i >= 1; i--) {
		ll x = c1[i] - 'a';
		if (!tr2[rt][x]) {
			tr2[rt][x] = ++tr2_tot;
		}
		rt = tr2[rt][x];
	}
	O.idx1 = rt;
	rt = rt2[bel];
	for (ll i = s2; i <= len1; i++) {
		ll x = c1[i] - 'a';
		if (!tr2[rt][x]) {
			tr2[rt][x] = ++tr2_tot;
		}
		rt = tr2[rt][x];
	}
	O.idx2 = rt;
	V[bel].emplace_back(O);
	return;
}

void dfs(ll x) {
	dfn[x] = ++dfn_tot;
	st[x] = dfn[x];
	for (ll i = 0; i < 26; i++) {
		if (tr2[x][i]) {
			dfs(tr2[x][i]);
		}
	}
	ed[x] = dfn_tot;
	return;
}

bool cmp(op x, op y) {
	return x.pos < y.pos || x.pos == y.pos && !y.x;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%lld%ld", &n, &q);
	tr2_tot = n + n;
	for (ll i = 1; i <= n; i++) {
		scanf("%s%s", c1 + 1, c2 + 1);
		len1 = strlen(c1 + 1);
		s1 = 0;
		while (s1 < len1 && c1[s1 + 1] == c2[s1 + 1]) {
			s1++;
		}
		if (s1 == len1) {
			continue;
		}
		s2 = len1 + 1;
		while (s2 > 1 && c1[s2 - 1] == c2[s2 - 1]) {
			s2--;
		}
		ll rt = 0;
		for (ll j = s1 + 1; j < s2; j++) {
			ll x = c1[j] - 'a';
			if (!tr1[rt][x]) {
				tr1[rt][x] = ++tr1_tot;
			}
			rt = tr1[rt][x];
		}
		for (ll j = s1 + 1; j < s2; j++) {
			ll x = c2[j] - 'a';
			if (!tr1[rt][x]) {
				tr1[rt][x] = ++tr1_tot;
			}
			rt = tr1[rt][x];
		}
		if (!num[rt]) {
			num[rt] = ++num_tot;
			rt1[num_tot] = num_tot * 2 - 1;
			rt2[num_tot] = num_tot * 2;
		}
		ins(num[rt]);
	}
	for (ll i = 1; i <= num_tot; i++) {
		dfn_tot = 0;
		dfs(rt1[i]);
		dfn_tot = 0;
		dfs(rt2[i]);
	}
	for (ll i = 1; i <= q; i++) {
		scanf("%s%s", c1 + 1, c2 + 1);
		len1 = strlen(c1 + 1);
		len2 = strlen(c2 + 1);
		if (len1 != len2) {
			ans[i] = 0;
			continue;
		}
		s1 = 0;
		while (s1 < len1 && c1[s1 + 1] == c2[s1 + 1]) {
			s1++;
		}
		if (s1 == len1) {
			ans[i] = 0;
			continue; 
		}
		s2 = len1 + 1;
		while (s2 > 1 && c1[s2 - 1] == c2[s2 - 1]) {
			s2--;
		}
		ll rt = 0;
		for (ll j = s1 + 1; j < s2; j++) {
			ll x = c1[j] - 'a';
			if (!tr1[rt][x]) {
				rt = -1;
				break;
			}
			rt = tr1[rt][x];
		}
		if (rt == -1) {
			ans[i] = 0;
			continue;
		}
		for (ll j = s1 + 1; j < s2; j++) {
			ll x = c2[j] - 'a';
			if (!tr1[rt][x]) {
				rt = -1;
				break;
			}
			rt = tr1[rt][x];
		}
		if (rt == -1) {
			ans[i] = 0;
			continue;
		}
		if (!num[rt]) {
			continue;
		}
		ll bel = num[rt];
		o.idx = i;
		rt = rt1[bel];
		for (ll j = s1; j >= 1; j--) {
			ll x = c1[j] - 'a';
			if (!tr2[rt][x]) {
				break;
			}
			rt = tr2[rt][x];
		}
		o.dfn1 = dfn[rt];
		rt = rt2[bel];
		for (ll j = s2; j <= len1; j++) {
			ll x = c1[j] - 'a';
			if (!tr2[rt][x]) {
				break;
			}
			rt = tr2[rt][x];
		}
		o.dfn2 = dfn[rt];
		g[bel].emplace_back(o);
	}
	for (ll idx = 1; idx <= num_tot; idx++) {
		if (g[idx].empty()) {
			continue;
		}
		op_tot = 0;
		mx = ed[rt2[idx]];
		for (ll i = 0; i < V[idx].size(); i++) {
			op_tot++;
			d[op_tot].pos = st[V[idx][i].idx1];
			d[op_tot].L = st[V[idx][i].idx2];
			d[op_tot].R = ed[V[idx][i].idx2];
			d[op_tot].x = 1;
			op_tot++;
			d[op_tot].pos = ed[V[idx][i].idx1] + 1;
			d[op_tot].L = st[V[idx][i].idx2];
			d[op_tot].R = ed[V[idx][i].idx2];
			d[op_tot].x = -1;
		}
		for (ll i = 0; i < g[idx].size(); i++) {
			op_tot++;
			d[op_tot].pos = g[idx][i].dfn1;
			d[op_tot].L = g[idx][i].dfn2;
			d[op_tot].R = g[idx][i].idx;
			d[op_tot].x = 0;
		}
		sort(d + 1, d + op_tot + 1, cmp);
		for (ll i = 1; i <= op_tot; i++) {
			if (!d[i].x) {
				ans[d[i].R] = qry(d[i].L);
			} else {
				add(d[i].L, d[i].x);
				add(d[i].R + 1, -d[i].x);
			}
		}
		for (ll i = 1; i <= mx; i++) {
			cnt[i] = 0;
		}
	}
	for (ll i = 1; i <= q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
} 
