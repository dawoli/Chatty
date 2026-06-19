#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 1e5+7;
// map<int, int> arthur, mal, saito;
bitset<MAXN> used1, used2, used3;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> cobb, robert, eames,;
        for (int i = 0, x, y, z; i < n; i++) {
            scanf("%d%d%d", &x, &y, &z);
            cobb.push_back(x);
        }
        sort(cobb.begin(), cobb.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < n/2; i++) ans += cobb[i];
        printf("%d\n", ans);
    }
    return 0;
}