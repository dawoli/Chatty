#include <iostream>
#include <set>
using namespace std;

typedef long long LL;

const LL N = 1e5 + 10;
LL d[N], v[N], a[N], p[N];

LL instant_v(LL v0, LL _a, LL s) {
    return v0 * v0  + 2 * _a * s;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    LL t;
    cin >> t;
    while (t--) {
        LL n, m, l, limit;
        cin >> n >> m >> l >> limit;
        bool all_0, all_pos, all_neg;
        all_0 = all_pos = all_neg = true;
        for (LL i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
            all_0 &= (a[i] == 0);
            all_pos &= (a[i] > 0);
            all_neg &= (a[i] < 0);
        }
        for (LL i = 1; i <= m; i++) {
            cin >> p[i];
        }
        if (all_0) {
            LL cnt = 0;
            for (LL i = 1; i <= n; i++) {
                if (d[i] <= p[m] && v[i] > limit) {
                    cnt++;
                }
            }
            cout << cnt << ' ' << m - (cnt != 0) << endl;
            continue;
        }
        if (all_pos) {
            LL cnt = 0;
            for (LL i = 1; i <= n; i++) {
                if (d[i] <= p[m] && instant_v(v[i], a[i], p[m] - d[i]) > limit * limit) {
                    cnt++;
                }
            }
            cout << cnt << ' ' << m - (cnt != 0) << endl;
            continue;
        }
        if (all_neg) {
            LL cnt = 0;
            set<LL> camaras;
            for (LL i = 1; i <= n; i++) {
                LL *pos = lower_bound(p + 1, p + 1 + n, d[i]);
                if (pos == p + 2 + n) {
                    continue;
                }
                if (instant_v(v[i], a[i], *pos - d[i]) > limit * limit) {
                    cnt++;
                    camaras.insert(pos - p);
                }
            }
            cout << cnt << ' ' << camaras.size() << endl;
            continue;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
