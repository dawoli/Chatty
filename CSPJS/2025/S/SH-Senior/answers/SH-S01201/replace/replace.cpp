#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll n, q, t[N][2];
unordered_map<string, vector<string>> s;

pair<string, string> trim(string a, string b)
{
    // assert(a.size() == b.size());
    size_t l = 0, r = a.size() - 1;
    while (a[l] == b[l] && l < a.size())
        l++;
    while (a[r] == b[r] && r >= 0)
        r--;
    return {a.substr(l, r - l + 1) + " " + b.substr(l, r - l + 1), a.substr(0, l) + " " + b.substr(r + 1, b.size() - r)};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef LOCAL
    ignore = freopen("replace.in", "r", stdin);
    ignore = freopen("replace.out", "w", stdout);
    // #else
    // ignore = freopen("replace.err", "w", stderr);
    // #endif
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2)
            continue;
        tie(s1, s2) = trim(s1, s2);
        s[s1].push_back(s2);
        // cerr << "\"" << s1 << "\" --- \"" << s2 << "\"" << endl;
    }
    // cerr << endl;
    for (ll i = 0; i < q; i++)
    {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            // cerr << "Len not match" << endl;
            cout << 0 << endl;
        }
        else
        {
            tie(t1, t2) = trim(t1, t2);
            // cerr << "Finding \"" << t2 << "\"" << endl;
            ll ans = 0;
            for (const auto &_ : s[t1])
                if (t2.find(_) != string::npos)
                {
                    // cerr << "Found: \"" << _ << "\"" << endl;
                    ans++;
                }
            // cerr << endl;
            cout << ans << endl;
        }
    }
    return 0;
}