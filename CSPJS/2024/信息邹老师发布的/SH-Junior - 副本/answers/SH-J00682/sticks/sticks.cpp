#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, w[10]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long dp[100001];
long long wei(long long x)
{
    if (x == 0) return 10;
    long long ans = 1;
    while (x)
    {
        ans *= 10;
        x /= 10;
    }
    return ans;
}
long long num(long long x)
{
    int cur = 0, a[20];
    long long ans = 0;
    while (x)
    {
        a[++cur] = x % 10;
        x /= 10;
    }
    for (int i = cur; i >= 1; i--)
    {
        if (a[i] == 6) ans *= 10;
        else ans = ans * 10 + a[i];
    }
    return ans;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        dp[1] = -1, dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;
        for (int i = 8; i <= n; i++)
        {
            dp[i] = 1e9;
            for (int j = 1; j <= 9; j++)
                dp[i] = min(dp[i], j * wei(dp[i - w[j]]) + num(dp[i - w[j]]));
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
