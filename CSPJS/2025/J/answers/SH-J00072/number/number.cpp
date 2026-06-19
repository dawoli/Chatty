#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> vc;
    for (char c : s) {
        if (isdigit(c)) {
            vc.push_back(c-'0');
        }
    }
    sort(vc.begin(), vc.end(), greater<int>());
    for (int x : vc) cout << x;
    return 0;
}