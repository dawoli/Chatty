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
const ll N = 1e4 + 9, M = 1e6 + 9, INF = 1e18;
ll n, m, K, ec, E;
array<ll, 3> e[M], tr[N];
array<ll, 4> te[N * 15];
ll fa[N], c[15];
pii to[15][N];
ll find(ll x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool check(ll x, ll y) {
    return find(x) == find(y);
}
void merge(ll x, ll y) {
    x = find(x), y = find(y);
    if(x ^ y) fa[x] = y;
}
bool Med;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cerr << fabs(&Med - &Mbe) / 1048576.0 << "MB\n";
    n = read(), m = read(), K = read();
    rep(i, 1, m) e[i][1] = read(), e[i][2] = read(), e[i][0] = read();
    iota(fa + 1, fa + n + 1, 1ll);
    sort(e + 1, e + m + 1);
    rep(i, 1, m) {
        ll w = e[i][0], x = e[i][1], y = e[i][2];
        if(check(x, y)) continue;
        tr[++ec] = {w, x, y};
        merge(x, y);
    }
    // rep(i, 1, ec) cout << tr[i][0] << " " << tr[i][1] << " " << tr[i][2] << endl;
    rep(i, 1, K) {
        c[i] = read();
        rep(j, 1, n) to[i][j].first = read(), to[i][j].second = j;
        sort(to[i] + 1, to[i] + n + 1);
        // rep(j, 1, n) cout << to[i][j].first << " ";
        // cout << endl;
    }
    rep(i, 1, n - 1) te[++E] = {tr[i][0], tr[i][1], tr[i][2], 0};
    rep(i, 1, K) {
        rep(j, 2, n) te[++E] = {to[i][j].first, to[i][j].second, to[i][1].second, i};
    }
    sort(te + 1, te + E + 1);
    ll ans = INF;
    rep(S, 0, (1 << K) - 1) {
        iota(fa + 1, fa + n + 1, 1ll);
        ll res = 0;
        rep(i, 1, K) {
            if((S >> (i - 1)) & 1) res += c[i] + to[i][1].first;
        }
        ec = 0; 
        rep(i, 1, E) {
            if(ec == n - 1 || res > ans) break;
            ll tp = te[i][3];
            if(tp && (!((S >> (tp - 1)) & 1))) continue;
            ll x = te[i][1], y = te[i][2];
            if(!check(x, y)) merge(x, y), ++ec, res += te[i][0];
        }
        ans = min(ans, res);
        // cout << res << endl;
    }
    write(ans), putchar('\n');
    cerr << "\n" << clock() * 1.0 / CLOCKS_PER_SEC * 1000 << "ms\n";
    return 0;
}

/*
g++ -std=c++14 -O2 -Wall -Wextra road.cpp -o road && ./road
*/