#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200010, base = 31, mod = (ll)1e9 + 9;
ll n, q; string s[N][2]; map<string, string> mp;
void solve()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1], mp[s[i][0]] = s[i][1];
    while (q--)
    {
        string a, b; cin >> a >> b; ll ret = 0;
        for (ll i = 0; i < (ll)a.size(); i++)
            for (ll j = 0; j <= i; j++)
            {
                string tmp = a.substr(j, i-j+1);
                if (mp.count(tmp))
                {
                    string ttt = a;
                    for (ll k = j; k <= i; k++) a[k] = mp[tmp][k-j];
//                    cout << i << ' ' << j << ' ' << a << endl;
                    if (a == b) ret++;
                    a = ttt;
                }
            }
        printf("%lld\n", ret);
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
