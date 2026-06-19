#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], s[N], f[N];
unordered_map<int, int> g;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    // freopen("xor.err", "w", stderr);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k; g[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (g.find(s[i] ^ k) != g.end())
            f[i] = max(f[i], g[s[i] ^ k] + 1);
        g[s[i]] = max(g[s[i]], f[i]);
    }
    cout << f[n] << endl;
    return 0;
}