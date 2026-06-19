# include <bits/stdc++.h>
# include <iostream>
# include <string.h>

using namespace std;

int t, n;
string dp[100005];
int stick[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void dfs(int n) {
	if (dp[n].length() != 0) return;
	if (n == 0) return;
	for (int i = 0; i <= 9; i++) {
		int rest_stick = n - stick[i];
		if (rest_stick < 0 || rest_stick == 1) {
			continue;
		}
		string new_str;
		new_str += ('0' + i);
		dfs(rest_stick);
		new_str = new_str + dp[rest_stick];
		if (dp[n].length() == 0 or (new_str < dp[n] && new_str.length() <= dp[n].length())) {
			dp[n] = new_str;
		}
	}
}

int main() {
	freopen("sticks1.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d\n", &n);
		if (n == 1) {
			printf("-1\n");
		} else if (n == 2) {
			printf("1\n");
		} else {
			dfs(n - 1);
			string res;
			for (int j = 1; j <= 9; j++) {
				int rest_stick = n - stick[j];
				if (rest_stick < 0 || rest_stick == 1) {
					continue;
				}
				string new_str;
				new_str += ('0' + j);
				dfs(rest_stick);
				new_str = new_str + dp[rest_stick];
				if (res.length() == 0 or (new_str < res && new_str.length() <= dp[n].length())) {
					res = new_str;
				}
			}
			for (int j = 0; j < res.length(); j++) printf("%c", res[j]);
			printf("\n");
		}
	}
	return 0;
} 
