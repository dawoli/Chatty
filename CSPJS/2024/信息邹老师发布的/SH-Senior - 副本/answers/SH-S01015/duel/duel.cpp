#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, r[100009];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> r[i];
    sort(r+1, r+n+1);
    ll lastused = 0, ans = n;
    for(ll i = 1; i <= n; i++) {
        ll pos = lower_bound(r+1, r+n+1, r[i]+1)-r;
        if(lastused >= pos) pos = lastused+1;
        if(pos <= n) ans--;
        lastused = pos;
    }
    cout << ans << endl;
    return 0;
}