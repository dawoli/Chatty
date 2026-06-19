#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, a[109];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n*m; i++) cin >> a[i];
    ll r = a[1];
    sort(a+1, a+n*m+1, greater<ll>());
    ll idx = 0;
    for(ll i = 1; i <= m; i++) {
        for(ll j = ((i&1)?1:n); j && j <= n; ((i&1)?(j++):(j--))) {
            idx++;
            if(a[idx] == r) {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
    return 0;
}