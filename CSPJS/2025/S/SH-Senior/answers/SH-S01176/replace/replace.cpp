#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, lens[N], lent;
string s[N][3], t1, t2;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    //freopen("replace.err", "w", stderr);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i][1] >> s[i][2], lens[i] = s[i][1].size();
    while (q--) {
        cin >> t1 >> t2; lent = t1.size(); int ans = 0;
        if (lent != t2.size()) {cout << 0 << endl; continue;}
        for (int i = 1; i <= n; i++) {
            // for (int j = 0; j <= lent - lens[i]; j++)
            int pos1 = t1.find(s[i][1]), pos2 = t2.find(s[i][2]);
            cerr<<pos1<<" "<<pos2<<endl;
                if (~pos1 && ~pos2 && pos1 == pos2) {//assert(0);
                    cerr<<"x";
                    bool flag = true;
                    for (int i = 0; i < pos1; i++) if (t1[i] != t2[i]) flag = false;
                    for (int i = pos1 + lens[i]; i < lent; i++)
                        if (t1[i] != t2[i]) flag = false;
                    if (flag) ans++;
                }//assert(0);
        }//cerr<<endl;
        cout << ans << endl;
    }
    return 0;
}
