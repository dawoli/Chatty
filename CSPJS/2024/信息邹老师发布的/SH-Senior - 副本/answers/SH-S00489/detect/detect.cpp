#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T;
int d[maxn], v[maxn], a[maxn], p[maxn];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        int n, m, L, V;
        int maxp = -1, cnt = 0, ans;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
            maxp = max(maxp, p[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (v[i] > V && d[i] <= maxp) {
                cnt++;
            }
        }
        if (cnt != 0) {
            ans = m - 1;
        } else {
            ans = m;
        }
        cout << cnt << " " << ans << endl;
    }
    return 0;
}
