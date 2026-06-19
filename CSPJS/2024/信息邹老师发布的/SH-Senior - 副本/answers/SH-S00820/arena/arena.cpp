#include <bits/stdc++.h>
using namespace std;
const int _ = 1e6;
int Testcases, n, m, k, A[_], c[_], X[4], a[_], v[_], h[_], hh[_], res[_];
long long s[_], ans;
bool d[_];
inline void pushup(int p) {
    int l = (p << 1);
    int r = ((p << 1) | 1);
    if (d[p]) {
        swap(l, r);
    }
    if (v[l] == -1) {
        v[p] = -1;
        s[p] = s[l] + s[r];
    } else if (v[l] >= h[p]) {
        v[p] = v[l];
        s[p] = s[l];
    } else {
        v[p] = v[r];
        s[p] = s[r];
    }
}
inline void update(int p) {
    while (p != 1) {
        (p >>= 1);
        pushup(p);
    }
}
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    k = __lg(n - 1) + 1;
    h[1] = k;
    for (int i = 2; i < (1 << k); i++) {
        h[i] = h[i >> 1] - 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    for (int r = 1; r <= k; r++) {
        string str;
        cin >> str;
        for (int i = 0; i < (1 << (k - r)); i++) {
            d[(1 << (k - r)) | i] = (str[i] == '1');
        }
    }
    hh[1] = 0;
    for (int i = 1; i < (1 << k); i++) {
        hh[i << 1] = hh[i];
        hh[(i << 1) | 1] = hh[i];
        (hh[(i << 1) | d[i]] |= (1 << (h[i] - 1)));
    }
    cin >> Testcases;
    while (Testcases--) {
        for (int i = 0; i <= 3; i++) {
            cin >> X[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] = (A[i] ^ X[i & 3]);
        }
        for (int i = 0; i < (1 << k); i++) {
            int p = ((1 << k) | i);
            v[p] = -1;
            s[p] = i + 1;
        }
        for (int i = (1 << k) - 1; i >= 1; i--) {
            pushup(i);
        }
        for (int i = 0; i < n; i++) {
            int x = a[i + 1];
            int p = ((1 << k) | i);
            int L = 0;
            if (i >= 1) {
                L = __lg(i) + 1;
            }
            v[p] = x;
            int H = (hh[p] & ((1 << L) - 1));
            if (x <= 25 && (1 << x) <= H) {
                s[p] = 0LL;
            }
            update(p);
            if (i && (!(i & (i - 1)))) {
                for (int j = 0; j < i; j++) {
                    int x = a[j + 1];
                    int p = ((1 << k) | j);
                    int H = (hh[p] & ((1 << (L + 1)) - 1));
                    if (x <= 25 && (1 << x) <= H) {
                        s[p] = 0LL;
                        update(p);
                    }
                }
            }
            res[i + 1] = s[1 << (k - L)];
        }
        ans = 0LL;
        for (int i = 1; i <= m; i++) {
            (ans ^= (i * res[c[i]]));
        }
        cout << ans;
        if (Testcases) {
            cout << '\n';
        }
    }
    cout << endl;
    return 0;
}