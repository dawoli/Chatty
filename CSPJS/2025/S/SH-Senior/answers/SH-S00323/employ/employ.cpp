//employ
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, m;
char s[N];
int c[N*2];
int a[N*2];
typedef long long ll;
const ll P = 998244353;
ll C[N][N], fac[N];

namespace solveA{
    ll f[N][N];
    int cc[N];
    int main(){
        for(int i = 1; i <= n; ++ i){
            ++ cc[c[i]];
        }
        if(!cc[0]){
            printf("%lld\n", fac[n]);
            return 0;
        }
        f[0][1] = 1;
        int cnt = cc[0];
        ll ans = 0;
        for(int i = 1; i <= n; ++ i){
            for(int j = 0; j <= cnt; ++ j){
                for(int k = 0; k <= cc[i]; ++ k){
                    for(int l = j+k+1; l <= j+cc[i]; ++ l){
                        f[i][l] = (f[i][l] + f[i-1][j] * C[j+k-1][j-1] % P * C[j+cc[i]-k][cc[i]-k-1]) % P;
                    }
                }
                if(j < cnt){
                    f[i][j+cc[i]+1] = (f[i][j+cc[i]+1] + f[i-1][j] * C[j+cc[i]-1][j-1]) % P;
                }
            }
            // for(int j = 0; j <= cnt + cc[i]; ++ j){
            //     printf("%d %d %lld\n", i,j, f[i][j]);
            // }
            if(i <= n - m){
                // for(int j = 0; j <= cnt; ++ j){
                    int j = cnt;
                    ll val = f[i-1][j] * C[j+cc[i]-1][cc[i]] % P;
                    ans = (ans + val * C[n][cnt+cc[i]]) % P;
                // }
            }
            cnt += cc[i];
        }
        for(int i = 0; i <= n; ++ i){
            ans = ans * fac[cc[i]] % P;
        }
        printf("%lld\n", ans);
        return 0;
    }
}
namespace solve15{
    int main(){
        for(int i = 1; i <= n; ++ i){
            if(s[i] == '0'){
                puts("0");
                return 0;
            }
            if(c[i] == 0){
                puts("0");
                return 0;
            }
        }
        printf("%lld\n", fac[n]);
        return 0;
    }
}
namespace solve1214{
    int cc[N], ss[N];
    int main(){
        ll ans = 1;
        for(int i = 1; i <= n; ++ i){
            ++ cc[c[i]];
        }
        for(int i = 1; i <= n; ++ i){
            cc[i] += cc[i-1];
        }
        int f = 0;
        for(int i = 1; i <= n; ++ i){
            if(s[i] == '1'){
                ans = ans * (cc[i-1] - f) % P;
                ++ f;
            } else {
                
            }
        }
        ans = ans * fac[n-f] % P;
        ans = (fac[n] + P - ans) % P;
        printf("%lld\n", ans);
        return 0;
    }
}

namespace solvebf{
    ll f[1<<18][20];
    int main(){
        f[0][0] = 1;
        for(int S = 1; S < (1 << n); ++ S){
            for(int t = 0; t < n; ++ t){
                for(int i = 1; i <= n; ++ i){
                    if(S & (1 << (i - 1))){
                        int T = S ^ (1 << (i - 1));
                        int pos = __builtin_popcount(S);
                        if(s[pos] == '0' || c[i] <= t){
                            f[S][t+1] = (f[S][t+1] + f[T][t]) % P;
                        } else {
                            f[S][t] = (f[S][t] + f[T][t]) % P;
                        }
                    }
                }
            }
            // for(int t = 0; t <= n; ++ t){
            //     printf("%d %d %lld\n", S, t, f[S][t]);
            // }
        }
        ll ans = 0;
        for(int i = m; i <= n; ++ i){
            ans = (ans + f[(1<<n)-1][n-i]) % P;
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    bool flg = 1;
    C[0][0] = fac[0] = 1;
    for(int i = 1; i <= n; ++ i){
        C[i][0] = 1;
        fac[i] = fac[i-1] * i % P;
        for(int j = 1; j <= i; ++ j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
        }
        if(s[i] == '0'){
            flg = 0;
        }
        scanf("%d", &c[i]);
    }
    if(m == n){
        solve15::main();
    } else if(m == 1){
        solve1214::main();
    } else if(n <= 18){
        solvebf::main();
    } else if(flg){
        solveA::main();
    }
    return 0;
}