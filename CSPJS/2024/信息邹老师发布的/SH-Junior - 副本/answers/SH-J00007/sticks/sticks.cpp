#include <bits/stdc++.h>
using namespace std;

int n, t, 
a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, sum[50005], l;

int cnt(int m[50005], int len) {
	int ans = 0;
	for (int i = len - 1; i >= 0; i--) {
		ans += a[m[i]];
	}
	return ans;
}

void print(int m[50005], int len) {
	for (int i = len - 1; i >= 0; i--) {
		printf("%d", m[i]);
	}
	printf("\n");
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int t = pow(10, n / 2) - 1;
		bool flag = false;
		memset(sum, 0, sizeof(sum));
		l = 1;
		for (int j = 0; j < t; j++){
			if (cnt(sum, l) == n) {
				print(sum, l);
				flag = true;
				break;
			}
			sum[0]++;
			for (int k = 0; k < l; k++) {
				if (sum[k] == 10) {
					sum[k + 1]++;
					sum[k] = 0;
				}
				else break;
			}
			if (sum[l]) l++;
		}
		if (!flag) {
			printf("-1\n");
		}
	}
	return 0;
}
