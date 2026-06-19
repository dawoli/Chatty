#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int P = 998244353;
using i64 = long long;
vector<int> stat[19];
int n, m, dp[2][1 << 18][19], c[18];
inline void add(int &x, int &y) {
    if ((x += y) >= P) x -= P;
}
std::string s;
inline void brute(void) {
    for (int S = 0; S < (1 << n); S++) {
        stat[__builtin_popcount(S)].push_back(S);
    }
    for (int i = 0; i < n; i++) {
        int nxt = i & 1, cur = nxt ^ 1;
        memset(dp[nxt], 0, sizeof(dp[nxt]));
        for (auto S : stat[i]) {
            for (int k = 0; k <= i; k++) {
                for (int j = 0; j < n; j++) {
                    if (S >> j & 1) continue;
                    const int T = S ^ (1 << j);
                    if (s[i] == '0' || i - k >= c[j]) {
                        add(dp[nxt][T][k], dp[cur][S][k]);
                    } else {
                        add(dp[nxt][T][k + 1], dp[cur][S][k]);
                    }
                }
            }
        }
    }
    int ans = 0, T = (1 << n) - 1;
    for (int i = m; i <= n; i++) {
        add(ans, dp[(n & 1) ^ 1][T][i]);
    }
    cout << ans << endl;
}
int main(int argc, const char *argv[]) {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> s, dp[1][0][0] = 1;
    for (int i = 0; i < n; i++) cin >> c[i];
    brute();
    return 0;
}