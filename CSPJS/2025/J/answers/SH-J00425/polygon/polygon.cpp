#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const int MOD = 998244353;
int n, a[N], ans, sum[N];
int qpow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = (res * x) % MOD;
        x = x * x % MOD;
        y /= 2;
    }
    return res % MOD;
}
void dfs(int x, int s, int k)
{
    if (sum[k - 1] - sum[x - 1] + s < a[k])
        return;
    if (s > a[k])
    {
        ans += qpow(2, (k - x));
        return;
    }
    if (x == k)
        return;
    dfs(x + 1, s, k);
    dfs(x + 1, s + a[x], k);
}
signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int maxa = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], maxa = max(maxa, a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    if (maxa == 1)
    {
        cout << (qpow(2, n) + MOD - (n * (n - 1) / 2 % MOD) - n - 1) % MOD;
        return 0;
    }
    for (int i = 3; i <= n; i++)
        dfs(1, 0, i);
    cout << ans;
    return 0;
}
// 70
