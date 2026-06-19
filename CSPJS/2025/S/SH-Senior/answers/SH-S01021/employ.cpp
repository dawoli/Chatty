#include <iostream>

constexpr int mod = 0x3b800001;
int n, m;
char s[507];
int c[507], g[507];
int dp[2][507][507];

int main() {
  std::freopen("employ.in", "r", stdin);
  std::freopen("employ.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> m >> s;
  for (int i = 1; i <= n; ++i) {
    std::cin >> c[i]; 
    if (c[i] >= 1) {
      ++g[c[i] - 1];
    }
  }
  for (int i = n; i >= 1; --i) {
    g[i - 1] += g[i];
  }
  for (int i = 0; i <= n - m; ++i) {
    dp[1][i][0] = 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          dp[0][j][k] = dp[1][j + 1][k];
        }
      }
    } else {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          dp[0][j][k] = dp[1][j + 1][k];
          if (k >= 1) {
            dp[0][j][k] = (dp[0][j][k] + 1LL * dp[1][j][k - 1] * std::max(g[j] - (k - 1), 0)) % mod;
            dp[0][j][k] = (dp[0][j][k] - 1LL * dp[1][j + 1][k - 1] * std::max(g[j] - (k - 1), 0) % mod + mod) % mod;
          }
        }
      }
    }
    std::swap(dp[0], dp[1]);
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= n - i; ++j) {
      dp[1][0][i] = 1LL * j * dp[1][0][i] % mod;
    }
    ans = (ans + dp[1][0][i]) % mod;
  }
  std::cout << ans << '\n';
  return 0;
}