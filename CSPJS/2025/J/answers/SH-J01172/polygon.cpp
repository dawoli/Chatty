#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n, a[N], b[N], f[N], s[N], ans;
int qpow2(int x) {
    if (x <= 1) return 1 << x;
    long long m = qpow2(x / 2), n = qpow2(x % 2);
    return m * m % mod * n % mod;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    // freopen("polygon.err", "w", stderr);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]]++;
    sort(a + 1, a + n + 1, greater<int>());
    f[0] = s[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = a[1]; j >= a[i]; j--) (f[j] += f[j - a[i]]) %= mod;
    for (int j = 1; j <= a[1]; j++) (s[j] = s[j - 1] + f[j]) %= mod;
    for (int rest = n, i = a[1]; i >= 1; i--)
        for (int j = 1; j <= b[i]; j++)
            (ans += qpow2(--rest) - s[i] + j) %= mod;
    cout << ans << endl;
    return 0;
}