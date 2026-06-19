#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
const ull Bas = 108432131;
const ll N = 2e5 + 9, M = 5e6 + 9 + N * 4;
ll n, q;
char s1[M], s2[M];
struct BIT {
    ll n, bit[M];
    void Init(ll _n) {
        n = _n;
        rep(i, 0, n + 1) bit[i] = 0;
    }
    void Upd(ll x, ll k) {
        while(x <= n) bit[x] += k, x += (x & (-x));
    }
    ll Query(ll x) {
        ll res = 0;
        while(x) res += bit[x], x -= (x & (-x));
        return res;
    }
} B;
ll typ, tot, ans[N];
int ch[M / 2 + 999999][26], rt1[N], rt2[N];
pii par[N];
map<ull, ll> H;
Ve<int> va[M];
Ve<pair<int, int> > vq[M];
int dfn[M], sz[M], tim;
void dfs1(int x) {
    dfn[x] = ++tim, sz[x] = 1;
    rep(i, 0, 25) {
        int y = ch[x][i];
        if(!y) continue;
        dfs1(y), sz[x] += sz[y];
    }
}
void dfs2(int x) {
    for(int y : va[x]) B.Upd(dfn[y], 1), B.Upd(dfn[y] + sz[y], -1);
    for(pair<int, int> qu : vq[x]) {
        int y = qu.first, id = qu.second;
        ans[id] += B.Query(dfn[y]);
    }
    rep(i, 0, 25) {
        int y = ch[x][i];
        if(!y) continue;
        dfs2(y);
    }
    for(int y : va[x]) B.Upd(dfn[y], -1), B.Upd(dfn[y] + sz[y], 1);
}
bool Med;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cerr << fabs(&Med - &Mbe) / 1048576.0 << "MB\n";
    n = read(), q = read();
    rep(i, 1, n) {
        scanf("%s%s", s1 + 1, s2 + 1);
        ll len = strlen(s1 + 1);
        ll L = len + 1, R = 0;
        rep(j, 1, len) {
            if(s1[j] != s2[j]) {
                L = min(L, j);
                R = max(R, j);
            }
        }
        if(!R) continue;
        ull hsh = 0;
        rep(j, L, R) hsh = hsh * Bas + s1[j];
        rep(j, L, R) hsh = hsh * Bas + s2[j];
        // cout << L << " " << R << " " << hsh << endl;
        if(!H.count(hsh)) H[hsh] = ++typ, rt1[typ] = ++tot, rt2[typ] = ++tot;
        ll tp = H[hsh]; 
        int u = rt1[tp]; 
        per(j, L - 1, 1) {
            ll v = s1[j] - 'a';
            if(!ch[u][v]) ch[u][v] = ++tot;
            u = ch[u][v];
        }
        par[i].first = u;
        u = rt2[tp];
        rep(j, R + 1, len) {
            ll v = s1[j] - 'a';
            if(!ch[u][v]) ch[u][v] = ++tot;
            u = ch[u][v];
        }
        par[i].second = u;
        va[par[i].first].pb(par[i].second);
        // cout << par[i].first << " " << par[i].second << endl;
    }
    rep(i, 1, q) {
        scanf("%s%s", s1 + 1, s2 + 1);
        ll len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        if(len1 != len2) continue;
        ll L = len1 + 1, R = 0;
        rep(j, 1, len1) {
            if(s1[j] != s2[j]) {
                L = min(L, j);
                R = max(R, j);
            }
        }
        // assert(R);
        ull hsh = 0;
        rep(j, L, R) hsh = hsh * Bas + s1[j];
        rep(j, L, R) hsh = hsh * Bas + s2[j];
        // cout << L << " " << R << " " << hsh << endl;
        if(!H.count(hsh)) continue;
        ll tp = H[hsh];
        int u1 = rt1[tp], u2 = rt2[tp];
        per(j, L - 1, 1) {
            ll v = s1[j] - 'a';
            if(!ch[u1][v]) break;
            u1 = ch[u1][v];
        } 
        rep(j, R + 1, len1) {
            ll v = s1[j] - 'a';
            if(!ch[u2][v]) break;
            u2 = ch[u2][v];
        }
        // cout << u1 << " " << u2 << endl;
        vq[u1].pb(make_pair(u2, (int)i));
    }
    // cerr << tot << "\n";
    rep(i, 1, typ) {
        tim = 0;
        dfs1(rt2[i]);
        B.Init(tim);
        dfs2(rt1[i]);
    }
    rep(i, 1, q) write(ans[i]), putchar('\n');
    cerr << "\n" << clock() * 1.0 / CLOCKS_PER_SEC * 1000 << "ms\n";
    return 0;
}

/*
g++ -std=c++14 -O2 -Wall -Wextra replace.cpp -o replace && ./replace
*/