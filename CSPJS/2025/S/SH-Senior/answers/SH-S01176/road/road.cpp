#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
const int N = 1e4 + 15, M = 3e6;
int n, m, k, c[11], S; bool vis[N]; ll ans = LONG_LONG_MAX;
int tot, head[N], ver[M], Next[M], edge[M];
inline void add(int x, int y, int z) {//if(x==1)cerr<<"add("<<x<<","<<y<<","<<z<<")";
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; //if(x==1)cerr<<tot<<"\n";
}
inline bool chosen(int x) {
    if (1 <= x && x <= n) return 1;//return 0;
    return (S >> (x - n)) & 1;
    // return 1 <= x && x <= n || ((S >> (x - n)) & 1);
}
struct cmp {bool operator()(int x, int y) {return edge[x] > edge[y];}};
ll mst() {//cerr<<"mst:S="<<S<<":";
    memset(vis, 0, sizeof(vis));
    ll ans = 0;
    for (int i = 1; i <= k; i++) if ((S >> i) & 1) ans += c[i];
    priority_queue<int, vector<int>, cmp> q; vis[1] = 1;
         //assert(0);
    for (int i = head[1]; i; i = Next[i]) {//cerr<<i<<" ";
         if (chosen(ver[i]))
             q.push(i);
    }
    while (!q.empty()) {
        int e = q.top(), u = ver[e]; q.pop();
        if (vis[u]) continue; vis[u] = 1; //cerr<<"{e:"<<e<<",u:"<<u<<"}";
        ans += edge[e];
        for (int i = head[u]; i; i = Next[i])
            if (chosen(ver[i]) && !vis[ver[i]]) q.push(i);
    }
    //cerr<<ans<<endl;
    return ans;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //freopen("road.err", "w", stderr);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
    memset(head, 0, sizeof(head));
    memset(Next, 0, sizeof(Next));//cerr<<head[1]<<";\n";
    cin >> n >> m >> k;
    for (int u, v, w, i = 1; i <= m; i++)
        cin >> u >> v >> w, add(u, v, w), add(v, u, w);
    for (int j = 1; j <= k; j++) {
        cin >> c[j];
        for (int a, i = 1; i <= n; i++) cin >> a,
            add(i, n + j, a), add(n + j, i, a);
    }//cerr<<Next[Next[Next[Next[Next[head[1]]]]]]<<";\n";cerr<<tot<<";\n";
    for (S = 0; S < (1 << (k+1)); S += 2) {
        ans = min(ans, mst());
    }
    cout << ans << endl;
    return 0;
}
