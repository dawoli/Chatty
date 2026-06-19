#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;

namespace AugustLight {
    const int MAXN = 500 + 5;
    const ll MOD = 998244353;

    int n, m;
    bool s[MAXN];
    int c[MAXN];

    ll fac[MAXN];
    void init_fac(ll n) {
        fac[0] = 1;
        rep(i, 1, n)
            fac[i] = fac[i-1] * i % MOD;
    }

    namespace BF {
        int p[MAXN];
        ll Main() {
            rep(i, 1, n)
                p[i] = i;
            ll ans = 0;
            do {
                int cnt = 0;
                rep(i, 1, n)
                    if (cnt >= c[p[i]] or !s[i])
                        cnt++;
                if (n - cnt >= m)
                    ans++;
            } while (next_permutation(p+1, p+n+1));
            return ans % MOD;
        }
    }

    namespace SubA {
        bool valid() {
            rep(i, 1, n)
                if (!s[i])
                    return false;
            return true;
        }
        void Main() {

        }
    }

    namespace Sub15 {
        bool valid() {
            return (m == n);
        }
        ll Main() {
            if (!SubA::valid())
                return 0;
            rep(i, 1, n)
                if (c[i] == 0)
                    return 0;
            return fac[n];
        }
    }

    void Main() {
        cin >> n >> m;
        init_fac(500);
        rep(i, 1, n) {
            char c; cin >> c;
            if (c == '1')
                s[i] = 1;
            else
                s[i] = 0;
        }
        rep(i, 1, n)
            cin >> c[i];

        if (Sub15::valid())
            cout << Sub15::Main() << '\n';
        //else if (SubA::valid())
        //    cout << SubA::Main() << '\n';
        else
            cout << BF::Main() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    AugustLight::Main();
    return 0;
}