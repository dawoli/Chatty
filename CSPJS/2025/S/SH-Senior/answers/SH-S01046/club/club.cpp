#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
int d[N][5];
vector<int> vec[5];

void solve() {
  vec[1].clear();
  vec[2].clear();
  vec[3].clear();

  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> d[i][1] >> d[i][2] >> d[i][3];
    int mx = max({ d[i][1], d[i][2], d[i][3] });

    if (mx == d[i][1])      vec[1].push_back(max(d[i][2], d[i][3]) - d[i][1]);
    else if (mx == d[i][2]) vec[2].push_back(max(d[i][1], d[i][3]) - d[i][2]);
    else if (mx == d[i][3]) vec[3].push_back(max(d[i][1], d[i][2]) - d[i][3]);

    ans += mx;
  }
  int t = 0;
  if (vec[1].size() > n / 2)      t = 1;
  else if (vec[2].size() > n / 2) t = 2;
  else if (vec[3].size() > n / 2) t = 3;

  if (t) {
    sort(vec[t].begin(), vec[t].end(), greater<int>());
    for (int i = 0; i < vec[t].size() - n / 2; i++)
      ans += vec[t][i];
  }
  cout << ans << '\n';
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);

  int t; cin >> t;
  while (t--) solve();

  return 0;
}
