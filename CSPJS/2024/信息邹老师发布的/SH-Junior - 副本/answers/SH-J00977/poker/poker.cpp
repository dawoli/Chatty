#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
map<string, bool> mp;

signed main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        string s; cin >> s;
        mp[s] = true;
    }

    cout << 52 - mp.size() << endl;
    return 0;
}
