#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, r[100010], cnt[100010], ans;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &r[i]);
        cnt[r[i]]++;
    }
    for(int i = 1; i <= 100000; ++i) {
        if(cnt[i] == 0) continue;
        if(ans <= cnt[i]) ans = 0;
        else ans -= cnt[i];
        ans += cnt[i];
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}