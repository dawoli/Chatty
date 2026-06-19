#include<bits/stdc++.h>
using namespace std;
const int MAXN = 11;
const int MAXM = 101;
int n, m, k;
vector<int> costs;
vector<int> weights;
vector<int> days;
int dp[MAXN][MAXM][MAXM * 10];
int main() {
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
    cin >> n >> m >> k;
    costs.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> costs[i];
    }
    weights.resize(n);
    days.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> days[i] >> weights[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int l = 0; l <= MAXM * 10; ++l) {
                if (j >= weights[i-1]) {
                    dp[i][j][l] = min(dp[i][j][l], dp[i-1][j-weights[i-1]][l] + costs[j-weights[i-1] > 0 ? j-weights[i-1] : 1]);
                }
                dp[i][j][l] = min(dp[i][j][l], dp[i-1][j][l] + k * weights[i-1] * (days[i-1] - i + 1));
            }
        }
    }

    int minCost = *min_element(dp[n][m], dp[n][m] + MAXM * 10);
    cout << minCost << endl;
    return 0;
}
