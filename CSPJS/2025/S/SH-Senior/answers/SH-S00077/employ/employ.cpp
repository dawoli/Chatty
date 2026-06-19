#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 998244353, MAXN = 507;
int a[MAXN];
LL level(int n) {
    LL ans = 1;
    for (int i = n; i >= 1; i--) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ct = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // if (!a[i]) ++ct;
    }
    LL ans = level(n);
    ans %= MOD;
    cout << ans;
    return 0;
}