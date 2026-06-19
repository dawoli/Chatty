#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, a[500009], s[500009], f[500009], sf[500009];
map<ll,ll> mp;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1] ^ a[i];
    mp[0] = 0;
    for(ll i = 1; i <= n; i++) {
        if(mp.find(k^s[i]) != mp.end()) f[i] = sf[mp[k^s[i]]]+1;
        sf[i] = max(f[i], sf[i-1]);
        mp[s[i]] = i;
    }
    cout << sf[n] << '\n';
    return 0;
}