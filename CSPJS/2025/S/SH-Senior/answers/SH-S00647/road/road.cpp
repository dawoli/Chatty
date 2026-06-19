#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
#define maxn 12345
#define maxm 1234567
lint n, m, k, p = 0, vst[maxn], ans = 0;
struct edge{
    lint v, w;
    edge(){}
    edge(lint av, lint aw){
        v = av; w = aw;
    }
};
struct edgeo{
    lint u, v, w;
    edgeo(){}
    edgeo(lint au, lint av, lint aw){
        u = au; v = av; w = aw;
    }
} b[maxm];
bool cmp(edgeo x, edgeo y){
    return x.w < y.w;
}
vector<edge> a[maxn];
void bEdge(int bu, int bv, int bw){
    a[bu].push_back(edge(bv, bw));
    a[bv].push_back(edge(bu, bw));
    b[p] = edgeo(bu, bv, bw);
    p++;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(lint i = 0; i < m; i++){
        lint u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        bEdge(u, v, w);
    }
    for(lint i = 0; i < k; i++){
        lint c, ca;
        cin >> c; // c == 0
        for(lint j = 0; j < n; j++){
            cin >> ca;
            bEdge(i + n, j, ca);
        }
    }
    cerr << p << endl;
    sort(b, b + p, cmp);
    for(lint i = 0; i < p; i++){
        cout << b[i].u << ' ' << b[i].v << ' ' << b[i].w << '\n';
    }
    for(lint i = 0; i < p; i++){
        if(! (vst[b[i].u] && vst[b[i].v]) ){
            vst[b[i].u] = 1; vst[b[i].v] = 1;
            ans += b[i].w;
        }
    }
    cerr << endl;
    cout << ans << endl;
    return 0;
}