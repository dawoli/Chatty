#include <bits/stdc++.h>
using namespace std;
const int _ = 1e5 + 10;
int d[_], v[_], a[_], p[_], r[_];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
            r[i] = m + 1;
        }
        r[m + 1] = m + 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 0) {
                int D = d[i];
                if (v[i] <= V) {
                    D += (V * V - v[i] * v[i]) / (a[i] << 1) + 1;
                }
                int x = lower_bound(p + 1, p + m + 1, D) - p;
                if (x != m + 1) {
                    cnt++;
                    r[x] = min(r[x], m);
                }
            } else if (a[i] == 0) {
                if (v[i] > V) {
                    int x = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    if (x != m + 1) {
                        cnt++;
                        r[x] = min(r[x], m);
                    }
                }
            } else {
                if (v[i] > V) {
                    int D = d[i] + (v[i] * v[i] - V * V + ((-a[i]) << 1) - 1) / ((-a[i]) << 1);
                    int x = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    int y = lower_bound(p + 1, p + m + 1, D) - p;
                    if (x != y) {
                        cnt++;
                        r[x] = min(r[x], y - 1);
                    }
                }
            }
        }
        for (int i = m; i >= 1; i--) {
            r[i] = min(r[i], r[i+1]);
        }
        int cur = 1, ans = m + 1;
        while (cur != m + 2) {
            ans--;
            cur = r[cur] + 1;
        }
        cout << cnt << ' ' << ans;
        if (T) {
            cout << '\n';
        }
    }
    cout << endl;
    return 0;
}