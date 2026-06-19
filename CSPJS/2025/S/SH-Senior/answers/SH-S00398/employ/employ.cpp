#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505, MOD = 998244353;

int n, m, c[MAXN];
char s[MAXN];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int cnt = 0, ans = 1;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) cnt++;
        ans = 1ll * ans * n % MOD;
    }
    printf("%d", m + cnt > n ? 0 : ans);

    return 0;
}
