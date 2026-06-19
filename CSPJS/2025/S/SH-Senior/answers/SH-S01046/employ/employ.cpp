#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 998244353;
int n, m;
int ans = 0;
int s[15], c[15];
bool vis[15];

void dfs(int step, int cur) {
  if (step > n) ans = (ans+1) % MOD;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    dfs(step+1, cur + (!s[step] || cur >= c[i]));
    vis[i] = 0;
  }
}

int main() {
  freopen("employ1.in", "r", stdin);
  freopen("employ.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  dfs(1, 0);
  cout << ans;

  return 0;
}
