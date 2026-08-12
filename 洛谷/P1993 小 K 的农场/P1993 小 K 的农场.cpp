#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5003;

struct edge {
    int v, w;
};

vector<edge> e[MAXN];
int dis[MAXN], cnt[MAXN];
bitset<MAXN> vis;
queue<int> q;

void add_edge(const int & u, const int & v, const int & w){
    e[u].push_back({v, w});
}

int n, m, a, b, c;

bool spfa(int n, int s){
    memset(dis, 0x3f, (n + 1) * sizeof(int));
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto ed : e[u]){
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return false;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int op;
        cin >> op;
        switch (op){
        case 1:
            cin >> a >> b >> c;
            add_edge(a, b, -c);
            break;
        case 2:
            cin >> a >> b >> c;
            add_edge(b, a, c);
            break;
        case 3:
            cin >> a >> b;
            add_edge(a, b, 0);
            add_edge(b, a, 0);
        }
    }
    for (int i = 1; i <= n; i++){
        e[0].push_back({i, 0});
    }

    cout << (spfa(n, 0) ?  "Yes" :  "No");
}