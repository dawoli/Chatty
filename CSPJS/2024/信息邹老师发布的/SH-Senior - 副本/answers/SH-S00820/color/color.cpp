#include <bits/stdc++.h>
using namespace std;
const int _ = 2e5 + 10;
const int __ = 1e6 + 10;
int T, n, a[_], b[_], las[__];
long long dp[_], sum;
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            cin >> a[i];
            int j = las[a[i]];
            if (j) {
                if (j == i - 1) {
                    sum += a[i];
                } else {
                    dp[i] = max(dp[i], dp[j + 1] + a[i]);
                }
            }
            las[a[i]] = i;
        }
        cout << sum + dp[n];
        if (T) {
            cout << '\n';
        }
        sum = 0LL;
        for (int i = 1; i <= n; i++) {
            las[a[i]] = 0;
        }
    }
    cout << endl;
    return 0;
}