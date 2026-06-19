#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[1000], ans;
int main() {
    freopen("seat.in", "r", stdin);
   freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    ans = a[1];
    sort(a + 1, a + n * m + 1);
    for(ll i = 1; i <= n * m; i++) {
        if(a[i] == ans) {
            ans = i;
            break;
        }
    }
    ans = n * m - ans + 1;
    ll a = (ans-1) / n;
    ll b = (ans-1) % n;
    b++;
    cout << a+1 << " ";
    if(a%2 == 0) {
        cout << b;
    } else {
        cout << n-b+1;
    }
    return 0;
}
