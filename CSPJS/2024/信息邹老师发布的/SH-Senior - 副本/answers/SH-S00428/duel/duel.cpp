#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000 + 5;
int n, cnt[MAXN], ans, maxr = -1;
signed main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1, r; i <= n; i++){
        cin >> r;
        maxr = max(maxr, r);
        cnt[r]++;
    }
    ans = n;
    int pre = 0;
    for(int i = 1; i <= maxr; i++){
        ans -= min(pre, cnt[i]);
        pre += cnt[i] - min(pre, cnt[i]);
        //cout << ans << ' ' << pre << endl;
    }
    cout << ans << endl;
    return 0;
}
