#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = (1<<18)+10;
int n, m, tot, dep, aa[N], T, a[N], d[N];
pair<int, int> q[N];
ll f[N][18], g[N][18];
int len, lim, lst;

void trans(int u, int dep, bool t){
    rep(i, 0, lim) f[u][i] = 0, g[u][i] = 0;
    bool flg = 0;
    int x = u<<1|t, y = u<<1|(t^1);
    rep(i, 0, dep-1) if(f[x][i] || g[x][i]) {flg = 1; break;}
    if(flg) rep(i, 0, lim) f[u][i] = f[y][i], g[u][i] = g[y][i];
    rep(i, dep, lim) f[u][i] += f[x][i], g[u][i] += g[x][i];
    rep(i, 0, dep-1) g[u][dep] += g[x][i];
}

ll solve(int n){
    if(n == 1) return 1;
    len = 1;
    while(len < n) len <<= 1;
    int l = tot + lst, r = tot + (lst<=(len>>1) ? len : n) - 1;
    // l = tot, r = tot + len - 1;
    // printf("solve: %d %d %d\n", n, l, r);
    rep(i, l, tot + n - 1){
        rep(j, 0, lim) f[i][j] = 0, g[i][j] = 0;
        f[i][min(a[i], lim)] = i-tot+1;
    }
    rep(i, tot + n, r){
        rep(j, 0, lim) f[i][j] = 0, g[i][j] = 0;
        g[i][0] = i-tot+1;
    }
    per(i, dep, 1){
        len >>= 1; l >>= 1, r >>= 1;
        // printf("solve: %d %d\n", l, r);
        rep(j, l, r) trans(j, dep-i+1, d[j]);
        if(len == 1){
            ll ret = 0; int t = 1<<(i-1);
            // if(n == 2) fprintf(stderr, "%lld\n", f[t][1]);
            rep(j, 0, lim) ret += f[t][j] + g[t][j];
            // fprintf(stderr, "%lld\n", ret);
            return ret;
        }
    }
    assert(0);
}

void solve(){
    ll ans = 0; lst = 0; ll ret = 0;
    rep(i, 1, m){
        ret = q[i].first == q[i-1].first ? ret : solve(q[i].first);
        ans ^= q[i].second * ret;
        lst = q[i].first == 1 ? 0 : q[i].first; 
        // printf("%d %lld\n", q[i].first, ret);
    }
    printf("%lld\n", ans);
}

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    tot = 1;
    while(tot < n) tot <<= 1;
    dep = __lg(tot); lim = dep;
    rep(i, tot, tot + n - 1) scanf("%d", &aa[i]);
    rep(i, 1, m) scanf("%d", &q[i].first), q[i].second = i;
    sort(q+1, q+m+1);
    per(i, dep, 1) rep(j, 1<<(i-1), (1<<i)-1){
        char c = getchar();
        while(!isdigit(c)) c = getchar();
        d[j] = c ^ 48;
    }
    int T; scanf("%d", &T); while(T--){
        static int x[4];
        scanf("%d%d%d%d", &x[0], &x[1], &x[2], &x[3]);
        rep(i, tot, tot+n-1) a[i] = aa[i] ^ x[(i-tot+1)&3];
        solve();
    }
    return 0;
}

// g++ -std=c++14 -Wall -Wextra -fsanitize=undefined -Wno-unused-result -O2 arena.cpp -o arena && ./arena