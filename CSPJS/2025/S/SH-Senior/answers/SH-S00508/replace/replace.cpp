#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;
constexpr int BASE = 178, MOD = 1e9 + 7;
int h1[2001], h2[2001], b[2001];
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q, ans;
    string s1, s2;
    unordered_set<ll> st;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        int h1 = 0, h2 = 0;
        for (int j = 0; j < s1.size(); j++)
        {
            h1 = ((ll)h1 * BASE + s1[j] - 'a') % MOD;
            h2 = ((ll)h2 * BASE + s2[j] - 'a') % MOD;
        }
        st.insert(((ll)h1 << 32) + h2);
    }
    while (q--)
    {
        ans = 0;
        cin >> s1 >> s2;
        h1[0] = h2[0] = 0;
        b[0] = 1;
        for (int i = 0; i < s1.size(); i++)
        {
            b[i + 1] = (ll)b[i] * BASE % MOD;
            h1[i + 1] = ((ll)h1[i] * BASE + s1[i] - 'a') % MOD;
            h2[i + 1] = ((ll)h2[i] * BASE + s2[i] - 'a') % MOD;
        }
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = i; j < s1.size(); j++)
            {
                if (h1[i] == h2[i] && (h1[s1.size()] + ll(MOD - h1[j + 1]) * b[s1.size() - j - 1]) % MOD == (h2[s1.size()] + ll(MOD - h2[j + 1]) * b[s1.size() - j - 1]) % MOD)
                {
                    int a1 = (h1[j + 1] + ll(MOD - h1[i]) * b[j - i + 1]) % MOD;
                    int a2 = (h2[j + 1] + ll(MOD - h2[i]) * b[j - i + 1]) % MOD;
                    if (st.find(((ll)a1 << 32) + a2) != st.end())
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}