#include <bits/stdc++.h>
using namespace std;
int n, ans, a[100005][5], b[5][50005], c[100005];
bool check_a = 1, check_b = 1;
void dfs(int i, int s) {
	if (i > n) {
		ans = max(ans, s);
		return;
	}
	for (int j = 1; j <= 3; j++) {
		if (b[j][0] < n/2) {
			b[j][0]++;
			b[j][b[j][0]] = a[i][j];
			dfs(i+1, s + a[i][j]);
			b[j][0]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		memset(b, 0, sizeof(b));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
			if (a[i][3] != 0) {
				check_a = 0;
				check_b = 0;
			}
			else if(a[i][2] != 0) check_a = 0;
		}
		ans = 0;
		if (check_a) {
			for (int i = 1; i <= n; i++) {
				c[i] = a[i][1];
			}
			sort(c+1, c+n+1);
			for (int i = n; i > n/2; i--) ans += c[i];
		}
		else dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
