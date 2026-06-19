#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int MAXN = 2e5 + 10;
struct DP {int num, val;};
DP dp[MAXN];
int a[MAXN];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        dp[1]= {1, 0};
        for (int i = 2; i <= n; ++i) {
            int add1 = a[i - 1], add2 = a[dp[i - 1].num - 1];
            if (a[i] != a[i - 1]) add1 = 0;
            if (a[i] != a[dp[i - 1].num - 1]) add2 = 0;
            if (dp[i - 1].val + add1 >= dp[i - 1].val + add2) {
                dp[i].val = dp[i - 1].val + add1;
                dp[i].num = dp[i - 1].num;
                cout << " # 0\n";
            }
            else {
                dp[i].val = dp[i - 1].val + add2;
                dp[i].num = i;
                cout << " # 1\n";
            }
            // cout << "@ " << dp[i].val << "\n";
        }
        cout << dp[n].val << "\n";
    }
    return 0;
}