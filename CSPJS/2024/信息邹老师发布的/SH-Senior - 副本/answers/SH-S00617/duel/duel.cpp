#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int dp[100010] = {0};
bool vis[100010] = {false};
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	int maxn = -1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		maxn = max(maxn, arr[i]);
	}
	if (maxn <= 2) {
		sort(arr + 1, arr + n + 1);
		int num1, num2;
		for (int i = 1; i < n; i++) {
			if (arr[i] != arr[i + 1]) {
				num1 = i;
				num2 = n - i;
				break;
			}
		}
		cout << max(num1, num2);
		return 0;
	}
	sort(arr + 1, arr + n + 1);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j < i; j++) {
			if (!vis[j] && arr[i] > arr[j]) {
				vis[j] = true;
				dp[i] = dp[i - 1];
				flag = false;
				break;
			}
		}
		if (flag) {
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[n] << endl;
	return 0;
}

