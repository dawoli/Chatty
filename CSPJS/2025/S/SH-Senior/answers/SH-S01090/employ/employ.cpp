#include <bits/stdc++.h>
using namespace std;
#define maxn 505
int n, m, c[maxn], cnt, ans;
string s;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
        ans %= 998244353;
    }
    cout << ans;

    return 0;
}