#include <bits/stdc++.h>
using namespace std;
int t, n, cnt[4], a[4][100001], ans;
vector <int> dp[100001];
void dfs(int step, int s1, int s2, int s3) {
	if (step > n) {
		ans = max(ans, s1 + s2 + s3);
		return;
	}
	if (cnt[1] * 2 < n) {
		cnt[1]++; 
		dfs(step + 1, s1 + a[1][step], s2, s3);
		cnt[1]--;
	}
	if (cnt[2] * 2 < n) {
		cnt[2]++; 
		dfs(step + 1, s1, s2 + a[2][step], s3);
		cnt[2]--;
	}
	if (cnt[3] * 2 < n) {
		cnt[3]++; 
		dfs(step + 1, s1 + a[3][step], s2, s3);
		cnt[3]--;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int sum = 0;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int m = 0;
			for (int j = 1; j < 4; j++) {
				cin >> a[j][i];
				m = max(m, a[j][i]);
			}
			sum += m;
		}
		dfs(1, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}
