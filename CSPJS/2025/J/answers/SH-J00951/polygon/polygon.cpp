#include <bits/stdc++.h>
using namespace std;

int n, a[5010], dp[5010];	

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)	
		for (int j = i - 3; j >= 1; j--) {
			dp[i] = dp[j] + a[i];
			
		}
	return 0;
}
