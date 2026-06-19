#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

using LL = long long;

const LL MOD = 998244353; 
const LL N = 5010;
LL a[N], s[N], dp[N * N];

LL pow_2(LL n) {
    if (n == 0) {
        return 1;
    }
    LL half = pow_2(n / 2);
    return half * half % MOD * (n % 2 == 0 ? 1 : 2) % MOD;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    LL n;
    cin >> n;
    bool all_1 = true;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            all_1 = false;
        }
    }
    if (all_1) {
        LL ans = (pow_2(n) - n * (n - 1) / 2 - n - 1 + MOD) % MOD;
        cout << ans << endl;
        return 0;
    }
    sort(a + 1, a + 1 + n);
    s[0] = 0;
    for (LL i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (LL j = 1; j <= s[n]; j++) {
        dp[j] = 1;
    }
    LL cnt = 0;
    for (LL i = 1; i <= n; i++) {
        if (i >= 3 && s[i - 1] >= a[i]) {
            cnt += dp[s[i - 1] - a[i]];
            cnt %= MOD;
        }
        for (LL j = s[n]; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
    }
    cout << cnt << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
