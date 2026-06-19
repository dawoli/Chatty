#include <bits/stdc++.h>

using pii = std::pair<int, int>;

constexpr int N = 100005;

int T;
int n, ans;
struct Person {
  pii val[3];
  int diff1, diff2;
} a[N];
int cnt[3];

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  // freopen("club.err", "w", stderr); // dbg
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) {
    cnt[0] = cnt[1] = cnt[2] = 0;
    ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i].val[0].first >> a[i].val[1].first >> a[i].val[2].first;
      a[i].val[0].second = 0, a[i].val[1].second = 1, a[i].val[2].second = 2;
      std::sort(a[i].val, a[i].val + 3, std::greater<pii>());
      a[i].diff1 = a[i].val[0].first - a[i].val[1].first;
      a[i].diff2 = a[i].val[1].first - a[i].val[2].first;
    }
    std::sort(a + 1, a + n + 1, [](const Person &a, const Person &b) {
      if (a.diff1 != b.diff1) return a.diff1 > b.diff1;
      return a.diff2 > b.diff2;
    });
    for (int i = 1; i <= n; ++i) {
      // std::cerr << a[i].diff1 <<" " << a[i].diff2 << "\n"; // dbg
      if (cnt[a[i].val[0].second] < n / 2) {
        ++cnt[a[i].val[0].second];
        ans += a[i].val[0].first;
        // std::cerr << "A\n"; // dbg
      } else if (cnt[a[i].val[1].second] < n / 2) {
        ++cnt[a[i].val[1].second];
        ans += a[i].val[1].first;
        // std::cerr << "B\n"; // dbg
      } else {
        ++cnt[a[i].val[2].second];
        ans += a[i].val[2].first;
        // std::cerr << "C\n"; // dbg
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}