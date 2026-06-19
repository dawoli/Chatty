// xor
// seat:100pts
// 09:31 start to write code.
// O(n)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
ll a[823482]; // Subscribe me!
ll f[823482];
vector<ll> ff[1294450];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        f[i] = a[i] ^ f[i-1];
    }
    ll x = -1;
    ff[0].push_back(0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll o = (f[i] ^ k);
        if(!ff[o].empty()) {
            if(ff[o].back() >= x) {
                ans++;
                x = i;
            }
        }
        ff[f[i]].push_back(i);
    }
    printf("%lld", ans);
    return 0;
}
