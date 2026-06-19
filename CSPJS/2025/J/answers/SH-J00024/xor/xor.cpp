#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, k, num, now;
int lst[N], dp[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    memset(lst, -1, sizeof(lst));
    memset(dp, 0, sizeof(dp));
    now = 0;
    lst[0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        now ^= x;
        num = now ^ k;
        lst[now] = i;
        if (lst[num] != -1) {
            dp[i] = max(dp[lst[num]] + 1, dp[i-1]);
        } else {
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
