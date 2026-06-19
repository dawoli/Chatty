#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 5e5 + 5;
int a[N], xo[N], f[N];
unordered_map<int, int> mp;

int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  mp[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    xo[i] = xo[i - 1] ^ a[i];
    int pre = xo[i] ^ k;
    if (mp.count(pre)) {
      f[i] = f[ mp[pre] ] + 1;
    }
    f[i] = max(f[i], f[i - 1]);
    mp[ xo[i] ] = i;
  }
  cout << f[n];

  return 0;
}
