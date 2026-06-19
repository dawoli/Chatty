#include <bits/stdc++.h>
#define lli long long int
#define ld long double
#define mem0(x) memset((x), 0, sizeof(x))
using namespace std;
const int MAXn = 1e5 + 9;
lli v0[MAXn], beg[MAXn], a[MAXn];
bool cs[MAXn]; int rule;
bool can[MAXn];

bool ifcs(int i, int pbeg) {
    if(beg[i] > pbeg) return false;
    return !(rule * rule >= v0[i] * v0[i] + 2 * a[i] * (pbeg - beg[i]));
}

int main() {=
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++) {
        mem0(cs);
        int n, m, l;
        scanf("%d%d%d%d", &n, &m, &l, &rule);
        for(int i = 1; i <= n; i ++) {
            scanf("%lld%lld%lld", &beg[i], &v0[i], &a[i]);
        }
        int ncs = 0, ans = 0;
        bool aallcan = false;
        for(int p = 1; p <= m; p ++) {
            int pbeg;
            scanf("%d", &pbeg);
            bool nowcan = false;
            bool allcan = true;
            for(int i = 1; i <= n; i ++)
                if(ifcs(i, pbeg)) {
                    nowcan = true;
                    if(!cs[i]) ncs ++, cs[i] = true;
                } else allcan = false;
            if(!nowcan) { ans ++; can[p] = true; }
            if(allcan) aallcan = true;
        }
        if(aallcan) ans = m - 1;
        printf("%d %d\n", ncs, ans);
    }
    return 0;
}
