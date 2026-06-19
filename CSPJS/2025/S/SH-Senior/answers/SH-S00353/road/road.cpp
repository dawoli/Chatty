#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e4+15, MAXM=1e6+5, INF=1e18;
int n, m, k;
int c[15];
int ans;
struct edge {int to, val;};
vector<edge> G[MAXN];
struct node {
    int dis, to;
    friend bool operator > (const node &x, const node &y) {
        return x.dis>y.dis;
    }
};

int dis[MAXN], vis[MAXN], mst;
priority_queue<node, vector<node>, greater<node> > q;
void init() {
    mst=0;
    for (int i=1; i<=n; i++) vis[i]=false;
    for (int i=1; i<=n+k; i++) dis[i]=0x3f3f3f3f3f3f3f3f;
}
int kruskal(int state) {
    init();
    for (int i=1; i<=k; i++) {
        if (state&1) vis[i+n]=true;
        else {mst+=c[i]; vis[i+n]=false;}
        state>>=1;
    }
//    printf("mst=%lld\n", mst);
//    for (int i=1; i<=k; i++) printf("vis[%lld]=%lld\n", i, vis[i]);
    dis[1]=0;
    q.push((node){0, 1});
    while (!q.empty()) {
        int u=q.top().to;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        mst+=dis[u];
        for (edge i:G[u]) {
            int v=i.to, w=i.val;
            if (vis[v]) continue;
            if (dis[v]>w) {
                dis[v]=w;
                q.push((node){dis[v], v});
            }
        }
    }
    return mst;
}
bool flag;
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back((edge){v, w});
        G[v].push_back((edge){u, w});
    }
    for (int i=1; i<=k; i++) {
        cin >> c[i];
        if (c[i]!=0) flag=true;
        int h=i+n;//id of town_i
        for (int j=1; j<=n; j++) {
            int a;
            cin >> a;
            G[h].push_back((edge){j, a});
            G[j].push_back((edge){h, a});
        }
    }
    if (flag) {
        ans=INF;
        for (int i=0; i<(1<<k); i++)
            ans=min(ans, kruskal(i));
        cout << ans;
    }
    else {
        ans=kruskal(0);
        cout << ans;
    }
    return 0;
}
