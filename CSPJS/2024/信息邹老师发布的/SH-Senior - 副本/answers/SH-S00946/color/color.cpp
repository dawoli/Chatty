#include <iostream>
#include <algorithm>

int n, a[200007];
long long tag;
long long mx[1000007];

void solve() {
  std::cin >> n, n += 2;
  for (int i = 3; i <= n; ++i) {
    std::cin >> a[i];
  }
  tag = 0;
  for (int i = 1; i <= 1000000; ++i) {
    mx[i] = -1e18;
  }
  mx[0] = 0;
  for (int i = 3; i <= n; ++i) {
    long long val = std::max(mx[0], mx[a[i]] + a[i]) + tag;
    if (a[i] == a[i - 1]) {
      tag += a[i];
    }
    mx[a[i - 1]] = std::max(mx[a[i - 1]], val - tag);
    mx[0] = std::max(mx[0], mx[a[i - 1]]);
  }
  std::cout << mx[0] + tag << '\n';
}

int main() {
  std::freopen("color.in", "r", stdin);
  std::freopen("color.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }  
  return 0;
}