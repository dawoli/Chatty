#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, c[MAXN], cnt[MAXN];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    sort(c + 1, c + 1 + n);
    // for (int i = 1; i <= n; ++i)
    //     cout << c[i] << " ";

    //lisanhua
    int cur = 1; 
    // l[1] = 1;
    cnt[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (c[i - 1] != c[i]) cur++;
        // l[i] = cur;
        cnt[cur]++;
        // cout << cur << " ";
    }
    // for (int i = 1; i <= cur; ++i)
    //     cout << "$ " << i << ": " << cnt[i] << "\n";
    // int ans = cnt[1];
    // for (int i = 2; i < cur; ++i) {
    //     ans = abs(cnt[i] - ans) + cnt[i];
    // }
    // ans = max(cnt[cur], ans);
    int ans = 0;
    for (int i = 1; i <= cur; ++i) 
        ans = max(ans, cnt[i]);
    cout << ans << "\n";
    return 0;
}
