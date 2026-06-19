//arena
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int n, m, K, T, a[N], c[N];
ll ans[N], tmp;
int rs[20][N], ded[20][N];
char s[20][N];
int bit[N];

void del(int r, int g){
    if(ded[r][g]) return;
    ded[r][g] = 1;
    if(r == 0){
        bit[g] = 0;
    } else {
        del(r-1, g+g-1);
        del(r-1, g+g);
    }
}
ll solve(){
    for(int i = 1; i <= (1 << K); ++ i){
        rs[0][i] = i;
        ded[0][i] = 0;
        bit[i] = i;
    }
    for(int j = 1; j <= K; ++ j){
        for(int k = 1; k <= (1 << (K - j)); ++ k){
            ded[j][k] = 0;
            rs[j][k] = 0;
        }
    }
    tmp = 0;
    ll sum = 1;
    int nw = 1, tk = K;
    for(int i = 1; i <= n; ++ i){
        if(nw < i){
            for(int j = nw + 1; j <= nw * 2; ++ j){
                sum += j;
            }
            nw *= 2;
            // ++ tk;
        }
        int x = 1, pos = i;
        // printf("%d %d %d\n", K, i, a[i]);
        while(x <= tk){
            int p = ((pos - 1) >> (x - 1)) & 1;
            int g = ((pos - 1) >> x) + 1;
            // if(i == 15){
                // printf("%d %d %d\n", x, p, g);
            // }
            if(ded[x][g]) break;
            if(p == 0 && s[x][g] == '1'){
                break;
                // pos = rs[x][g];
            } else if(p == 0 || s[x][g] == '1'){
                // puts("1234");
                if(a[pos] < x){
                    // printf("%d %d\n", pos, a[pos]);
                    // rs[x][g] = ((pos - 1) ^ 1) + 1;
                    if(p == 0){
                        rs[x][g] = rs[x-1][g+g];
                        // del(x-1, g+g-1);
                        break;
                        // pos = rs[x][g];
                    } else {
                        rs[x][g] = rs[x-1][g+g-1];
                        del(x-1, g+g);
                        // puts("1234");
                        // printf("%d\n", rs[x][g]);
                        pos = rs[x][g];
                    }
                    // break;
                } else {
                    // if(i == 5) printf("%d %d\n", x, g);
                    // rs[x][g] = pos;
                    if(p == 0){
                        // puts("1234");
                        rs[x][g] = rs[x-1][g+g-1];
                        del(x-1, g+g);
                    } else {
                        rs[x][g] = rs[x-1][g+g];
                        del(x-1, g+g-1);
                    }
                }
            } else if(!rs[x][g]){
                if(a[rs[x-1][g+g-1]] < x){
                    del(x-1, g+g-1);
                    rs[x][g] = rs[x-1][g+g];
                } else {
                    del(x-1, g+g);
                    rs[x][g] = rs[x-1][g+g-1];
                    pos = rs[x][g];
                }
                // rs[x][g] = rs[x-1][g+g];
                // del(x-1, g+g-1);
            }// else break;
            ++ x;
        }
        ans[i] = 0;
        for(int j = 1; j <= nw; ++ j) ans[i] += bit[j];
        // for(int j = 1; j <= nw; ++ j) printf("%d ", bit[j]);
        // ans[i] = - tmp + sum;
        // cerr << ans[i] << '\n';
        // printf("%d %lld\n", i, ans[i]);
        // for(int j = 0; j <= K; ++ j){
        //     for(int k = 1; k <= (1 << (K - j)); ++ k){
        //         printf("%d ", rs[j][k]);
        //     } puts("");
        // }
        // printf("%lld\n", tmp);
        // puts("-----");
    }
    ll tt = 0;
    for(int i = 1; i <= m; ++ i){
        tt ^= i * ans[c[i]];
    }
    // cerr << tt << '\n';
    return tt;
}

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d", &c[i]);
    }
    while((1ll << K) < n){
        ++ K;
    }
    for(int i = 1; i <= K; ++ i){
        scanf("%s", s[i] + 1);
    }
    scanf("%d", &T);
    for(int i = 1; i <= T; ++ i){
        int x[4];
        scanf("%d%d%d%d", &x[0], &x[1], &x[2], &x[3]);
        for(int j = 1; j <= n; ++ j){
            a[j] ^= x[j&3];
        }
        printf("%lld\n", solve());
        for(int j = 1; j <= n; ++ j){
            a[j] ^= x[j&3];
        }
    }
    return 0;
}