#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
using i64 = long long;
using PII = pair<int, int>;
template <int mod, int seed> 
struct SingleHash {
    std::vector<int> pow, h;
    inline void init(std::string &s) {
        const int n = s.size() - 1;
        pow.assign(n + 1, 1), h.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pow[i] = 1ll * pow[i - 1] * seed % mod;
            h[i] = (1ll * h[i - 1] * seed + s[i]) % mod;
        }
    }
    inline int query(int l, int r) {
        if (l > r) return 0;
        return (h[r] - 1ll * pow[r - l + 1] * h[l - 1] % mod + mod) % mod;
    }
};
struct HashedString {
    SingleHash<998244353, 447> H1;
    SingleHash<1000000007, 233> H2;
    inline void init(std::string s) {
        s = ' ' + s, H1.init(s), H2.init(s);
    }
    inline PII query(int l, int r) {
        l++, r++;
        return {H1.query(l, r), H2.query(l, r)};
    }
};
pair<PII, PII> ch[N];
PII S[N], T[N], pre[N], suf[N];
std::string s[N][2], t[N][2];
HashedString HS[2], HT[2];
inline PII calc(std::string &s1, std::string &s2) {
    int n = s1.size(), i = 0, j = n - 1;
    while (i < n && s1[i] == s2[i]) i++;
    while (j >= 0 && s1[j] == s2[j]) j--;
    return {i, j};
}
int n, q, pres[N], sufs[N];
map<pair<PII, PII>, vector<int>> mp;
inline void optimizeIO(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, const char *argv[]) {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    optimizeIO(), cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        S[i] = calc(s[i][0], s[i][1]);
        HS[0].init(s[i][0]), HS[1].init(s[i][1]);
        auto [l, r] = S[i];
        pre[i] = HS[0].query(0, l - 1);
        suf[i] = HS[0].query(r + 1, s[i][0].size() - 1);
        pres[i] = l, sufs[i] = s[i][0].size() - r - 1;
        pair<PII, PII> mod = {HS[0].query(l, r), HS[1].query(l, r)};
        mp[mod].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        int cnt = 0;
        cin >> t[i][0] >> t[i][1];
        auto [l, r] = calc(t[i][0], t[i][1]);
        HT[0].init(t[i][0]), HT[1].init(t[i][1]);
        pair<PII, PII> mod = {HT[0].query(l, r), HT[1].query(l, r)};
        for (auto &j : mp[mod]) {
            // auto [L, R] = S[j];
            if (pres[j] > l || sufs[j] > t[i][0].size() - r) {
                continue;
            }
            if (HT[0].query(l - pres[j], l - 1) == pre[j] && 
                HT[0].query(r + 1, r + sufs[j]) == suf[j]) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}