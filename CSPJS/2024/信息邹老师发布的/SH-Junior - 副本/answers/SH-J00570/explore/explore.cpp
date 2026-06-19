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
const int d4i[]{0, 1, 0, -1}, d4j[]{1, 0, -1, 0};
// const int d8i[]{-1, -1, 0, 1, 1, 1, 0, -1}, d8j[]{0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
    int n, m, k, x, y, d;
    cin >> n >> m >> k >> x >> y >> d;
    --x;
    --y;
    vs s(n);
    each(i, s) {
        cin >> i;
    }
    set<pi> vis{{x, y}};
    while (k--) {
        int dx = x + d4i[d], dy = y + d4j[d];
        if (0 <= dx && dx < n && 0 <= dy && dy < m && s[dx][dy] == '.') {
            x = dx;
            y = dy;
            vis.is({x, y});
        } else {
            (++d) %= 4;
        }
    }
    cout << sz(vis) << "\n";
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}