#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100010, N1 = 210;
ll n, flag1, flag2, b[N], a[N][5], cnt[5], vis1[N], dp[N1][N1][N1];
struct node { ll x, y, id; }s[N];
bool cmp(node a, node b) { return a.x > b.x; }
void solve()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
    flag1 = flag2 = 1;
    for (ll i = 1; i <= n; i++) flag1 &= (!a[i][2] && !a[i][3]), flag2 &= (!a[i][3]);
    if (flag1)
    {
        ll ret = 0;
        for (ll i = 1; i <= n; i++) b[i] = a[i][1];
        sort(b + 1, b + n + 1, greater<ll>());
        for (ll i = 1; i <= n/2; i++) ret += b[i];
        printf("%lld\n", ret);
        return ;
    }
    if (n <= 200)
    {
        memset(dp, 0, sizeof(dp));
        for (ll i = 1; i <= n; i++)
            for (ll j = 0; j <= n/2; j++)
                for (ll k = 0; k <= n/2; k++)
                {
                    if (i-j-k > n/2) continue;
                    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[i][1]);
                    if (k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + a[i][2]);
                    if (i-j-k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + a[i][3]);
                }
        ll ret = 0;
        for (ll j = 0; j <= n/2; j++)
            for (ll k = 0; k <= n/2; k++)
                if (n-j-k <= n/2) ret = max(ret, dp[n][j][k]);
        printf("%lld\n", ret);
        return ;
    }
    cnt[1] = cnt[2] = cnt[3] = 0;
    for (ll i = 1; i <= n; i++)
    {
        vis1[i] = 0;
        for (ll j = 1; j <= 3; j++) s[(i-1)*3+j] = {a[i][j], j, i};
    } sort(s + 1, s + n*3 + 1, cmp);
    ll ret = 0;
    for (ll i = 1; i <= n*3; i++)
        if (cnt[s[i].y] < n/2 && !vis1[s[i].id]) cnt[s[i].y]++, vis1[s[i].id] = 1, ret += s[i].x;
    printf("%lld\n", ret);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ll T = 1; scanf("%lld", &T);
    while (T--) solve();
    return 0;
}
