#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

namespace AugustLight {
    const int MAXN = 2e5 + 5;
    const int MAXL = 5e6 + 5;

    int n, q;
    string S1[MAXN], S2[MAXN];
    string T1[MAXN], T2[MAXN];

    namespace BF1 {
        void Main() {
            //cerr << "BF1" << endl;
            rep(i, 1, q) {
                string t1 = T1[i], t2 = T2[i];
                int lent = t1.size() - 1;
                int ans = 0;
                rep(j, 1, n) {
                    string s1 = S1[j], s2 = S2[j];
                    int lens = s1.size() - 1;
                    rep(k, 1, lent - lens + 1) {
                        bool flg = true;
                        rep(x, 1, k-1)
                            if (t1[x] != t2[x])
                                flg = false;
                        rep(x, k + lens, lent)
                            if (t1[x] != t2[x])
                                flg = false;
                        rep(x, 1, lens) {
                            if (t1[k + x - 1] != s1[x])
                                flg = false;
                            if (t2[k + x - 1] != s2[x])
                                flg = false;
                        }
                        if (flg) {
                            //cerr << j << " " << k << endl;
                            ans++;
                        }
                    }
                }
                //cerr << "---" << endl;
                cout << ans << '\n';
            }
        }
    }

    /*
    namespace HASH {
        ull BASE = 13331;
        ull pw[MAXL];
        void init() {
            pw[0] = 1;
            rep(i, 1, 5e6)
                pw[i] = pw[i-1] * BASE;
        }
        vector<ull> hash_string(string s) {
            int n = s.size()-1;
            vector<ull> hsh; hsh.resize(n+1);
            hsh[0] = 0;
            rep(i, 1, n)
                hsh[i] = hsh[i-1] * BASE + s[i];
            return hsh;
        }
        ull query(int l, int r, vector<ull> &hsh) {
            int len = r-l+1;
            return hsh[r] - hsh[l-1] * pw[len];
        }
    }

    namespace BF2 {
        vector<ull> hs1[MAXN], hs2[MAXN];
        void Main() {
            cerr << "BF Hash" << endl;
            rep(i, 1, n) {
                hs1[i] = HASH::hash_string(S1[i]);
                hs2[i] = HASH::hash_string(S2[i]);
            }
            //cerr << "S processed" << endl;
            rep(i, 1, q) {
                string t1 = T1[i], t2 = T2[i];
                int lent = t1.size() - 1;
                auto ht1 = HASH::hash_string(t1);
                auto ht2 = HASH::hash_string(t2);
                int ans = 0;
                rep(j, 1, n) {
                    string s1 = S1[j], s2 = S2[j];
                    int lens = s1.size() - 1;
                    rep(k, 1, lent - lens + 1) {
                        bool flg = true;
                        if (HASH::query(1, k-1, ht1) != HASH::query(1, k-1, ht2))
                            flg = false;
                        if (HASH::query(k + lens, lent, ht1) != HASH::query(k + lens, lent, ht2))
                            flg = false;
                        if (HASH::query(k, k + lens - 1, ht1) != hs1[i][lens])
                            flg = false;
                        if (HASH::query(k, k + lens - 1, ht2) != hs2[i][lens])
                            flg = false;
                        if (flg) {
                            cerr << j << " " << k << endl;
                            ans++;
                        }
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    */

    /*
    namespace SubB {
        int special(string &s) {
            int n = s.size() + 1;
            int idx = 0;
            rep(i, 1, n)
                if (s[i] == 'b') {
                    if (idx)
                        return 0;
                    idx = i;
                } else if (s[i] != 'a')
                    return 0;
            return idx;
        }
        int a1[MAXN], a2[MAXN];
        int b1[MAXN], b2[MAXN];
        bool valid() {
            rep(i, 1, n) {
                a1[i] = special(S1[i]);
                a2[i] = special(S2[i]);
                if (!a1[i] or !a2[i]) return false;
            }
            rep(i, 1, q) {
                b1[i] = special(T1[i]);
                b2[i] = special(T2[i]);
                if (!b1[i] or !b2[i]) return false;
            }
            return true;
        }
        void BF() {
            cerr << "Sub B BF" << endl;
        }
        void Main() {
            map<int, vector<int>> mp;
            rep(i, 1, n) {
                mp[a2[i] - a1[i]].push_back(i);
            }
            rep(j, 1, q) {
                int delta = b2[j] - b1[j];
                int ans = 0;
                for (auto i : mp[delta]) {
                    int l = 1 + b1[j] - a1[i];
                    int lens = S1[i].size() - 1;
                    int r = l + lens - 1;
                    if (1 <= l and r <= (int)T1[j].size() - 1)
                        ans++;
                }
                cout << ans << '\n';
            }
        }
    }
    */

    void Main() {
        cin >> n >> q;
        rep(i, 1, n) {
            cin >> S1[i] >> S2[i];
            S1[i] = "#" + S1[i];
            S2[i] = "#" + S2[i];
        }
        rep(i, 1, q) {
            cin >> T1[i] >> T2[i];
            T1[i] = "#" + T1[i];
            T2[i] = "#" + T2[i];
        }

        BF1::Main();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    AugustLight::Main();
    return 0;
}