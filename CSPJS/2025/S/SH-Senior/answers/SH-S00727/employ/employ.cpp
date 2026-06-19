#include <bits/stdc++.h>
#define mod 998244353LL
using namespace std;
int n, m, cnt;
long long ans;
int p[509];
int bear[509];
char s[509];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", bear + i);
        p[i] = i;
    }
    do {
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '0' || bear[p[i]] <= cnt)
                cnt++;
        }
        if(cnt <= n - m)
            ans = (ans + 1) % mod;
    } while(next_permutation(p + 1, p + n + 1));
    printf("%lld\n", ans);
    return 0;
}