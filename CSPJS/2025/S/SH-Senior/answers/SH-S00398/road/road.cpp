#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10015, MAXM = 1000005;

int n, m, k, c[12], a[12][MAXN];

struct edge {
    int u;
    int v;
    int w;
}g[MAXM], mst[MAXM];

bool operator < (const edge& e1, const edge& e2) {
	return e1.w < e2.w;
}

struct ufs {
    int rt[MAXN];
    int sz[MAXN];

    void initialize(int x) {
        for (int i = 1; i <= x; i++) {
            rt[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (x == rt[x]) return x;
        return rt[x] = find(rt[x]);
    }

    void add(int u, int v) {
        int ur = find(u), vr = find(v);
        if (sz[ur] > sz[vr]) swap(ur, vr);
        rt[ur] = vr;
        sz[vr] += sz[ur];
    }
}s;

long long ans;
int cnt;
bool leg[MAXN];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    }
    sort(g + 1, g + m + 1);
    s.initialize(n);
    for (int i = 1, u, v; i <= m; i++) {
        if (cnt == n - 1) break;
        u = g[i].u;
        v = g[i].v;
        if (s.find(u) == s.find(v)) continue;
        s.add(u, v);
        mst[++cnt] = g[i];
        ans = ans + g[i].w;
    }
    long long t;
    for (int i = 1; i <= n; i++) leg[i] = true;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++)
            mst[++cnt] = {n + i, j, a[i][j]};
    }
    sort(mst + 1, mst + cnt + 1);
    for (int i = 1, vcnt; i < (1 << k); i++) {
        t = 0;
        vcnt = n;
        for (int j = 1; j <= k; j++) {
            if ((i >> (j - 1)) & 1) {
                t = t + c[j];
                vcnt++;
                leg[n + j] = true;
            } else leg[n + j] = false;
        }
        s.initialize(vcnt);
        for (int j = 1, u, v, ecnt = 0; j <= cnt; j++) {
            if (ecnt == vcnt - 1) break;
            u = mst[j].u;
            v = mst[j].v;
            if (!(leg[u] && leg[v])) continue;
            if (s.find(u) == s.find(v)) continue;
            s.add(u, v);
            t = t + mst[j].w;
            ecnt++;
        }
        ans = min(ans, t);
    }
    printf("%lld", ans);

	return 0;
}
