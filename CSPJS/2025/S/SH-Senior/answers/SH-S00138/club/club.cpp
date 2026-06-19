#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
using i64 = long long;
int T, n, a[N][3], p[N][3], vis[N];
inline void solve(void) {
    cin >> n;
    long long ans = 0;
    vector<int> cnt(3, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j], p[i][j] = j;
        }
        sort(p[i], p[i] + 3, [&](int x, int y) {
            return a[i][x] > a[i][y];
        });
        cnt[p[i][0]]++;
        ans += a[i][p[i][0]];
    }
    int mj = 0, h = n / 2;
    for (int i = 0; i < 3; i++) {
        if (cnt[i] > cnt[mj]) mj = i;
    }
    if (cnt[mj] <= h) {
        cout << ans << '\n';
        return;
    }
    ans = 0;
    for (int i = 0; i < 3; i++) {
        long long cur = 0;
        vector<int> rest, req;
        for (int k = 0; k < 3; k++) {
            if (k != i) rest.push_back(k);
        } 
        for (int j = 1; j <= n; j++) {
            int v = INT_MAX;
            cur += a[j][i];
            for (auto &k : rest) {
                v = min(v, a[j][i] - a[j][k]);
            }
            req.push_back(v);
        }
        sort(req.begin(), req.end());
        for (int j = 0; j < h; j++) {
            cur -= req[j];
        }
        ans = max(ans, cur);
    } 
    cout << ans << endl;
}
inline void optimizeIO(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, const char *argv[]) {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    optimizeIO(), cin >> T;
    while (T--) solve();
    return 0;
}
