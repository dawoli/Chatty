#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAXn = 2e5 + 9;
int d[MAXn];
map<int, int> mp;
int mxv, mxt;
bitset<MAXn> sta;

int main() {
    // finished BAOLI at 18:24
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++) {
        int n;
        scanf("%d", &n);
        if(n <= 100) {
            for(int i = 0; i < n; i ++) {
                scanf("%d", &d[i]);
            }
            lli ans = 0;
            sta = 0;
            while(!sta[n]) {
                lli nowans = 0;
                int last0 = -1, last1 = -1;
                for(int i = 0; i < n; i ++) {
                    if(sta[i]) {
                        if(last1 == -1) last1 = i;
                        else {
                            if(d[last1] == d[i]) nowans += d[i];
                            last1 = i;
                        }
                    }
                    else /*sta[i] == 0*/ {
                        if(last0 == -1) last0 = i;
                        else {
                            if(d[last0] == d[i]) nowans += d[i];
                            last0 = i;
                        }
                    }
                }
                ans = max(ans, nowans);
                sta = sta.to_ulong() + 1;
            }
            printf("%lld\n", ans);
        } else {
            for(int i = 1; i <= n; i ++) {
                int ia;
                scanf("%d", &ia);
                mp[ia] ++;
                if(mxt < mp[ia]) mxt = mp[ia], mxv = ia;
            }
            printf("%lld\n", 1ll * mxv * mxt);
        }
    }
    return 0;
}
