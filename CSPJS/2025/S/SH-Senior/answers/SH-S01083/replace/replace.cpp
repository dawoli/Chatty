#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, q;
string s[200009][2];

const unsigned long long MOD = 998244353;
unsigned long long qpow(unsigned long long x, unsigned long long y) {
    unsigned long long res = 1;
    while(y) {
        if(y&1) (res *= x) %= MOD;
        (x *= x) %= MOD;
        y >>= 1;
    }
    return res;
}
struct m99 {
    unsigned long long v;
    m99(): v(0){}
    m99(unsigned long long x): v(x){}
    m99(const m99& u): v(u.v){}
    m99 operator*(const m99& x) const {return v*x.v%MOD;}
    m99 operator+(const m99& x) const {return (v+x.v)%MOD;}
    m99 operator-(const m99& x) const {return (v+MOD-x.v)%MOD;}
    m99 operator/(const m99& x) const {return (v*qpow(x.v, MOD-2))%MOD;}
    m99 operator%(const m99& x) const {return (*this)-(*this)/x;}
    bool operator<(const m99& x) const {return v < x.v;}
    bool operator==(const m99& x) const {return v == x.v;}
};
typedef m99 ull;
const ll T = 10;
ull mapping[T][26];
const ull B = 131;
ull pw[5000009];
vector<ull> hd[200009], h[200009][2];
multiset<vector<ull>> ms;
map<vector<ull>,vector<ll>> mp;

ull H(string st, ll mpid) {
    ull hsh = 0;
    for(char c:st) hsh.v = (hsh*B+mapping[mpid][c-'0']).v;
    return hsh;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    pw[0].v = 1;
    for(ll i = 1; i < 5000009; i++) pw[i].v = m99(pw[i-1]*B).v;
    auto gen = mt19937_64();
    for(ll i = 0; i < T/2; i++) {
        for(ll c = 0; c < 26; c++) mapping[i][c].v = c;
        shuffle(mapping[i], mapping[i]+26, gen);
    }
    for(ll i = T/2; i < T; i++) for(ll c = 0; c < 26; c++) mapping[i][c].v = (unsigned long long)gen();
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
    for(ll k = 0; k < T; k++) for(ll i = 1; i <= n; i++) {
        ull h1 = H(s[i][0], k), h2 = H(s[i][1], k);
        h[i][0].push_back(h1); h[i][1].push_back(h2);
        hd[i].push_back(h2-h1);
    }
    for(ll i = 1; i <= n; i++) ms.emplace(hd[i]), mp[hd[i]].push_back(i);
    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;
        vector<ull> h1, h2;
        for(ll k = 0; k < T; k++) h1.push_back(H(t1, k)), h2.push_back(H(t2, k));
        vector<vector<ull>> ph1;
        for(ll k = 0; k < T; k++) {
            vector<ull> vec;
            ull hsh = 0;
            for(char c:t1) {
                hsh.v = (hsh*B+mapping[k][c-'0']).v;
                vec.push_back(hsh);
            }
            ph1.push_back(vec);
        }
        ll ans = 0;
        for(ll i = t2.size(); i >= 1; i--) {
            vector<ull> diff;
            for(ll k = 0; k < T; k++) diff.push_back((h2[k]-h1[k])/pw[t2.size()-i]);
            for(ll t:mp[diff]) {
                bool b = true;
                for(ll k = 0; k < T; k++) {
                    // if(k == 0) {
                    //     cout << (ph1[k][i-1]-ph1[k][i-1-s[t][0].size()]*pw[s[t][0].size()]).v << ' ' << h[t][0][k].v << endl;
                    // }
                    b &= (i-1 > s[t][0].size() && ph1[k][i-1]-ph1[k][i-1-s[t][0].size()]*pw[s[t][0].size()] == h[t][0][k])
                    || (i == s[t][0].size() && ph1[k][i-1] == h[t][0][k]);
                }
                if(b) ans++;
            }
            if(t1[i-1] != t2[i-1]) break;
        }
        cout << ans << '\n';
    }
    return 0;
}