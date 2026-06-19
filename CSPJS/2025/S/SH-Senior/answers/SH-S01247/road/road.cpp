#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4+30;
const int M = 1e6+10;
const int K = 20;
int n, m, k, c[K], f[N], sz[N], ans = 1e18;

struct Edge{
    int u, v, w;
}e[M], w[K][N], now[K][M];

bool cmp(Edge x, Edge y){
    return x.w < y.w;
}

inline int find(int x){return (f[x] == x ? x : f[x] = find(f[x]));}

void dfs(int x,int cnt,int v){
    if(x == k+1){
        int ans0 = 0;
        for(int i = 1; i <= cnt; i++){
            ans0 += now[x-1][i].w;
        }
        ans = min(ans,ans0+v);
        return;
    }
    for(int i = 1; i <= n+k; i++) f[i] = i, sz[i] = 1;
    int l1 = 1, l2 = 1, cnt2 = 0;
    while(cnt2 <= cnt){
        if((l1 <= cnt && now[x-1][l1].w < w[x][l2].w) || l2 == n+1){
            int U = find(now[x-1][l1].u);
            int V = find(now[x-1][l1].v);
            ++l1;
            if(U==V)continue;
            if(f[U]<f[V])swap(U,V);
            f[V]=U;
            sz[U]+=sz[V];
            now[x][++cnt2] = now[x-1][l1-1];
        } else {
            int U = find(w[x][l2].u);
            int V = find(w[x][l2].v);
            ++l2;
            if(U==V)continue;
            if(f[U]<f[V])swap(U,V);
            f[V]=U;
            sz[U]+=sz[V];
            now[x][++cnt2] = w[x][l2-1];
        }
    }
    dfs(x+1,cnt+1,v+c[x]);
    for(int i = 1; i <= cnt; i++) now[x][i] = now[x-1][i];
    dfs(x+1,cnt,v);
}

int read(){
    char c = getchar();
    int f = 0;
    while(c < '0' || c > '9'){c = getchar();}
    while(c >= '0' && c <= '9'){
        f = (f<<3)+(f<<1)+(c-'0');
        c = getchar();
    }
    return f;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read();
    m = read();
    k = read();
    for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    for(int i = 1; i <= m; i++){
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }
    sort(e+1,e+m+1,cmp);
    int m2 = 0;
    for(int i = 1; i <= m; i++){
        int U = find(e[i].u);
        int V = find(e[i].v);
        if(U == V){
            continue;
        }
        if(sz[U] < sz[V]) swap(U,V);
        f[V] = U;
        sz[U] += sz[V];
        now[0][++m2] = e[i];
    }
    for(int i = 1; i <= k; i++){
        c[i] = read();
        for(int j = 1; j <= n; j++){
            w[i][j].w = read();
            w[i][j].v = j;
            w[i][j].u = i+n;
        }
        sort(w[i]+1,w[i]+n+1,cmp);
    }
    dfs(1,n-1,0);
    cout << ans << endl;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/