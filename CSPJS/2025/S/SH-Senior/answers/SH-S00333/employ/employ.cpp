#include <iostream>
#include <fstream>
using namespace std;

#define FILE_IO "employ"
#ifdef FILE_IO
ifstream fin(FILE_IO ".in");
ofstream fout(FILE_IO ".out");
#define cin fin
#define cout fout
#endif

#define int long long

#define rep(a, b, c) for (int a = (b), _ = (c); a <= _; a++)
#define rrep(a, b, c) for (int a = (b), _ = (c); a >= _; a--)

const int N = 505;
const int mod = 998244353;

int n, m;
int s[N], c[N];
int ans = 0;

namespace bl {
    int rec[N];
    bool flg[N];
    void dfs(int idx) {
        if (idx > n) {
            int suc, cnt;
            suc = cnt = 0;
            rep(i, 1, n) {
                if (cnt >= c[rec[i]] || !s[i]) cnt++;
                else suc++;
            }
            if (suc >= m) ans++;
        }
        rep(i,1, n) {
            if (flg[i]) continue;
            flg[i] = 1;
            rec[idx] = i;
            dfs(idx + 1);
            flg[i] = 0;
        }
    }
    inline void solve() {
        dfs(1);
        cout << ans;
    }
}

namespace sp {
    inline void solve() {
        int ans = 1;
        rep(i, 1, n) {
            ans = ans * i % mod;
        }
        cout << ans;
    }
}

signed main() {
    cin >> n >> m;
    string tmp; cin >> tmp;
    int mins = 1;
    rep(i, 1, n) {
        s[i] = tmp[i - 1] - '0';
        mins = min(mins, s[i]);
    }
    rep(i, 1, n) cin >> c[i];
    bl::solve();
}