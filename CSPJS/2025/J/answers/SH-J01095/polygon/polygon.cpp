#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, a[5005], vis[5005], ans = 0;
void dfs(int x, int sum, int m, int mx)
{
    if (vis[x]) return;
    if (x > n)
    {
        if (m >= 3 && sum > mx * 2) ans++, ans % MOD;
        return;
    }
    vis[x] = true;
    dfs(x + 1, sum + a[x], m + 1, max(mx, a[x]));
    vis[x] = false;
    dfs(x + 1, sum, m, mx);
}

//int dfs1(int x, int sum, int m, int mx) {
//    if (m >= 3 && sum > mx * 2) return 1;
//    return dfs1(x + 1, sum + a[x], m + 1, max(mx, a[x])) + dfs1(x + 1, sum, m, mx);
//}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1) flag = true;
    }
    sort(a + 1, a + 1 + n);
    //if (x >= 25) dfs1(1, 0, 0, 0);
    //else dfs(1, 0, 0, 0);
    if (flag)
        dfs(1, 0, 0, 0);
    else
    {
        int lm = 1,last = n, ans = 0;
        for (int m = 2; m <= n; m++)
        {
            int re = last *(n - (m - 1)) % MOD;
            last = re;
            ans += re / (lm * m) % MOD;
            lm = lm * m % MOD;
        }
    }
    cout << ans % MOD << "\n";
    return 0;
}
