#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int best[4] = {2, 5, 6, 7};
const ll N = 100001;
ll t, n, ans;
ll dp[N];
vector<int> used;
int findcostmin(int x) {
	for(int f = 1;f <= 9;f++) {
		if(cost[f] == x) {
			return f;
		}
	}
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	dp[1] = -1;
	for(int j = 2;j <= 7;j++) {
		dp[j] = findcostmin(j);
	}
	for(int j = 8;j < N;j++) {
		int k = ceil(j * 1.0 / 7);
		for(int b = 0;b < 4;b++) {
			int last = j - best[b];
			if(ceil(last * 1.0 / 7) < k) {
				dp[j] = findcostmin(best[b]) * pow(10, k-1);
				int plus = dp[last], nplus = 0, i = 1;
				while(plus) {
					int curr = plus % 10;
					if(curr != 6) nplus += curr * i;
					i *= 10;
					plus /= 10;
				}
				dp[j] += nplus;
				break;
			}
		}
	}
	for(int i = 1;i <= t;i++) {
		cin >> n;
		if(n == 1)
			cout << -1 << '\n';
		else if(n <= 7) {
			cout << findcostmin(n) << '\n';
		}
		else cout << dp[n] << '\n';
	}
	return 0;
}
