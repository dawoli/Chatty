#include <iostream>
#include <algorithm>

int n, c[100007];

int main() {
  std::freopen("duel.in", "r", stdin);
  std::freopen("duel.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n;
  while (n--) {
    int x;
    std::cin >> x;
    ++c[x];
  }
  std::cout << *std::max_element(c + 1, c + 100001) << '\n';
  return 0;
}