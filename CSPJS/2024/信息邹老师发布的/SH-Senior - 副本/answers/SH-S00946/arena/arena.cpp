#include <iostream>

const int top = 17;
struct S {
  long long Sum[top + 2];
  S() {
    for (int i = 0; i <= top + 1; ++i) {
      Sum[i] = 0;
    }
  }
};
void op(S lhs, S rhs, int h, S& to) {
  for (int i = 0; i <= top + 1; ++i) {
    to.Sum[i] = 0;
  }
  for (int i = h; i <= top + 1; ++i) {
    to.Sum[i] += lhs.Sum[i];
  }
  bool ok = (lhs.Sum[top + 1] != 0);
  for (int i = 0; i < h; ++i) {
    if (lhs.Sum[i] != 0) {
      ok = true;
    }
  }
  if (ok) {
    for (int i = 0; i <= top + 1; ++i) {
      to.Sum[i] += rhs.Sum[i];
    }
  }
}

S tr[1 << (top + 1)];
int n, m;
int a[100007], c[100007];
int P[1 << (top + 1)];
long long ans[100007];
int h[1 << (top + 1)];
int LOG;

void solve() {
  for (int i = (1 << LOG); i < (1 << (LOG + 1)); ++i) {
    tr[i] = S();
    tr[i].Sum[top + 1] = i - (1 << LOG) + 1;
  }
  for (int i = (1 << LOG) - 1; i >= 1; --i)  {
    if (P[i] == 0) {
      op(tr[i << 1], tr[i << 1 | 1], h[i], tr[i]);
    } else {
      op(tr[i << 1 | 1], tr[i << 1], h[i], tr[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    tr[i + (1 << LOG) - 1].Sum[top + 1] = 0;
    tr[i + (1 << LOG) - 1].Sum[std::min(top, a[i])] = i;
    int id = 1;
    for (int j = i + (1 << LOG) - 1, sz = 1; j != 1; j >>= 1, sz <<= 1) {
      int nd = j >> 1;
      if (P[nd] == 0) {
        op(tr[nd << 1], tr[nd << 1 | 1], h[nd], tr[nd]);
      } else {
        op(tr[nd << 1 | 1], tr[nd << 1], h[nd], tr[nd]);
      }
      if (sz >= i && id == 1) {
        id = j;
      }
    }
    ans[i] = 0;
    for (int j = 0; j <= top + 1; ++j) {
      ans[i] += tr[id].Sum[j];
    }
  }
}

int main() {
  std::freopen("arena.in", "r", stdin);
  std::freopen("arena.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    std::cin >> c[i];
  }
  while ((1 << LOG) < n) {
    ++LOG;
  }
  for (int i = 0, H = LOG; i <= LOG; ++i, --H) {
    for (int j = (1 << i); j < (2 << i); ++j) {
      h[j] = H;
    }
  }
  for (int i = (1 << (LOG - 1)); i >= 1; i >>= 1) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < int(s.size()); ++j) {
      P[i + j] = s[j] - '0';
    }
  }
  int t;
  std::cin >> t;
  while (t--) {
    int x[4];
    std::cin >> x[0] >> x[1] >> x[2] >> x[3];
    for (int i = 1; i <= n; ++i) {
      a[i] ^= x[i & 3];
    }
    solve();
    long long res = 0;
    for (int i = 1; i <= m; ++i) {
      res ^= ans[c[i]] * i;
    }
    std::cout << res << '\n';
    for (int i = 1; i <= n; ++i) {
      a[i] ^= x[i & 3];
    }
  }
  return 0;
}