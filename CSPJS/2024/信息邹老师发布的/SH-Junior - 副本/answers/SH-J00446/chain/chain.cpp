#include<bits/stdc++.h>
using namespace std;

struct edge {
    int v;
    int id;
};

int n, k, q;
vector<int> a[100005];
vector<edge> G[200005];
int r, c;

bool dfs(int n, int step, int eid) {
    bool ret = 0;
    if(step == r + 1) return n == c;
    for(auto [v, id] : G[n]) {
        if(id != eid) ret |= dfs(v, step + 1, id);
        if(ret) break;
    }
    return ret;
}

void Main() {
    for(int i = 0; i <= 100002; i++)
        a[i].resize(0);
    for(int i = 0; i <= 200002; i++)
        G[i].resize(0);
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for(int j = 1; j <= l; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        for(int j = 0; j < l; j++)
            for(int s = j + 1; s <= min(l - 1, j + k - 1); s++)
                G[a[i][j]].push_back({a[i][s], i});
    }
    /*
    for(int i = 1; i <= 6; i++)
        for(auto[v, id] : G[i])
            cout << i << " " << v << " " << id << endl;
    */
    while(q--) {
        cin >> r >> c;
        cout << int(dfs(1, 1, -1)) << endl;
    }
    return ;
}

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int Q;
    cin >> Q;
    while(Q--)
        Main();
    return 0;
}
