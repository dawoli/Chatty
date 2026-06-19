#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5e3 + 8, MOD = 998244353;
int n, a[MAXN], ans;
void dfs(int pos, int ch, int mx, int sum, bool nc)
{
    if (nc && ch >= 3 && sum > mx * 2) ans = (ans + 1) % MOD;
    if (pos > n) return;
    dfs(pos + 1, ch + 1, max(mx, a[pos]), sum + a[pos], true);
    dfs(pos + 1, ch, mx, sum, false);
}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0, 0, false);
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
