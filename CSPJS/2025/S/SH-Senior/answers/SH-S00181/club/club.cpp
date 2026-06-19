#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(ll i = (a); i <= (b); ++i)
#define per(i, a, b) for(ll i = (a); i >= (b); --i)
template <class T>
using Ve = vector<T>;
#define pb push_back
#define pii pair<ll, ll>
bool Mbe;
ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -f;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}
void write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
const ll N = 1e5 + 9;
ll T, n, a[N][3], ans, g[2];
Ve<ll> id[3];
void solve() {
    n = read(), ans = 0;
    rep(i, 1, n) {
        rep(j, 0, 2) a[i][j] = read();
    }
    rep(i, 0, 2) id[i].clear();
    rep(i, 1, n) {
        ll p = max_element(a[i], a[i] + 3) - a[i];
        ans += a[i][p], id[p].pb(i);
    }
    ll tp = -1;
    rep(i, 0, 2) {
        if((ll)id[i].size() > n / 2) tp = i;
    }
    if(!~tp) {
        write(ans), putchar('\n');
        return ;
    }
    if(tp == 0) g[0] = 1, g[1] = 2;
    else if(tp == 1) g[0] = 0, g[1] = 2;
    else g[0] = 0, g[1] = 1;
    Ve<ll> v;
    for(ll x : id[tp]) {
        ll d1 = a[x][g[0]] - a[x][tp];
        ll d2 = a[x][g[1]] - a[x][tp];
        v.pb(max(d1, d2));
    }
    ll o = (ll)id[tp].size() - (n / 2);
    sort(v.begin(), v.end(), greater<ll>());
    rep(i, 0, o - 1) ans += v[i];
    write(ans), putchar('\n');
}
bool Med;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cerr << fabs(&Med - &Mbe) / 1048576.0 << "MB\n";
    T = read();
    while(T--) solve();
    cerr << "\n" << clock() * 1.0 / CLOCKS_PER_SEC * 1000 << "ms\n";
    return 0;
}

/*
g++ -std=c++14 -O2 -Wall -Wextra club.cpp -o club && ./club
*/