#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
#define mp make_pair
#define f first
#define s second

#define vt vector
using vi = vt<int>;
using vb = vt<bool>;
using vl = vt<ll>;
using vd = vt<ld>;
using vs = vt<str>;
using vpi = vt<pi>;
using vpl = vt<pl>;
using vpd = vt<pd>;
#define sz(x) (int)(x).size()
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rs resize
#define is insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(x, a) for (auto& x : a)

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int d4i[]{-1, 0, 1, 0}, d4j[]{0, 1, 0, -1};
const int d8i[]{-1, -1, 0, 1, 1, 1, 0, -1}, d8j[]{0, 1, 1, 1, 0, -1, -1, -1};

const int cnt[10]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int ans[10]{-1, 1, 7, 4, 2, 6, 8, 10, 18, 22};

void solve() {
    int n;
    cin >> n;

    if (n % 7 == 0 && n >= 100) {
        cout << str(n / 7, '8') << "\n";
        return;
    }

    if (n % 7 == 1 && n >= 100) {
        cout << "10" + str(n / 7 - 1, '8') << "\n";
        return;
    }
    
    if (n <= 10) {
        cout << ans[n - 1] << "\n";
        return;
    }

    vs dp(8, "-1");
    dp.ft = "";
    FOR(i, 1, 7) {
        F0R(j, 10) {
            if (i - cnt[j] >= 0 && dp[i - cnt[j]] != "-1") {
                str ss = dp[i - cnt[j]];
                ss += '0' + j;
                if (ss.ft != '0' && (dp[i] == "-1" || sz(ss) < sz(dp[i]) || sz(ss) == sz(dp[i]) && ss < dp[i])) {
                    dp[i] = ss;
                }
            }
        }
    }
    n -= 6;
    while (n--) {
        F0R(i, 10) {
            if (dp[7 - cnt[i]] != "-1") {
                str ss = dp[7 - cnt[i]];
                ss += '0' + i;
                if (ss.ft != '0' && (dp[7] == "-1" || sz(ss) < sz(dp[7]) || sz(ss) == sz(dp[7]) && ss < dp[7])) {
                    dp[7] = ss;
                }
            }
        }
        F0R(i, 7) {
            dp[i] = dp[i + 1];
        }
        dp[7] = "-1";
    }
    cout << dp[6] << "\n";
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}