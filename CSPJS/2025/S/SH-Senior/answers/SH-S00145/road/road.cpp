#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
int n, m, k, ans = 9e18, cur, cnt, c[K], a[K][N], f[N], head[N], dis[K][N], rt[K];
bool vis[K];
struct edge{
    int u, v, w;
    bool operator< (const edge &b) const{
        return w < b.w;
    }
}e[M];
int find(int x){
    if (x == f[x]){
        return x;
    }
    return f[x] = find(f[x]);
}
struct node{
    int v, nxt;
}t[N << 1];
void add(int u, int v){
    t[++cnt] = (node){v, head[u]};
    head[u] = cnt;
}
void dfs(int u, int fa, int id){
    for (int i = head[u]; i; i = t[i].nxt){
        int v = t[i].v;
        if (v == fa){
            continue;
        }
        dis[id][v] = dis[id][u] + 1;
        dfs(v, u, id);
    }
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    }
    for (int i = 1; i <= k; i++){
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j++){
            scanf("%lld", &a[i][j]);
            if (!rt[i] || a[i][j] < a[i][rt[i]]){
                rt[i] = j;
            }
        }
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
    for (int i = 1; i <= m; i++){
        int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
        if (u == v){
            continue;
        }
        f[u] = v;
        e[++cur] = e[i];
        add(e[i].u, e[i].v), add(e[i].v, e[i].u);
        // printf("%lld %lld %lld\n", e[i].u, e[i].v, e[i].w);
    }
    for (int i = 1; i <= k; i++){
        dfs(rt[i], 0, i);
    }
    int lim = (1 << k) - 1;
    for (int sta = 0; sta <= lim; sta++){
        int sum = 0;
        for (int i = 1; i <= k; i++){
            if ((sta >> (i - 1)) & 1){
                sum += c[i] + a[i][rt[i]];
                // printf("+%lld+%lld\n", c[i], a[i][rt[i]]);
                vis[i] = true;
            }
            else{
                vis[i] = false;
            }
        }
        for (int i = 1; i < n; i++){
            int u = e[i].u, v = e[i].v, w = e[i].w;
            for (int j = 1; j <= k; j++){
                if (!vis[j]){
                    continue;
                }
                if (dis[j][u] < dis[j][v]){
                    w = min(w, a[j][v]);
                }
                else{
                    w = min(w, a[j][u]);
                }
            }
            sum += w;
            // printf("+%lld\n", w);
        }
        ans = min(ans, sum);
        // printf("sta=%lld:sum=%lld\n", sta, sum);
    }
    printf("%lld\n", ans);
}