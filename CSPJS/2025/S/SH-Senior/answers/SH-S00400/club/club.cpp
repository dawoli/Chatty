#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 100009, B = 209;
struct stsf {
	int mx, cm;
	bool operator<(stsf i) const {
		return mx - cm > i.mx - i.cm;
	}
};
priority_queue<stsf> p0, p1;
int dp[B][B][B], a[N][3], t, n;
void bf() {
	for (int i = 0; i <= n / 2; i++)
		for (int j = 0; j <= n / 2; j++)
			for (int k = 0; k <= min(n / 2, n - i - j); k++) {
				int p = i + j + k;
				if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[p][0]);
				if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[p][1]);
				if (k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[p][2]);
			}
	int ans = 0;
	for (int i = 0; i <= n / 2; i++)
		for (int j = 0; j <= n / 2; j++) ans = max(ans, dp[i][j][n - i - j]);
	cout << ans << endl;
	for (int i = 0; i <= n / 2; i++)
		for (int j = 0; j <= n / 2; j++)
			for (int k = 0; k <= min(n / 2, n - i - j); k++) dp[i][j][k] = 0;
}
bool spcA() {
	for (int i = 1; i <= n; i++)
		if (a[i][1] || a[i][2]) return 0;
	return 1;
}
void sA() {
	priority_queue<int, vector<int>, greater<int> > ptq;
	for (int i = 1; i <= n; i++) {
		ptq.push(a[i][0]);
		if (ptq.size() > n / 2) ptq.pop();
	}
	int ans = 0;
	while (ptq.size()) {
		ans += ptq.top();
		ptq.pop();
	}
	cout << ans << endl;
}
bool spcB() {
	for (int i = 1; i <= n; i++)
		if (a[i][2]) return 0;
	return 1;
}
void sB() {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (a[i][0] > a[i][1]) {
			p0.push({a[i][0], a[i][1]});
			ans += a[i][0];
			if (p0.size() > n / 2) {
				ans += p0.top().cm - p0.top().mx;
				p0.pop();
			}
		} else {
			p1.push({a[i][1], a[i][0]});
			ans += a[i][1];
			if (p1.size() > n / 2) {
				ans += p1.top().cm - p1.top().mx;
				p1.pop();
			}
		}
	cout << ans << endl;
	while (p0.size()) p0.pop();
	while (p1.size()) p1.pop();
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (n <= 200) bf();
		else if (spcA()) sA();
		else if (spcB()) sB();
		else cout << "wo bu hui" << endl;
	}
	return 0;
}
