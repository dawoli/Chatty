#include<iostream>
#include<algorithm>
using namespace std;

int t, n, a[100010][3], dd[3], nn[3], ans;

void dfs(int d) {
	if (d > n) {
		ans = max(ans, dd[0] + dd[1] + dd[2]);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (nn[i] < n / 2) {
			dd[i] += a[d][i];
			nn[i]++;
			dfs(d + 1);
			dd[i] -= a[d][i];
			nn[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j][0] >> a[j][1] >> a[j][2];
		}
		dfs(1);
		cout << ans << "\n";
	}
	
	return 0;
} 
