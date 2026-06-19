#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector<vector<ll>> coins; // coins[i][j]: 第i个箱子减半j次后的金币数
int main()
{
    cin >> n >> k;
    vector<ll> a(n + 1);
    int max_halve = 0;
    coins.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        coins[i].push_back(a[i]);
        ll val = a[i];
        while (val > 0) {
            val /= 2;
            coins[i].push_back(val);
        }
        max_halve = max(max_halve, (int)coins[i].size());
    }
    // dp[i][j]: 前i个箱子，用了j次B钥匙的最大金币数
    vector<ll> dp(max_halve, LLONG_MIN), ndp(max_halve, LLONG_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        fill(ndp.begin(), ndp.end(), LLONG_MIN);
        for (unsigned long long j = 0; j < coins[i].size(); j++) {
            if (dp[j] == LLONG_MIN) continue;
            // 用A钥匙
            ndp[j] = max(ndp[j], dp[j] + coins[i][j] - k);
            // 用B钥匙
            if (j + 1 < coins[i].size())
                ndp[j + 1] = max(ndp[j + 1], dp[j] + coins[i][j + 1]);
        }
        swap(dp, ndp);
    }
    ll ans = LLONG_MIN;
    for (ll x : dp) ans = max(ans, x);
    cout << ans;
    return 0;
}
