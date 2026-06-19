#include <bits/stdc++.h>

constexpr int N = 200005;

int n, Q, L1, L2;
struct Pair1 {
  std::string x, y;
  std::vector<int> nxt;
} s[N];
struct Pair2 {
  std::string x, y;
} t[N];

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w",stdout);
  // freopen("replace.err", "w", stderr); // dbg
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> Q;
  for (int i = 1; i <= n; ++i) {
    std::cin >> s[i].x >> s[i].y;
    L1 += s[i].x.size() + s[i].y.size();
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> t[i].x >> t[i].y;
    L2 += t[i].x.size() + t[i].y.size();
  }
  if (n <= 1000 && Q <= 1000 && L1 <= 2000 && L2 <= 2000) { // brute force
    for (int _ = 1; _ <= n; ++_) { // init nxt (ok)
      int len = s[_].x.size();
      s[_].nxt.resize(len);
      for (int i = 1, pre = 0; i < len; ) {
        if (s[_].x[i] == s[_].x[pre]) {
          s[_].nxt[i++] = ++pre;
        } else {
          if (pre == 0) {
            s[_].nxt[i++] = 0;
          } else {
            pre = s[_].nxt[pre - 1];
          }
        }
      }
      // dbg
      // for (int i = 0; i < len; ++i) {
      //   std::cerr << s[_].nxt[i] << " ";
      // }
      // std::cerr << "\n";
    }
    for (int _ = 1; _ <= Q; ++_) {
      if (t[_].x.size() != t[_].y.size()) {
        std::cout << "0\n";
        continue;
      }
      int ans = 0;
      std::string &s1 = t[_].x;
      int len1 = s1.size();
      for (int k = 1; k <= n; ++k) {
        std::string &s2 = s[k].x;
        int len2 = s2.size();
        for (int i = 0, j = 0; i <= len1; ) {
          if (s1[i] == s2[j]) {
            ++i, ++j;
          } else {
            if (j == 0) {
              ++i;
            } else {
              j = s[k].nxt[j - 1];
            }
          }
          if (j == len2) {
            // std::cerr << i - j << "\n"; // dbg

            // check
            std::string tmp = s1;
            for (int p = 0; p < len2; ++p) {
              tmp[i - j + p] = s[k].y[p];
            }
            if (tmp == t[_].y) {
              ++ans;
            }

            j = s[k].nxt[j - 1];
          }
        }
      }
      std::cout << ans << '\n';
    }
  } else { // pattern b
    for (int _ = 1; _ <= Q; ++_) {
      if (t[_].x.size() != t[_].y.size()) {
        std::cout << "0\n";
        continue;
      }
      int ans = 0;
      for (int k = 1; k <= n; ++k) {
        int x = t[_].x.find(s[k].x);
        int y = t[_].y.find(s[k].y);
        if (x == t[_].x.size() || y == t[_].y.size()) continue;
        if (x == y) {
          ++ans;
        }
      }
      std::cout << ans << '\n';
    }
  }

  return 0;
}