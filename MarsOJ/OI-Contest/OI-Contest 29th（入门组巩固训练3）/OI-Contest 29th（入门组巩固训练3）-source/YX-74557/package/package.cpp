#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e4 + 5, M = 1e6 + 5;
ll n, m, k;
ll v[M], w[N], t[N], dp[N];

int main(){
    freopen("package.in", "r", stdin);
    freopen("package.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> t[i] >> w[i];
        ll wei = w[i], prc = 0;
        dp[i] = dp[i - 1] + v[wei];
        for (int j = i - 1; j; j--){
            wei += w[j];
            prc += k * w[j] * (t[i] - t[j]);
            if (wei > m) break;
            dp[i] = min(dp[i], dp[j - 1] + v[wei] + prc);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}