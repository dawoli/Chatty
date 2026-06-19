#include <bits/stdc++.h>
using namespace std;

typedef int ll;
ll T, n, k, Q;
vector<ll> s[100009];
vector<pair<ll,ll>> occus[200009];
bool ok[109][200009];
ll ban[109][200009];
struct query{ll id, r, c;} q[100009];

void read(ll& x) {
	ll s = 0, w = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') w = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9') {
		s = s*10+(c-'0');
		c = getchar();
	}
	x = s*w;
}

struct segment{ll l, r;bool brush;};
vector<segment> tr[100009];

void init(ll p) {
	tr[p] = vector<segment>(s[p].size()*4+1);
}

void build(ll p, ll u, ll l, ll r) {
	tr[p][u].l = l; tr[p][u].r = r; tr[p][u].brush = false;
	if(l == r) return;
	ll mid = (l+r)>>1;
	build(p, u<<1, l, mid); build(p, u<<1|1, mid+1, r);
}

void brush(ll p, ll u, ll l, ll r) {
	if(tr[p][u].brush) return;
	if(l <= tr[p][u].l && tr[p][u].r <= r) {
		tr[p][u].brush = true;
		return;
	}
	if(r < tr[p][u].l || tr[p][u].r < l) return;
	brush(p, u<<1, l, r); brush(p, u<<1|1, l, r);
	if(tr[p][u<<1].brush && tr[p][u<<1|1].brush) tr[p][u].brush = true;
}

ll nxt(ll p, ll u, ll pos) {
	if(tr[p][u].brush) return tr[p][u].r+1;
	if(tr[p][u].l == tr[p][u].r) return tr[p][u].l;
	if(tr[p][u<<1].r < pos || tr[p][u<<1].brush) return nxt(p, u<<1|1, pos);
	return nxt(p, u<<1, pos);
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	read(T);
	while(T--) {
		read(n); read(k); read(Q);
		for(ll i = 0; i < 200009; i++) occus[i].clear();
		for(ll i = 1; i <= n; i++) {
			ll l;
			read(l);
			s[i].clear();
			for(ll j = 1; j <= l; j++) {
				ll x;
				read(x);
				s[i].push_back(x);
				if(j != l) occus[x].push_back(make_pair(i, j-1));
			}
		}
		memset(ok, 0, sizeof(ok));
		memset(ban, 0, sizeof(ban));
		ok[0][1] = true;
		ll ptr = 0;
		vector<ll> ss[2];
		ss[ptr].push_back(1);
		for(ll i = 1; i <= n; i++) init(i);
		for(ll m = 0; m < 100; m++) {
			for(ll i = 1; i <= n; i++) build(i, 1, 1, s[i].size());
			while(!ss[ptr].empty()) {
				ll u = ss[ptr].back();
				ss[ptr].pop_back();
				ll ci = 0, j = 0;
				for(pair<ll,ll> t:occus[u]) {
					ll i = t.first, x = t.second;
					if(i == ban[m][u]) continue;
					ll j = nxt(i, 1, x+2)-1;
					ll jo = j;
					for(; j < x+k && j < s[i].size(); j++) {
						if(!ok[m+1][s[i][j]]) ban[m+1][s[i][j]] = i, ss[ptr^1].push_back(s[i][j]);
						else if(ban[m+1][s[i][j]] != i) ban[m+1][s[i][j]] = 0;
						ok[m+1][s[i][j]] = true;
					}
					// cout << jo+1 << ' ' << j << endl;
					brush(i, 1, jo+1, j);
				}
			}
			ptr ^= 1;
		}
		// queue<pair<ll,ll>> q;
		// q.push(make_pair(0, 1));
		// while(!q.empty()) {
		// 	pair<ll,ll> u = q.front();
		// 	q.pop();
		// 	if(u.first == 100) continue;
		// 	for(ll i = 1; i <= n; i++) {
		// 		if(i == ban[u.first][u.second]) continue;
		// 		ll j = 0;
		// 		for(ll x:occus[u.second][i]) {
		// 			for(j = max(j, x+1); j < x+k && j < s[i].size(); j++) {
		// 				if(!ok[u.first+1][s[i][j]]) ban[u.first+1][s[i][j]] = i, q.push(make_pair(u.first+1, s[i][j]));
		// 				else if(ban[u.first+1][s[i][j]] != i) ban[u.first+1][s[i][j]] = 0;
		// 				ok[u.first+1][s[i][j]] = true;
		// 			}
		// 		}
		// 	}
		// }
		while(Q--) {
			ll r, c;
			read(r); read(c);
			puts(ok[r][c]?"1":"0");
		}
	}
	return 0;
}

