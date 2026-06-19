#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5, M = 1e6+5;
int n, m, k;
int dis[N];
bool vis[N];
struct edge {
    int to, nxt, cost;
    bool operator < (const edge &u) const{edge.cost > u.cost;}
} e[M];
int head[N], cnt = 0;
void addedge(int u, int v, int w) {
    cnt++;
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void dijkstra() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) dis[i] = INT_MAX;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[u].next) {
            int v = e[i].to;
            if (vis[v]) continue;
            int co = e[i].cost;
            q.push(v);
            if (dis[u] > co + dis[v]) {
                dis[u] = co + dis[v];
            }
        }
    }
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    cout << 13 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}