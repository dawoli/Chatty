#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int read() {
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int MAXN = 1e4 + 5;
const int MAXM = 1e6 + 5;
const int MAXK = 10;
int n, m, k, fa[MAXN + MAXK], sz[MAXN + MAXK];
long long ans;
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {};
};
vector<Edge> edges;

int find(int x) {
    while (fa[x] != fa[fa[x]]) {
        fa[x] = fa[fa[x]];
    }
    return fa[x];
}

void uni(int x, int y) {
    if (find(x) != find(y)) {
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        sz[y] = x;
    }
}

void MST() {
    for (int i = 1; i <= n + k; ++i) fa[i] = i;
    for (int i = 1; i <= n + k; ++i) sz[i] = 1;
    auto qwq = edges; ans = 0;
    sort(qwq.begin() + 1, qwq.end(), [](Edge& a, Edge& b){return a.weight < b.weight;});
    for (int i = 1; i <= n + k; ++i) {
        if (find(qwq[i].from) != find(qwq[i].to)) {
            ans += qwq[i].weight;
            uni(qwq[i].from, qwq[i].to);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(); m = read(); k = read();
    edges.reserve(n + k);
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        u = read(); v = read(); w = read();
        edges.push_back(Edge(u, v, w));
    }
    for (int i = 1; i <= k; ++i) {
        int cost = read();
        for (int j = 1; j <= n; ++j) {
            w = read();
            edges.push_back(Edge(n + i, j, w));
        }
    }

    MST();

    cout << ans << '\n';
}