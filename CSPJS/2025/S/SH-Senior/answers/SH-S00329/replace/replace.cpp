#include<bits/stdc++.h>

using namespace std;

int n, q;

// struct Tire {
//     Tire* son[26];

// }

// struct AC {

// }; buhui....


vector<string> dicta, dictb;
int diff[5000010]{};

int main() {
#ifndef MYDEBUG
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
#endif

    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0)->sync_with_stdio(false);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        dicta.push_back(a);
        dictb.push_back(b);
    }

    for (int i = 1; i <= q; i++) {
        int ans = 0;
        string a, b;
        cin >> a >> b;
        for (int j = 1; j <= a.length(); j++) {
            diff[j] = diff[j - 1];
            if (a[j - 1] != b[j - 1]) {
                diff[j]++;
            }
            // cout << "diff" << j << ' ' << diff[j] << endl;
        }
        for (int j = 0; j < dicta.size(); j++) {
            int now = 0;
            while (true) {
                int ixa = a.find(dicta[j], now);
                if (ixa == -1) break;
                int ixb = b.find(dictb[j], now);
                if (ixb == -1 || ixb != ixa) break;
                // cout <<"ixa=" << ixa << endl;
                if (diff[ixa - 1] > 0 || 
                    diff[a.length()] - diff[ixa + dicta[j].length()] > 0) break;
                // cout << now << endl;
                now = ixa + 1;
                ans++;
            }
        }
        cout << ans << endl;
    }

    // string a = "abcabc", b = "abc";
    
    // cout << a.find(b, 1);

    return 0;
}

// ^_^
