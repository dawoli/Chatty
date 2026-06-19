#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n, t, tt, plen, attacted, res;
int r[MAXN], bac[MAXN], p[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    sort(r + 1, r + n + 1);

    t = 0, tt = 0; plen = 0;
    for (int i = 1; i <= n; i++) {
        if (tt == r[i]) {
            p[t]++;
        }
        else {
            t++;
            tt = r[i];
            p[t] = 1;
        }
    }
    plen = t;

    for (int i = plen; i >= 1; i--) {
        bac[i] = bac[i + 1] + p[i];
    }
    
    res = bac[1];
    
    for (int i = 1; i <= plen; i++) {
        

        if (bac[i + 1] - attacted >= p[i]) {
            res -= p[i];
        } else {
            res -= max(bac[i + 1] - attacted, 0);
            break;
        }

        if (p[i + 1] - attacted < p[i]) {
            attacted = p[i] - p[i - 1];
        } else {
            attacted = 0;
        }
    }

    cout << res << endl;
    return 0;
}
