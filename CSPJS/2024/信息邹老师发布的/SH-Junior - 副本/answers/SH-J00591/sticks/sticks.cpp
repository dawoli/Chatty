#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MAXn = 1e5;

ll T, n, ans, dp[200001], beh[200001];

void init () {
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;
	dp[8] = 10;
	dp[9] = 18;
	dp[10] = 22;
	dp[11] = 20;
	dp[12] = 28;
	dp[13] = 68;
	dp[14] = 88;
	dp[17] = 200;
	return;
}

void doit () {
	for (ll i = 15; i <= MAXn; i++) {
		if (i == 17) continue;
		dp[i] = dp[i-7];
		beh[i] = beh[i-7]+1;
	}
	return;
}
int main() {
	freopen ("sticks.in", "r", stdin);
	freopen ("sticks.out", "w", stdout);
	cin >> T;
	memset(dp, 127, sizeof(dp));
	init();
	doit();
	for (ll i = 1; i <= T; i++) {
		cin >> n;
		cout << dp[n];
		for (ll i = 1; i <= beh[n]; i++) {
			cout << 8;
		}
		cout << endl;
	}
	return 0;
}

