#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    set<int> ps; // numbers possible to be max
    for (int i = 3; i <= n; i++) ps.insert(s[i]);
    long long ans = 0;
    for (auto pre : ps) {
        int rbound = find(s.begin(), s.end(), pre) - s.begin() - 1;
        for (int j = 0; j <= pre; j++) dp[1][j] = (1 ? s[1] > j : 0);
        for (int i = 1; i <= rbound; i++) {
            for (int j = 0; j <= pre; j++) {
                if (j >= s[i-1]) dp[i][j] = dp[i-1][j] + dp[i][j-s[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        ans += dp[rbound][pre];
    }
    cout << ans % 998244353 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
