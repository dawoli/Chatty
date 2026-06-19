#include <iostream>
#include <algorithm>
#include <vector>

int n, c[3], d[100007], v[100007];
void solve() {
  std::cin >> n;
  c[0] = c[1] = c[2] = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int a[3];
    std::cin >> a[0] >> a[1] >> a[2];
    int p[3] = {0, 1, 2};
    std::sort(p, p + 3, [&](int lhs, int rhs) { return a[lhs] < a[rhs]; });
    ++c[d[i] = p[2]], v[i] = a[p[2]] - a[p[1]], ans += a[p[2]];
  }
  int oo = -1;
  if (c[0] > n / 2) {
    oo = 0;
  }
  if (c[1] > n / 2) {
    oo = 1;
  }
  if (c[2] > n / 2) {
    oo = 2;
  }
  if (oo == -1) {
    std::cout << ans << '\n';
    return;
  }
  std::vector<int> z;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == oo) {
      z.push_back(v[i]);
    }
  }
  std::nth_element(z.begin(), z.begin() + c[oo] - n / 2 - 1, z.end());
  for (int j = 0; j <= c[oo] - n / 2 - 1; ++j) {
    ans -= z[j];
  }
  std::cout << ans << '\n';
}
int main() {
  std::freopen("club.in", "r", stdin);
  std::freopen("club.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}