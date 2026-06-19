#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define SZ(v) (int)((v).size())
#define allc(v) (v).begin(), (v).end()
#define popc(x) __builtin_popcount((x))
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
template <typename A, typename B>
void chkmax(A &x, B y) {
	x = (x > y) ? x : y;
}
template <typename A, typename B>
void chkmin(A &x, B y) {
	x = (x < y) ? x : y;
}
bool Meb;
namespace lyl {
	const int V = 1e7 + 5;
	const int N = 4e5 + 5;
	const ll mod1 = 1e9 + 7;
	const ll mod2 = 998244353;
	const ll P1 = 1331;
	const ll P2 = 2333;
	int tr[V][26];
	int tot;
	vector<int> vec[V];
	void clear() {
		FOR (i, 1, tot) {
			FOR (j, 0, 25) tr[i][j] = 0;
			vec[i].clear();
		}
		tot = 2;
	}
	int insert(int rt, string s) {
		int cur = rt;
		FOR (i, 0, SZ(s) - 1) {
			if (!tr[cur][s[i] - 'a']) {
				tr[cur][s[i] - 'a'] = ++tot;
				vec[cur].PB(tot);
			}
			cur = tr[cur][s[i] - 'a'];
		}
		return cur;
	}
	int n, q, id[N], p1[N], p2[N], pos1[N], pos2[N], ans[N], h1[N], h2[N];
	string s1[N], s2[N], t1[N], t2[N];
	bool cmp(int x, int y) {
		if (h1[x] != h1[y]) return h1[x] < h1[y];
		return h2[x] < h2[y];
	}
	struct fenwick {
		int tr[V], lim;
		void clear(int nwlim) {
			FOR (i, 1, lim) tr[i] = 0;
			lim = nwlim;
		}
		void upd(int x, int k) {
			while (x <= lim) {
				tr[x] += k;
				x += x & -x;
			}
		}
		int qry(int x) {
			int res = 0;
			while (x) {
				res += tr[x];
				x -= x & -x;
			}
			return res;
		}
	} fen;
	int L[V], R[V], timer;
	void dfs(int u) {
		L[u] = ++timer;
		for (int v: vec[u]) {
			dfs(v);
		}
		R[u] = timer;
	}
	vector<PII> ins[V], qry[V];
	void solve() {
		cin >> n >> q;
		FOR (i, 1, n) {
			cin >> s1[i] >> s2[i];
			s1[i] = " " + s1[i], s2[i] = " " + s2[i];
			FOR (j, 1, SZ(s1[i]) - 1) {
				if (s1[i][j] != s2[i][j]) {
					if (!p1[i]) p1[i] = j;
					p2[i] = j;
				}
			}
			FOR (j, p1[i], p2[i]) {
				h1[i] = (1ll * h1[i] * P1 + s1[i][j]) % mod1;	
				h2[i] = (1ll * h2[i] * P2 + s1[i][j]) % mod2;	
			}
			FOR (j, p1[i], p2[i]) {
				h1[i] = (1ll * h1[i] * P1 + s2[i][j]) % mod1;	
				h2[i] = (1ll * h2[i] * P2 + s2[i][j]) % mod2;	
			}
		}
		FOR (i, 1, q) {
			cin >> t1[i] >> t2[i];
			if (SZ(t1[i]) != SZ(t2[i])) continue;
			t1[i] = " " + t1[i], t2[i] = " " + t2[i];
			FOR (j, 1, SZ(t1[i]) - 1) {
				if (t1[i][j] != t2[i][j]) {
					if (!p1[i + n]) p1[i + n] = j;
					p2[i + n] = j;
				}
			}
			FOR (j, p1[i + n], p2[i + n]) {
				h1[i + n] = (1ll * h1[i + n] * P1 + t1[i][j]) % mod1;	
				h2[i + n] = (1ll * h2[i + n] * P2 + t1[i][j]) % mod2;
			}
			FOR (j, p1[i + n], p2[i + n]) {
				h1[i + n] = (1ll * h1[i + n] * P1 + t2[i][j]) % mod1;	
				h2[i + n] = (1ll * h2[i + n] * P2 + t2[i][j]) % mod2;	
			}
		}
		FOR (i, 1, n + q) id[i] = i;
		sort(id + 1, id + n + q + 1, cmp);
		for (int l = 1, r = 1; l <= n + q; l = r + 1, ++r) {
			while (r <= n + q && (h1[id[r]] == h1[id[l]] && h2[id[r]] == h2[id[l]])) ++r;
			--r;
			clear();
			timer = 0;
			FOR (t, l, r) {
				int i = id[t];
				if (i <= n) {
					if (p1[i] == 1) {
						pos1[i] = 1;
					} else {
						string str = s1[i].substr(1, p1[i] - 1);
						reverse(allc(str));
						pos1[i] = insert(1, str);
					}
					pos2[i] = p2[i] == SZ(s1[i]) - 1 ? 2 : insert(2, s2[i].substr(p2[i] + 1));
				} else {
					if (SZ(t1[i - n]) != SZ(t2[i - n])) continue;
					if (p1[i] == 1) {
						pos1[i] = 1;
					} else {
						string str = t1[i - n].substr(1, p1[i] - 1);
						reverse(allc(str));
						pos1[i] = insert(1, str);
					}
					pos2[i] = p2[i] == SZ(t1[i - n]) - 1 ? 2 : insert(2, t2[i - n].substr(p2[i] + 1));
				} 
			}
			dfs(1);
			int lt = timer;
			timer = 0;
			dfs(2);
			FOR (i, 1, lt + 1) ins[i].clear(), qry[i].clear();
			FOR (t, l, r) {
				int i = id[t];
				if (i <= n) {	
					ins[L[pos1[i]]].PB(MP(pos2[i], 1));
					ins[R[pos1[i]] + 1].PB(MP(pos2[i], -1));
				} else {
					if (SZ(t1[i - n]) != SZ(t2[i - n])) continue;
					qry[L[pos1[i]]].PB(MP(pos2[i], i - n));
				}
			}
			fen.clear(timer);
			FOR (i, 1, lt) {
				FOR (j, 0, SZ(ins[i]) - 1) {
					int x = ins[i][j].FI, y = ins[i][j].SE;
					fen.upd(L[x], y), fen.upd(R[x] + 1, -y);
				}
				FOR (j, 0, SZ(qry[i]) - 1) {
					int x = qry[i][j].FI, y = qry[i][j].SE; 
					ans[y] = fen.qry(L[x]);
				}
			}
		}
		FOR (i, 1, q) {
			cout << ans[i] << '\n';
		}
	}	
};
bool Mbe;
int main() {
	 freopen("replace.in", "r", stdin);
	 freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	lyl::solve();
//	 cerr << "Space: " << abs(&Meb - &Mbe) / 1024.0 / 1024.0 << "MB\n";
	// cerr << "Time: << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
 	return 0;
}
