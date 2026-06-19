#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, a[200010], occur[1000010], pre[200010], suffix[200010], dp[200010];

int main() {
    freopen("color1.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%lld", &T);
for(int times = 1; times <= T; ++times) {
    scanf("%lld", &n);
    memset(occur, 0, sizeof(occur));
    memset(pre, 0, sizeof(pre));
    memset(suffix, 0, sizeof(suffix));
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if(occur[a[i]]) pre[i] = occur[a[i]];
        occur[a[i]] = i;
        suffix[i] = suffix[i - 1];
        if(a[i] == a[i - 1]) suffix[i] += a[i];
    }
    for(int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if(pre[i]) dp[i] = max(dp[i], dp[pre[i] - 1] + suffix[i - 1] - suffix[pre[i] + 1] + a[i]);
    }
    printf("%lld\n", dp[n]);
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}