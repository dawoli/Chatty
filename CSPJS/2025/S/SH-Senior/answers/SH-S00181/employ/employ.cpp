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
const ll N = 509, Mod = 998244353;
ll n, m, a[N], cnt[N], fac[N], ifac[N], dp[2][N][N], cur;
char s[N];
ll pw(ll x, ll p) {
    ll res = 1;
    while(p) {
        if(p & 1) res = res * x % Mod;
        x = x * x % Mod, p >>= 1;
    }
    return res;
}
ll C(ll x, ll y) {
    if(x < y || y < 0) return 0;
    return fac[x] * ifac[y] % Mod * ifac[x - y] % Mod;
}
bool Med;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cerr << fabs(&Med - &Mbe) / 1048576.0 << "MB\n";
    n = read(), m = read();
    scanf("%s", s + 1);
    rep(i, 1, n) a[i] = read(), cnt[a[i]]++;
    rep(i, 1, n) cnt[i] += cnt[i - 1];
    fac[0] = 1;
    rep(i, 1, n) fac[i] = fac[i - 1] * i % Mod;
    ifac[n] = pw(fac[n], Mod - 2);
    per(i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % Mod;
    dp[0][0][0] = 1;
    rep(i, 1, n) {
        memset(dp[cur ^ 1], 0, sizeof(dp[cur ^ 1]));
        rep(j, 0, i) {
            rep(k, 0, i) {
                if(!dp[cur][j][k]) continue;
                // cout << i - 1 << " " << j << " " << k << " " << dp[cur][j][k] << endl;
                if(s[i] == '0') {
                    dp[cur ^ 1][j][k] = (dp[cur ^ 1][j][k] + dp[cur][j][k]) % Mod;
                    continue;
                }
                ll lim = i - 1 - j;
                // not employ
                dp[cur ^ 1][j][k + 1] = (dp[cur ^ 1][j][k + 1] + dp[cur][j][k] * max(0ll, cnt[lim] - k)) % Mod;
                // employ, no constraint
                dp[cur ^ 1][j + 1][k] = (dp[cur ^ 1][j + 1][k] + dp[cur][j][k]) % Mod;
                // employ, must be not enough
                // c[i] <= lim
                dp[cur ^ 1][j + 1][k + 1] = (dp[cur ^ 1][j + 1][k + 1] - dp[cur][j][k] * max(0ll, cnt[lim] - k) % Mod + Mod) % Mod; 
            }
        }
        cur ^= 1;
    }
    ll ans = 0;
    rep(j, m, n) {
        rep(k, 0, n) ans = (ans + dp[cur][j][k] * fac[n - k]) % Mod;
    }
    write(ans), putchar('\n');
    cerr << "\n" << clock() * 1.0 / CLOCKS_PER_SEC * 1000 << "ms\n";
    return 0;
}

/*
g++ -std=c++14 -O2 -Wall -Wextra employ.cpp -o employ && ./employ
*/
