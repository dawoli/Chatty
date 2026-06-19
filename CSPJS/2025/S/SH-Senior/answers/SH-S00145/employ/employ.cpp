#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int N = 5e2 + 5, mod = 998244353;
int n, m, c[N], pos[N], fac[N];
char s[N];
void init(){
    fac[0] = 1ll;
    for (int i = 1; i < N; i++){
        fac[i] = fac[i - 1] * i % mod;
    }
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    init();
    scanf("%lld%lld", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &c[i]);
    }
    if (n <= 10){
        for (int i = 1; i <= n; i++){
            pos[i] = i;
        }
        int ans = 0;
        do{
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                if (cnt >= c[pos[i]]){
                    cnt++;
                }
                else if (s[i] == '0'){
                    cnt++;
                }
            }
            if (n - cnt >= m){
                ans++;
            }
        } while (next_permutation(pos + 1, pos + n + 1));
        printf("%lld\n", ans);
        return 0;
    }
}