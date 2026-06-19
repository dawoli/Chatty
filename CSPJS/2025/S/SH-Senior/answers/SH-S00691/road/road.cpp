#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> edge;
vector<vector<int>> nxt;
vector<int> upg;
vector<int> dis;
const int inf = 0x3f3f3f3f;
void dij() {
    for (int i = 0; i < n + 1 + k; i++) dis.push_back(inf);
    dis[1] = 0;
    priority_queue<pair<pair<int, int>, vector<bool>>> q;
    vector<bool> initial;
    for (int i = 1; i <= n + k; i++) initial.push_back(false);
    q.push({{1, 0}, initial});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int v = p.first.first, w = p.first.second;
        vector<bool> built = p.second;
        if (w != dis[v]) continue;
        for (auto t : nxt[v]) {
            if (t > n && t <= n && dis[t] > w + edge[v][t]) dis[t] = w + edge[v][t];
            else if ((t <= n && dis[t] > w + edge[v][t])
                     || (t > n && dis[t] > w + edge[v][t] && built[t-n]))
             dis[t] = w + edge[v][t];
            else if (t > n && !built[t-n] && dis[t] > w + upg[t-n] + edge[t][v]) dis[t] = w + upg[t-n] + edge[t][v], built[t-n] = true;
            q.push({{t, dis[t]}, built});
        }
    }
}
int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i <= n + k + 1; i++) {nxt.push_back({}); }
    for (int i = 0; i <= n + k + 1; i++) {edge.push_back({}); for (int j = 0; j < n + k + 1; j++) edge[i].push_back(0);}
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u][v] = w;
        edge[v][u] = w;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        upg.push_back(x);
        for (int j = 1; j <= n; j++) {
            int y;
            cin >> y;
            edge[j][n+i] = y;
            edge[n+i][j] = y;
            nxt[j].push_back(n+i);
            nxt[n+i].push_back(j);
        }
    }
    dij();
    cout << dis[n] << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
