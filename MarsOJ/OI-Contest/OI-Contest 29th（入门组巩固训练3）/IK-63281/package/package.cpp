#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("package.in","r",stdin);
    freopen("package.out","w",stdout);
    int n, max_weight, cost_per_day;
    cin >> n >> max_weight >> cost_per_day;
    vector<int> costs(max_weight + 1, 0);
    for (int i = 1; i <= max_weight; i++) {
        cin >> costs[i];
    }
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    vector<long long> dp(max_weight + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = max_weight; j >= items[i].second; j--) {
            dp[j] = min(dp[j], dp[j - items[i].second] + costs[items[i].second]);
        }
    }

    long long ans = 1e9;
    for (int i = 0; i <= max_weight; i++) {
        ans = min(ans, dp[i] + i * cost_per_day);
    }

    cout << ans << endl;
    return 0;
}