#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

#define FILE_IO "road"
#ifdef FILE_IO
ifstream fin(FILE_IO ".in");
ofstream fout(FILE_IO ".out");
#define cin fin
#define cout fout
#endif

#define int long long

#define rep(a, b, c) for (int a = (b), _ = (c); a <= _; a++)
#define rrep(a, b, c) for (int a = (b), _ = (c); a >= _; a--)

const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 10 + 5;
const int INF = 1e15;

struct node {
    int v, w;
    node () { }
    node (int _v, int _w) {
        v = _v; w = _w;
    }
    inline bool operator > (const node & r) const {
        return w > r.w;
    }
};

int n, m, k;
vector<node> gra[N + K];
int c[K], a[K][N];

bool vis[K + N];

namespace sp {
    inline void solve() {
        rep(i, 1, k) {
            rep(j, 1, n) {
                gra[i + n].push_back(node(j, a[i][j]));
                gra[j].push_back(node(i + n, a[i][j]));
            }
        }
        priority_queue<node, vector<node>, greater<node>> que;
        int ans = 0;
        que.push(node(1, 0));
        while (!que.empty()) {
            node cur = que.top(); que.pop();
            int u = cur.v, val = cur.w;
            if (vis[u]) continue;
            vis[u] = 1; ans += val;
            for (node i : gra[u]) {
                int v = i.v, w = i.w;
                if (vis[v]) continue;
                que.push(node(v, w));
            }
        }
        cout << ans;
        return;
    }
}

namespace bl {
    bool ban[N + K];
    int dis[N + K];
    inline int cal() {
        rep(i, 1, n + k) {
            vis[i] = 0;
            dis[i] = INF;
        }
        priority_queue<node, vector<node>, greater<node>> que;
        int ans = 0;
        que.push(node(1, 0));
        while (!que.empty()) {
            node cur = que.top(); que.pop();
            int u = cur.v, val = cur.w;
            if (vis[u]) continue;
            vis[u] = 1; ans += val;
            // cout << "# " << u << " " << val << endl;
            for (node i : gra[u]) {
                int v = i.v, w = i.w;
                if (vis[v]) continue;
                if (ban[v]) continue;
                if (dis[v] <= w) continue;
                dis[v] = w;
                que.push(node(v, w));
            }
        }
        return ans;
    }
    inline void solve() {
        rep(i, 1, k) {
            rep(j, 1, n) {
                gra[i + n].push_back(node(j, a[i][j]));
                gra[j].push_back(node(i + n, a[i][j]));
            }
        }
        int ans = INF;
        rep(i, 0, (1 << k) - 1) {
            int cur = 0;
            rep(j, 1, k) {
                if (i & (1 << (j - 1))) {
                    ban[n + j] = 1;
                } else {
                    ban[n + j] = 0;
                    cur += c[j];
                }
            }
            if (cur >= ans) continue;
            ans = min(ans, cal() + cur);
            // cout << ans << " " << i << endl;
        }
        cout << ans;
    }
}

signed main() {
    cin >> n >> m >> k;
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        gra[u].push_back(node(v, w));
        gra[v].push_back(node(u, w));
    }
    int maxc = 0;
    rep(i, 1, k) {
        cin >> c[i];
        maxc = max(maxc, c[i]);
        rep(j, 1, n) cin >> a[i][j];
    }
    if (maxc == 0) {
        sp::solve();
    } else {
        bl::solve();
    }
}