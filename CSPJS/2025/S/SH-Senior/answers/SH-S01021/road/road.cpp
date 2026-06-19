#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
  int u, v, w;
  bool operator<(Edge rhs) const { return w < rhs.w; }
};
int n, m, k;
int dsu[10017], sz[10017];
void init() {
  for (int i = 1; i <= n + k; ++i) {
    dsu[i] = i, sz[i] = 1;
  }
} 
int anc(int u) {
  if (dsu[u] == u) {
    return u;
  }
  return dsu[u] = anc(dsu[u]);
}
bool merge(int u, int v) {
  u = anc(u), v = anc(v);
  if (u == v) {
    return 0;
  }
  if (sz[u] > sz[v]) {
    std::swap(u, v);
  }
  dsu[u] = v, sz[v] += sz[u];
  return 1;
}

int c[17], a[17][10007];
std::vector<Edge> T;
void MST(std::vector<Edge>& Q) {
  init();
  int t = 0;
  for (int i = 0; i < int(Q.size()); ++i) {
    if (merge(Q[i].u, Q[i].v)) {
      Q[t++] = Q[i];
    }
  }
  Q.resize(t);
}
void build(std::vector<Edge>* Q, int l, int r, bool TT) {
  std::vector<Edge> E[5];
  for (int i = l; i <= r; ++i) {
    for (int j = 1; j <= n; ++j) {
      E[i - l].push_back({j, i + n, a[i][j]});
    }
    std::sort(E[i - l].begin(), E[i - l].end());
  }
  for (int i = 0; i < (1 << (r - l + 1)); ++i) {
    if (i == 0) {
      if (TT) {
        Q[i] = T;
      }
      continue;
    }
    int z = 31 ^ __builtin_clz(i & -i);
    Q[i].resize(Q[i ^ (i & -i)].size() + E[z].size());
    std::merge(Q[i ^ (i & -i)].begin(), Q[i ^ (i & -i)].end(), E[z].begin(), E[z].end(), Q[i].begin());
    MST(Q[i]);
  }
}
std::vector<Edge> Q[2][32];

long long solve(int mask) {
  long long ans = 0;
  auto &v1 = Q[0][mask & ((1 << (k >> 1)) - 1)], &v2 = Q[1][mask >> (k >> 1)];
  init();
  for (int i = 0; i < k; ++i) {
    if ((mask >> i) & 1) {
      ans += c[i + 1];
    }
  }
  auto it1 = v1.begin(), it2 = v2.begin();
  while (it1 != v1.end() && it2 != v2.end()) {
    if (*it1 < *it2) {
      if (merge(it1->u, it1->v)) {
        ans += it1->w;
      }
      ++it1;
    } else {
      if (merge(it2->u, it2->v)) {
        ans += it2->w;
      }
      ++it2;
    }
  }
  while (it1 != v1.end()) {
    if (merge(it1->u, it1->v)) {
      ans += it1->w;
    }
    ++it1;
  }
  while (it2 != v2.end()) {
    if (merge(it2->u, it2->v)) {
      ans += it2->w;
    }
    ++it2;
  }
  return ans;
}

int main() {
  std::freopen("road.in", "r", stdin);
  std::freopen("road.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> m >> k;
  T.resize(m);
  for (auto& i : T) {
    std::cin >> i.u >> i.v >> i.w;
  }
  std::sort(T.begin(), T.end()), MST(T);
  for (int i = 1; i <= k; ++i) {
    std::cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      std::cin >> a[i][j];
    }
  }
  build(Q[0], 1, k >> 1, 1), build(Q[1], (k >> 1) + 1, k, 0);
  long long ans = 1e18;
  for (int i = 0; i < (1 << k); ++i) {
    ans = std::min(ans, solve(i));
  }
  std::cout << ans << '\n';
  return 0;
}