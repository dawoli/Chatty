#include <bits/stdc++.h>
typedef unsigned long long ull;

const int NUML = 3500;
const ull MAX = 0xFFFFFFFFFFFFFFFF;

using namespace std;

int use[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

//int dp[100005][NUML];
ull dp[100005];

//void init(int n) {
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j < NUML; j++) {
//			dp[i][j] = -1;
//		}
//	}
//}
//
//bool cmp(int a[], int b[]) {
//	int a_beg = -1, b_beg = -1;
//	
//	while (a[++a_beg] != -1);
//	while (b[++b_beg] != -1);
//	
//	if (a_beg != b_beg) return a_beg < b_beg;
//	else {
//		for (int i = 0; i < a_beg; i++) {
//			if (a[i] < b[i]) return true;
//			if (a[i] > b[i]) return false;
//		}
//	}
//	
//	return false;
//}
//
//void cpy(int from[], int to[], int ex) {
//	int i = 0;
//	for (i = 0; from[i] != -1; i++) {
//		to[i] = from[i];
//	}
//	
//	to[i] = ex;
//}
//
//void print(int a[]) {
//	for (int i = 0; a[i] != -1; i++) {
//		cout << i;
//	}
//	
//	cout << endl;
//}

void solve() {
	int n;
	cin >> n;
	
	if (n == 1) {
		cout << -1 << endl;
		return;
	}
	
	if (n % 7 == 0 && n >= 100) {
		for (int i = 0; i < n / 7; i++) cout << 8;
		cout << endl;
		return;
	}
	
	if ((n - 1) % 7 == 0 && n >= 100) {
		cout << 10;
		for (int i = 0; i < n / 7 - 1; i++) cout << 8;
		cout << endl;
		return;
	}
	
	for (int i = 0; i <= n; i++) dp[i] = MAX;
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 10; k++) {
			if (i < use[k]) continue;
			if (i == 6 && k == 0) continue;
			if (dp[i - use[k]] == MAX) continue;
			dp[i] = min(dp[i], 10 * dp[i - use[k]] + k);
		}
	}
	
//	for (int i = 0; i <= n; i++)
	if (dp[n] != MAX) cout << dp[n] << ' ';
	else cout << -1 << ' ';
	cout << endl;
	
//	init(n);
//	
//	dp[0][0] = 0;
//	dp[6][0] = 6;
//	for (int i = 1; i <= n; i++) {
//		int m = 0;
//		for (int k = 0; k < 10; k++) {
//			//dp[i] = 10 * max(dp[i - use[k]], prev) + k;
//			if (cmp(dp[i - use[k]], dp[i - use[m]])) m = k;
//		}
//		
//		cpy(dp[i - use[m]], dp[i], m);
//		
////		print(dp[i]);
////		cout << "e" << endl;
//	}
//	
////	print(dp[0]);
//
//	if (dp[n][0] != 0 && dp[n][0] != -1)
//		print(dp[n]);
//	else
//		cout << -1 << endl;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		solve();
	}
}
