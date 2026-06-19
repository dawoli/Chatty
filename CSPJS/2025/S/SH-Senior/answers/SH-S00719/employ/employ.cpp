#include <bits/stdc++.h>
using namespace std;

bool c[505];
int nxz[505], p[505];
const int mod = 998244353;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        c[i] = (ch == '1');
    }
    for (int i = 1; i <= n; i++) {
        cin >> nxz[i]; p[i] = i;
    }
    int ans = 0;
    do {
        int cnt = 0, lyz = 0;
        for (int i = 1; i <= n; i++) {
            if (nxz[p[i]] <= cnt) {
                cnt++;
                continue;
            }
            if (c[i] == 0) {
                cnt++;
                continue;
            }
            lyz++;
        }
        ans += (lyz >= m);
        if ((double)clock() / CLOCKS_PER_SEC >= 0.9) break;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
}