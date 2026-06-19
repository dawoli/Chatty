#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

int T, n, dp[N][N / 2], d[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void calc1() {
    int maxl = n / 2;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= maxl; ++j)
            for(int k = 0; k <= 9; ++k) {
                if(j == 1 && k == 0) continue;
                if(i >= d[k])
                    dp[i][j] = min(dp[i][j], dp[i - d[k]][j - 1] * 10 + k);
            }

    int minn = 1e15;
    for(int i = 1; i <= maxl; ++i)
        minn = min(minn, dp[n][i]);

    if(minn == 1e15) cout << -1 << endl;
    else cout << minn << endl;
}

void calc2() {
    int t = n / 7;
    for(int i = 1; i <= t; ++i)
        cout << 8;
    cout << endl;
}

void calc3() {
    if(n == 1) cout << -1 << endl;
    else {
        int t = n / 7 - 1;
        cout << 10;
        for(int i = 1; i <= t; ++i)
            cout << 8;
        cout << endl;
    }
}

void solve() {
    cin >> n;

    if(n % 7 == 0)
        calc2();
    else if(n % 7 == 1)
        calc3();
    else
        calc1();
}

signed main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--)
        solve();

    return 0;
}