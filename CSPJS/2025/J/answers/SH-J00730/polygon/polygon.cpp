#include <bits/stdc++.h>
#define mod 998244353LL
using namespace std;
int n;
long long ans, cur, curall;
int a[5009];
long long cntsum[5009];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    cntsum[0] = 1;
    curall = 1;
    for(int i = 1; i <= n; i++) {
        ans = (ans + curall) % mod;
        for(int j = 0; j <= a[i]; j++) {
            ans = (ans + mod - cntsum[j]) % mod;   
        }
        for(int j = 5000 - a[i]; j >= 0; j--) {
            cntsum[j + a[i]] = (cntsum[j + a[i]] + cntsum[j]) % mod;
        }
        curall = (curall * 2) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}