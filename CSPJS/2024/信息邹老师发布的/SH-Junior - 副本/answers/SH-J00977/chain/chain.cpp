#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

int T, n, k, q, l[N], s[N][N];

void calc1(int r, int c) {
    int idi = 0, idj = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= l[i]; ++j) {
            if(s[i][j] == c) {
                idi = i;
                idj = j;
                break;
            }
        }
        if(idi != 0 && idj != 0) break;
    }
    for(int i = 1; i <= idj && i <= l[idi]; ++i)
        if(s[idi][i] == 1) {
            if(idj - i + 1 <= k) {
                cout << 1 << endl;
                return;
            }
        }
    cout << 0 << endl;
    return;
}

void solve() {
    cin >> n >> k >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> l[i];
        for(int j = 1; j <= l[i]; ++j)
            cin >> s[i][j];
    }

    while(q--) {
        int r, c;
        cin >> r >> c;

        if(r == 1)
            calc1(r, c);
        else
            cout << 0 << endl;
    }
}

signed main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--)
        solve();

    return 0;
}