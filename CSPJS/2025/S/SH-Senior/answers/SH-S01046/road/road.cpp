#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e4 + 15, M = 1e6 + 5;
int n, m, k, cur;
struct Edge { int u, v; ll w; } e[M], e1[M];
ll c[15], a[15][N];
int f[N];

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

ll kruskal() {
  iota(f + 1, f + n + k + 1, 1);
  sort(e + 1, e + m + 1, cmp);
  if (cur) sort(e1 + 1, e1 + cur + 1, cmp);
  ll res = 0;
  for (int i = 1, j = 1; i <= m || j <= cur;) {
    int t = j > cur || i <= m && e[i].w < e1[j].w ? 0 : 1;
    int u, v; ll w;
    if (!t) u = find(e[i].u), v = find(e[i].v), w = e[i++].w;
    else    u = find(e1[j].u), v = find(e1[j].v), w = e1[j++].w;
    if (u == v) continue;
    f[u] = v;
    res += w;
  }
  return res;
}

ll calc(int S) {
  ll res = 0;
  cur = 0;
  for (int i = 1; i <= k; i++)
    if (S & 1 << i - 1) {
      res += c[i];
      for (int j = 1; j <= n; j++)
        e1[++cur] = { j, n + i, a[i][j] };
    }
  return res + kruskal();
}

void solve() {
  ll ans = 2e18;
  for (int S = 0; S < 1 << k; S++)
    ans = min(ans, calc(S));
  cout << ans;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  bool flag = k;
  for (int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    e[i] = { u, v, w };
  }
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
    if (c[i])
      flag = false;
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j]) flag = false;
    }
  }
  if (flag) {
    cout << 0;
    return 0;
  } else {
    solve();
  }

  return 0;
}

