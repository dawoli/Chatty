#include <bits/stdc++.h>
using namespace std;
int t, n;
multiset <int> cnt[9];
long long ans;
long long a[100009][9], cura[100009], curb[100009];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        ans = 0;
        cnt[1].clear();
        cnt[2].clear();
        cnt[3].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%lld %lld %lld", a[i] + 1, a[i] + 2, a[i] + 3);
            cura[i] = max(a[i][1], max(a[i][2], a[i][3]));
            ans += cura[i];
            if(a[i][1] == cura[i])
                cnt[1].insert(a[i][1] - max(a[i][2], a[i][3]));
            else if(a[i][2] == cura[i])
                cnt[2].insert(a[i][2] - max(a[i][1], a[i][3]));
            else
                cnt[3].insert(a[i][3] - max(a[i][1], a[i][2]));
        }
        while(cnt[1].size() > n / 2) {
            ans -= (*cnt[1].begin());
            cnt[1].erase(cnt[1].begin());
        }
        while(cnt[2].size() > n / 2) {
            ans -= (*cnt[2].begin());
            cnt[2].erase(cnt[2].begin());
        }
        while(cnt[3].size() > n / 2) {
            ans -= (*cnt[3].begin());
            cnt[3].erase(cnt[3].begin());
        }
        printf("%lld\n", ans);
    }
    return 0;
}