#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= (1 << n); i++) {
        vector<int> a;
        for (int j = 1; j <= n; j++) {
            if (i & (1 << (j-1))) {
                a.push_back(nums[j-1]);
            }
        }
        int mx = 0, sum = 0;
        for (auto x : a) {
            mx = max(x, mx);
            sum += x;
        }
        if (sum > mx*2) {
            ++ans;
            // for (auto x : a) {
            //     cout << x << ' ';
            // }
            // puts("");
            ans %= 998244353;
        }
    }
    printf("%d", ans);
    return 0;
}