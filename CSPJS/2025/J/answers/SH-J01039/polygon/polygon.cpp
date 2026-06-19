#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 5000 + 5, L = 5000 + 5, MOD = 998244353;
int a[N];
int f[N], g[N][L];


int main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  g[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    g[i][0] = 1;
    for (int j = 1; j <= 5001; j++) {
      g[i][j] = g[i - 1][j];
      if (j >= a[i])
        (g[i][j] += g[i - 1][ j - a[i] ]) %= MOD;
      if (j == 5001) {
        for (int k = 0; k < a[i]; k++)
          (g[i][j] += g[i - 1][j - k]) %= MOD;
      }
    }
  }
  for (int i = 3; i <= n; i++)
    for (int j = a[i] + 1; j <= 5001; j++)
      f[i] = (f[i] + g[i - 1][j]) % MOD;
  int ans = 0;
  for (int i = 3; i <= n; i++)
    ans = (ans + f[i]) % MOD;
  cout << ans;

  return 0;
}
