#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int nums[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int t, n;

int dp[10010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;

	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		
		// if (!flag) cout << -1;
		// else cout << ans;

		// cout << "\n";

		
		dp[1] = 1;
		for (int i = 0; i <= 9; i++) {
			for (int j = nums[i]; j <= n; j++) {
				dp[j] = max(dp[j], dp[j - nums[i]]);
			}
		}


		vector<int> a;
		for (int i = 0; i <= 9; i++) {
            a.push_back(i);
		}
        int flag = 0, ans = 1e9;
		while (next_permutation(a.begin(), a.end())) {
            int cur = 0;
            flag = 0;
            int tmp = 0;
            for (int i = 0; i <= 9; i++) {
                cur += nums[a[i]];
                if (cur == n) {
                    if (a[0] == 0) break;
                    for (int j = 0; j <= i; j++) tmp += a[j] * pow(10, j);
                    flag = 1;
     //            	a.clear();
     //            	for (int i = 0; i <= 9; i++) {
     //        			a.push_back(i);
					// }
                    break;
                }
                if (cur > n) break;
            }

            if (flag) {
                ans = min(ans, tmp);
            }
		}

		if (dp[n] == 0) cout << -1;
		else cout << ans;
		cout << "\n";
	}

	return 0;
}
