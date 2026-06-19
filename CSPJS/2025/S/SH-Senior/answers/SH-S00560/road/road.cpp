#include <bits/stdc++.h>

#define int long long

constexpr int N = 10015;
constexpr int K = 15;
constexpr int INF = 1e18;

int n, m, k;
struct Edge {
  int u, v, w;
  bool operator<(const Edge &other) const {
    return w < other.w;
  }
};
std::vector<Edge> e0, e1;
int c[K], a[K][N];

namespace set {
  int fa[N];
  void init() {
    for (int i = 1; i <= n + k; ++i) {
      fa[i] = i;
    }
  }
  int find(int u) {
    if (fa[u] == u) return u;
    return fa[u] = find(fa[u]);
  }
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  // freopen("road.err", "w", stderr); // dbg
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m >> k;
  e0.resize(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> e0[i].u >> e0[i].v >> e0[i].w;
  }
  if (k == 0) {
    set::init();
    int ans = 0;
    std::sort(e0.begin(), e0.end());
    for (const Edge &i : e0) {
      int fu = set::find(i.u), fv = set::find(i.v);
      if (fu != fv) {
        set::fa[fu] = fv;
        ans += i.w;
        // std::cerr << i.u << ' ' << i.v << ' ' << i.w << '\n'; // dbg
      }
    }
    std::cout << ans << '\n';
    return 0;
  }

  const int LMT = 3e8 / (m * std::log2(m));
  for (int i = 1; i <= k; ++i) {
    std::cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      std::cin >> a[i][j];
    }
  }
  int ans = INF, cnt = 0;
  for (int use = (1 << k) - 1; use >= 0; --use) {
    set::init();
    e1 = e0;
    int res = 0;
    for (int i = 1; i <= k; ++i) {
      if (use >> (i - 1) & 1) {
        res += c[i];
        for (int j = 1; j <= n; ++j) {
          e1.push_back(Edge{j, n + i, a[i][j]});
        }
      }
    }
    std::sort(e1.begin(), e1.end());
    for (const Edge &i : e1) {
      int fu = set::find(i.u), fv = set::find(i.v);
      if (fu != fv) {
        set::fa[fu] = fv;
        res += i.w;
        // std::cerr << i.u << ' ' << i.v << ' ' << i.w << '\n'; // dbg
      }
    }
    ans = std::min(ans, res);
    if (++cnt >= LMT) {
      std::cout << ans << '\n';
      return 0;
    }
  }
  std::cout << ans << '\n';
  return 0;
}