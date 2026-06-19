#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct edge {ll u, v, w;};
typedef long long ll;
bool cmp (edge a, edge b) {return a.w < b.w;};
vector <edge> e;
ll n, m, k, ans1 = 1e18;
ll c [N], a [11] [N], f [N];
bool cur [N];
ll find (ll x) {
	if (f [x] == x) return x;
	else return f [x] = find (f [x]);
}
void merge (ll x, ll y) {
	f [find (x)] = f [find (y)];
}
bool check (ll x, ll y) {
	return f [find (x)] == f [find (y)];
}
void calc () {
	vector <edge> e1;
	for (int i = 0; i < e.size (); i ++)
		e1.push_back ({e [i].u, e [i].v, e [i].w});
	int nn = 1;
	for (ll i = 1; i <= k; i ++)
		if (cur [i]) {
			for (ll j = 1; j <= n; j ++)
				e1.push_back ({nn + n, j, a [i] [j]});
			nn ++;
		}
	nn --;
	sort (e1.begin (), e1.end (), cmp);
	for (ll i = 1; i <= n + nn; i ++)
		f [i] = i;
	ll ans = 0, cntt = 0;
	for (ll i = 0; i < e1.size (); i ++) {
		if (cntt == n + nn - 1) break;
		if (!check (e1 [i].u, e1 [i].v)) {
			merge (e1 [i].u, e1 [i].v);
			ans += e1 [i].w;
			cntt ++;
		}
	}
	for (ll i = 1; i <= k; i ++)
		if (cur [i])
			ans += c [i];
	ans1 = min (ans1, ans);
}
void dfs (ll l) {
	if (l == k + 1) {
		calc ();
		return;
	}
	cur [l] = 0;
	dfs (l + 1);
	cur [l] = 1;
	dfs (l + 1);
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i ++) {
		ll u, v, w; cin >> u >> v >> w;
		e.push_back ({u, v, w});
	}
	for (ll i = 1; i <= k; i ++) {
		cin >> c [i];
		for (ll j = 1; j <= n; j ++)
			cin >> a [i] [j];
	}
	dfs (1);
	cout << ans1;
}
