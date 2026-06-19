//road
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
typedef long long ll;
int n, m, K;
ll C[15], A[15][N];
struct edge{
    int u, v;
    ll w;
} eg[M], a[M];
bool cmp(edge x, edge y){
    return x.w < y.w;
}

int fa[N];
int gf(int x){
    return x == fa[x] ? x : fa[x] = gf(fa[x]);
}

ll ans;
pair<ll, int> rd[15][N];

int read(){
    int x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // srand(time(0));
    // scanf("%d%d%d", &n, &m, &K);
    n = read();
    m = read();
    K = read();
    // printf("%d %d %d\n", n, m, K);
    for(int i = 1; i <= m; ++ i){
        // eg[i].u = i < n ? 1 : rand() % n + 1;
        // eg[i].v = i < n ? i + 1 : rand() % n + 1;
        // eg[i].w = rand();
        // printf("%d %d %lld\n", eg[i].u, eg[i].v, eg[i].w);
        // scanf("%d%d%lld", &eg[i].u, &eg[i].v, &eg[i].w);
        eg[i].u = read();
        eg[i].v = read();
        eg[i].w = read();
    }
    sort(eg + 1, eg + m + 1, cmp);
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    for(int i = 1; i <= m; ++ i){
        int u = eg[i].u, v = eg[i].v;
        ll w = eg[i].w;
        if(gf(u) != gf(v)){
            a[++cnt] = eg[i];
            fa[gf(u)] = gf(v);
        }
    }
    for(int i = 1; i <= K; ++ i){
        // scanf("%lld", &C[i]);
        C[i] = read();
        // // C[i] = rand();
        // printf("%lld ", C[i]);
        for(int j = 1; j <= n; ++ j){
            // scanf("%lld", &A[i][j]);
            A[i][j] = read();
            // A[i][j] = rand();
            // printf("%lld ", A[i][j]);
            rd[i][j] = make_pair(A[i][j], j);
        }
        // puts("");
        sort(rd[i] + 1, rd[i] + n + 1);
    }
    ans = 1e18;
    int xb[15];
    for(int S = 0; S < (1 << K); ++ S){
        ll tmp = 0;
        xb[0] = 1;
        for(int i = 1; i <= K; ++ i){
            if(S & (1 << (i - 1))){
                tmp += C[i];
                xb[i] = 1;
            } else {
                xb[i] = n + 1;
            }
        }
        for(int i = 1; i <= n + K; ++ i){
            fa[i] = i;
        }
        // printf("%d %lld\n", S, tmp);
        while(true){
            while(xb[0] <= n - 1 && gf(a[xb[0]].u) == gf(a[xb[0]].v)){
                // printf("ban %d %d\n", a[xb[0]].u, a[xb[0]].v);
                ++ xb[0];
            }
            for(int i = 1; i <= K; ++ i){
                while(xb[i] <= n && gf(rd[i][xb[i]].second) == gf(n + i)){
                    ++ xb[i];
                }
            }
            pair<ll, pair<int, int> > nx = make_pair(2e9, make_pair(0, 0));
            if(xb[0] <= n - 1){
                nx = min(nx, make_pair(a[xb[0]].w, make_pair(a[xb[0]].u, a[xb[0]].v)));
            }
            for(int i = 1; i <= K; ++ i){
                if(xb[i] <= n){
                    nx = min(nx, make_pair(rd[i][xb[i]].first, make_pair(rd[i][xb[i]].second, n + i)));
                }
            }
            if(nx.first == 2e9){
                break;
            }
            tmp += nx.first;
            if(tmp > ans){
                break;
            }
            // printf("%lld %d %d\n", nx.first, nx.second.first, nx.second.second);
            // printf("--- %d %d %d\n", xb[0], xb[1], xb[2]);
            fa[gf(nx.second.first)] = gf(nx.second.second);
            if(nx.second.second <= n){
                ++ xb[0];
            } else {
                ++ xb[nx.second.second - n];
            }
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
    return 0;
}