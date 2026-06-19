#include <bits/stdc++.h>
using namespace std;

set<string> seq;

int main() {
        freopen("poker.in", "r", stdin);
        freopen("poker.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        seq.insert(s);
    }
    cout << 52 - seq.size();
    return 0;
}