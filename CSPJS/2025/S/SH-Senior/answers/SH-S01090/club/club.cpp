#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define int long long
#define maxn 100005
int t, n, a[maxn][5], lvl, ans = 0;

inline void calc() {
    for (int i = 1; i <= n; ++i) {
        ans += max(a[i][1], a[i][2], a[i][3]);
    }
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);  
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        for (int j = 1; j <= n; ++j)
            for (int x = 1; x <= 3; ++x)
                cin >> a[j][x];

        lvl = n / 2;
        calc(), cout << ans << '\n';
        ans = 0;
    }
    return 0;
}