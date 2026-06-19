#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define int long long
using namespace std;
int rd() {
	int res = 0, c = getchar();
	while (c < 48 || c > 57) c = getchar();
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
	return res;
}
void wr(int x) {
	if (x > 9) wr(x / 10);
	putchar(x % 10 + 48);
}
const int maxn = 4e4 + 5;
const int maxk = 15;
const int inf = 1e18;
int n, m, k, r, z, ans = inf, now;
struct edge {
	int u, v, w;
	inline bool operator <(const edge &x) const {
		if (w != x.w) return w < x.w;
		if (v != x.v) return v < x.v;
		return u < x.u;
	}
};
int c[maxk];
vector<edge> g[maxk];
vector<edge> v;
set<edge> s;
int fa[maxn];
int gray(int i) {return i ^ i >> 1;}
int lowbit(int i) {return i & -i;}
void Read() {
	r = n = rd(), m = rd(), k = rd();
//	exit(9);
	for (int i = 1; i <= m; i ++) v.push_back({rd(), rd(), rd()});
	sort(v.begin(), v.end());
	for (int i = 1; i <= k; i ++) {
		c[i] = rd();
		for (int j = 1; j <= n; j ++) g[i].push_back({n + i, j, rd()});
		sort(g[i].begin(), g[i].end());
	}
}
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int run0() {
	int res = 0, cnt = 0;
	for (int i = 1; i <= n + k; i ++) fa[i] = i;
	for (auto it: v) {
		if (cnt == r - 1) break;
		int fx = find(it.u), fy = find(it.v);
		if (fx != fy) {
			fa[fx] = fy;
			cnt ++;
			res += it.w;
			z = it.w;
			s.insert(it);
		}
	}
	return res;
}
int run1() {
//	for (auto it: s) cerr << it.u << ' ' << it.v << ' ' << it.w << '\n';
//	cerr << '\n';
	int res = 0, cnt = 0;
	for (int i = 1; i <= n + k; i ++) fa[i] = i;
	for (auto it: s) {
		if (cnt == r - 1) break;
		int fx = find(it.u), fy = find(it.v);
		if (fx != fy) {
			fa[fx] = fy;
			cnt ++;
			res += it.w;
		}
	}
	return res;
}
void cont(int x, bool f) {
	if (f) {
		r --;
		now -= c[x];
		for (auto it: g[x]) s.erase(it);
	}
	else {
		r ++;
		now += c[x];
		for (auto it: g[x]) s.insert(it);
	}
}
void Solve() {
	ans = min(ans, run0());
	for (int i = 1; i <= k; i ++) g[i].erase(lower_bound(g[i].begin(), g[i].end(), (edge) {0, 0, z + 1}), g[i].end());
	for (int i = 1; i < 1 << k; i ++) {
		int u = __lg(lowbit(i));
		bool flag = gray(i - 1) >> u & 1;
		cont(u + 1, flag);
		int res = run1() + now;
//		cerr << u << ' ' << flag << '\n';
//		cerr << res << ' ' << now << '\n';
		ans = min(ans, res);
	}
	wr(ans);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	Read();
	Solve();
}
