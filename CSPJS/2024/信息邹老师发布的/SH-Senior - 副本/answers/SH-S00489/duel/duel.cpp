#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int n, mx = -1e5, mn = maxn;
int d[maxn], a[maxn];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        d[x]++;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    int sum = n;
    int cnt = 0;
    int minn = maxn;
    for (int i = mn; i <= mx; i++) {
        if (d[i] != 0) {
            cnt++;
            a[cnt] = d[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (minn > i) {
            minn = i;
        } else {
            if (a[minn] <= a[i]) {
                sum -= a[minn];
                a[minn] = 0;
                minn++;
            } else if (a[minn] > a[i]) {
                a[minn] -= a[i];
                sum -= a[i];
            }
        }
    }
    cout << sum << endl;
    return 0;
}
