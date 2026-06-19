#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, ans;
struct Node {
    int y[4];
} a[N];
// int dp[N][N / 2];
void dfs(int x, int cnt1, int cnt2, int cnt3, int sum)
{
    if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
    if (x > n) {
        ans = max(ans, sum);
        return;
    }
    dfs(x + 1, cnt1 + 1, cnt2, cnt3, sum + a[x].y[1]);
    dfs(x + 1, cnt1, cnt2 + 1, cnt3, sum + a[x].y[2]);
    dfs(x + 1, cnt1, cnt2, cnt3 + 1, sum + a[x].y[3]);
    // int i = 0, j = 0, k = 0;
    // if (cnt1 + 1 <= n / 2) i = dfs(x + 1, cnt1 + 1, cnt2, cnt3) + a[x].y[1];
    // if (cnt2 + 1 <= n / 2) j = dfs(x + 1, cnt1, cnt2 + 1, cnt3) + a[x].y[2];
    // if (cnt3 + 1 <= n / 2) k = dfs(x + 1, cnt1, cnt2, cnt3 + 1) + a[x].y[3];
    // return dp[x][cnt1][cnt2][cnt3] = max({i, j, k});
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].y[1] >> a[i].y[2] >> a[i].y[3];
        }
        dfs(1, 0, 0, 0, 0);
        cout << ans << "\n";
        //cout << dfs(1, 0, 0, 0) << "\n";
    }
}