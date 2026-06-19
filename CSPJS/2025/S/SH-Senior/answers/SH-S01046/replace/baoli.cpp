#include <iostream>
using namespace std;

const int N = 2005;
string s1[N], s2[N];



int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> s1[i] >> s2[i];
  while (q--) {
    string t1, t2;
    cin >> t1 >> t2;
    int ans = 0;
    int l = min(t1.size(), t2.size());
    for (int i = 0; i < min(t1.size(), t2.size()); i++)
      if (t1[i] != t2[i]) {
        l = i;
        break;
      }
    for (int i = 0; i <= l; i++) {
      for (int j = 1; j <= n; j++) {
        bool flag = true;
        for (int k = i; k <= i + s1[j].size() - 1; k++)
          if (k >= t1.size() || t1[k] != s1[j][k - i]) {
            flag = false;
            break;
          }
        if (!flag) continue;
        string tmp = "";
        for (int k = 0; k < i; k++)
          tmp += t1[k];
        tmp += s2[j];
        for (int k = i + s1[j].size(); k < t1.size(); k++)
          tmp += t1[k];
        if (tmp == t2) ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
