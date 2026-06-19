#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], p[N], ans; char s[N];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m; char ch;
    for (int i = 1; i <= n; i++) cin >> ch, s[i] = ch;
    for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i;
    do {
        int cnt = 0, tot = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt >= c[p[i]]) cnt++;
            else if (s[i] == '1') tot++;
            else cnt++;
        }
        if (tot >= m) (++ans) %= mod;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}
