#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+7, MAXM = 5e6+7;
vector<string> s1, s2;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string ss = "HEELLO";
    // cout << ss.substr(2, 2);
    // return 0;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        s1.push_back(a), s2.push_back(b);
    }
    while (q--) {
        string a, b;
        cin >> a >> b;
        int ct = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < s1.size(); j++) {
                int m = s1[j].size();
                // if (i + m < a.size()) {
                //     cout << a.substr(i, m) << endl;
                // }
                if (i+m <= a.size() && a.substr(i, m) == s1[j]) {
                    string temp = a;
                    for (int k = i; k < i+m; k++) {
                        temp[k] = s2[j][k-i];
                    }
                    if (temp == b) {
                        ++ct;
                    }
                }
            }
        }
        printf("%d\n", ct);
    }
    return 0;
}