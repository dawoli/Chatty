#include <iostream>
using namespace std;
using ull = unsigned long long;

const int N = 2005, P = 13331;
string s1[N], s2[N];

ull pw[N];
ull hs1[N], hs2[N], ht1[N], ht2;

void prep(string s, ull &h) {
  h = 0;
  for (int i = 0; i < s.size(); i++)
    h = h * P + s[i];
}


void prep(string s, ull h[]) {
  for (int i = 0; i < s.size(); i++)
    h[i] = (i>0 ? h[i-1] : 0) * P + s[i];
}

ull H(int l, int r) {
  if (!l) return ht1[r];
  return ht1[r] - ht1[l - 1] * pw[r - l + 1];
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pw[0] = 1;
  for (int i = 1; i <= 2000; i++)
    pw[i] = pw[i - 1] * P;

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
    prep(s1[i], hs1[i]);
    prep(s2[i], hs2[i]);
  }
  while (q--) {
    string t1, t2;
    cin >> t1 >> t2;
    prep(t1, ht1);
    prep(t2, ht2);
    int ans = 0;
    int l = min(t1.size(), t2.size());
    for (int i = 0; i < min(t1.size(), t2.size()); i++)
      if (t1[i] != t2[i]) {
        l = i;
        break;
      }
    for (int i = 0; i <= l; i++) {
      for (int j = 1; j <= n; j++) if (i + s1[j].size() - 1 < t1.size()) {
        bool flag = H(i, i + s1[j].size() - 1) == hs1[j];
        if (!flag) continue;
        ull tmp = i ? ht1[i - 1] : 0;
        tmp = tmp * pw[s2[j].size()] + hs2[j];
        tmp = tmp * pw[(t1.size() - 1 - (i + s1[j].size() - 1))] + H(i + s1[j].size(), t1.size() - 1);
        if (tmp == ht2) ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
