#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int dp[N][2];
char color[N];

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		
		int a[n+1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		
		int previous = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i-1; j > 0; j--) {
				if (a[i] == a[j]) {
					if (j < previous) {
						dp[i][1] = max(dp[previous][0], dp[previous][1]) + a[i];
					}
					else if (j == previous) {
						continue;
					}
					else {
						dp[i][0] = max(dp[previous][0], dp[previous][1]) + a[i];
						dp[i][0] = max(dp[previous][0], dp[previous][1]) + a[i];
					}
				}
			} 
		}
		
		cout << max(dp[n][0], dp[n][1]) << endl;
	}
	
	return 0;
}
