#include <iostream>
#include <algorithm>
#include <vector>

int n, m, L, V, p[100007];
std::pair<int, int> calc(int d, int v, int a) {
  if (a == 0) {
    if (v > V) {
      return {d, L};
    }
    return {-1, -1};
  }
  if (a > 0) {
    if (v > V) {
      return {d, L};
    }
    long long lft = 1 + d + (1LL * V * V - 1LL * v * v) / (a * 2);
    if (lft > L) {
      return {-1, -1};
    }
    return {lft, L};
  }
  a = -a;
  if (v <= V) {
    return {-1, -1};
  }
  long long rgt = d + (1LL * v * v - 1LL * V * V - 1) / (a * 2);
  if (rgt > L) {
    return {d, L};
  }
  return {d, rgt};
}
int lft[100007], rgt[100007];
int l[100007], r[100007], q;

void solve() {
  std::cin >> n >> m >> L >> V;
  for (int i = 1; i <= n; ++i) {
    int d, v, a;
    std::cin >> d >> v >> a;
    auto TT = calc(d, v, a);
    lft[i] = TT.first, rgt[i] = TT.second;
  }
  for (int i = 1; i <= m; ++i) {
    std::cin >> p[i];
  }
  std::vector<std::pair<int, int>> LR;
  for (int i = 1; i <= n; ++i) {
    if (lft[i] != -1 && rgt[i] != -1) {
      lft[i] = std::lower_bound(p + 1, p + m + 1, lft[i]) - p;
      rgt[i] = std::upper_bound(p + 1, p + m + 1, rgt[i]) - p - 1;
      if (!(1 <= lft[i] && lft[i] <= rgt[i] && rgt[i] <= m)) {
        lft[i] = rgt[i] = -1;
      } else {
        ++q;
        LR.push_back({lft[i], rgt[i]});
      }
    }
  }
  std::cout << LR.size() << ' ';
  std::sort(LR.begin(), LR.end(), std::greater<>());
  std::vector<int> mnr;
  int mn = m + 1;
  for (auto i : LR) {
    mnr.push_back(mn = std::min(mn, i.second));
  }
  int ans = m;
  while (!LR.empty()) {
    int u = mnr[LR.size() - 1];
    while (!LR.empty() && LR.back().first <= u) {
      LR.pop_back();
    }
    --ans;
  }
  std::cout << ans << '\n';
}

int main() {
  std::freopen("detect.in", "r", stdin);
  std::freopen("detect.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}