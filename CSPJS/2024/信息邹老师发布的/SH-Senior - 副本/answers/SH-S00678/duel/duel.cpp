#include <bits/stdc++.h>
using namespace std;
int n, x, ans;
int cnt[100009];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for(int i = 1; i <= 100000; i++) {
        if(ans <= cnt[i])
            ans = cnt[i];
    }
    printf("%d\n", ans);
    return 0;
}